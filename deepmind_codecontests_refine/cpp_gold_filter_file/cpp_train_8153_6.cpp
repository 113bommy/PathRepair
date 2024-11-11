#include <bits/stdc++.h>
using namespace std;
int n;
int tree[100005 * 2];
vector<int> pos[100005];
vector<pair<int, int> > Ans;
void build() {
  for (int i = n - 1; i > 0; --i) tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
}
int query(int l, int r) {
  int res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, tree[l++]);
    if (r & 1) res = min(res, tree[--r]);
  }
  return res;
}
void solve(int l, int r, int Minus) {
  if (l > r) return;
  int Min = query(l, r + 1);
  for (int i = 1; i <= Min - Minus; i++) Ans.push_back(make_pair(l, r));
  int idx = lower_bound(pos[Min].begin(), pos[Min].end(), l) - pos[Min].begin();
  vector<int> v;
  v.push_back(l - 1);
  while (idx < pos[Min].size() && pos[Min][idx] <= r)
    v.push_back(pos[Min][idx++]);
  v.push_back(r + 1);
  for (int i = 1; i < v.size(); i++) solve(v[i - 1] + 1, v[i] - 1, Min);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &tree[n + i]);
    pos[tree[n + i]].push_back(i);
  }
  build();
  solve(0, n - 1, 0);
  cout << Ans.size() << endl;
  for (auto v : Ans) printf("%d %d\n", v.first + 1, v.second + 1);
}
