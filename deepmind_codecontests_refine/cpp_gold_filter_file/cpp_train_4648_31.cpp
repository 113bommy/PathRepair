#include <bits/stdc++.h>
const int MAX = 1000010;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-6;
const long double PI = acos(-1.0);
using namespace std;
struct query {
  int x, y, ind;
};
void init(vector<int> &func) {
  for (int i = 0; i <= 100; i++) func.push_back(i);
}
vector<vector<int> > seg(4 * 200010, vector<int>());
int p[200010];
void build(int i, int j, int pos) {
  init(seg[pos]);
  if (i == j) {
    p[i] = pos;
    return;
  }
  int mid = (i + j) / 2;
  build(i, mid, 2 * pos);
  build(mid + 1, j, 2 * pos + 1);
}
void merge(vector<int> &a, vector<int> &b, vector<int> &c) {
  for (int i = 1; i <= 100; i++) c[i] = b[a[i]];
}
void update(int ind, int x, int y) {
  seg[ind][x] = y;
  while (ind /= 2) merge(seg[2 * ind], seg[2 * ind + 1], seg[ind]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a[200010], l, r, x, y;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int q;
  cin >> q;
  build(1, q, 1);
  vector<query> sweep[200010];
  for (int i = 0; i < q; i++) {
    cin >> l >> r >> x >> y;
    sweep[l].push_back({x, y, i});
    sweep[r + 1].push_back({x, x, i});
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (auto j : sweep[i]) update(p[j.ind + 1], j.x, j.y);
    vector<int> vet = seg[1];
    ans.push_back(vet[a[i]]);
  }
  assert((int)ans.size() == n);
  for (auto a : ans) cout << a << " ";
  cout << '\n';
  return 0;
}
