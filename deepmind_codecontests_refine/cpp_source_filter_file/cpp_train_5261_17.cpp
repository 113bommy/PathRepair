#include <bits/stdc++.h>
using namespace std;
map<int, int> M;
;
vector<pair<pair<int, int>, int> > vec;
int ans[200007];
int tree[200007];
const int N = 200006;
void update(int i, int val) {
  while (i <= N) {
    tree[i] += val;
    i += i & (-i);
  }
}
int query(int i) {
  int sum = 0;
  while (i > 0) {
    sum += tree[i];
    i -= i & (-i);
  }
  return sum;
}
void func(int n) {
  int c = 0;
  map<int, int>::iterator j;
  for (j = M.begin(); j != M.end(); j++) M[j->first] = ++c;
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++)
    vec[i].first = make_pair(M[vec[i].first.first], M[vec[i].first.second]);
  for (int i = 0; i < vec.size(); i++) update(vec[i].first.second, 1);
  for (int i = 0; i < vec.size(); i++) {
    ans[vec[i].second] = query(vec[i].first.second);
    update(vec[i].first.second, -1);
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i] - 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    M[u];
    M[v];
    vec.push_back(make_pair(make_pair(u, v), i));
  }
  func(n);
  return 0;
}
