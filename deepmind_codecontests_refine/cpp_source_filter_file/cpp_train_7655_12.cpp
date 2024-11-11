#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int fa[N][22], n, ori, depth[N], pw[N];
vector<int> G[N];
pair<int, int> ps;
int query(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  int res = 0;
  int dif = depth[b] - depth[a], bit = 0;
  while (dif) {
    if (dif & 1) res += pw[bit], b = fa[b][bit];
    dif >>= 1, bit++;
  }
  if (a == b) return res;
  for (int i = 0; i < 22; i++) {
    if (fa[a][i] != fa[b][i]) {
      a = fa[a][i];
      b = fa[b][i];
      res += 2 * pw[i];
    }
  }
  res += 2;
  return res;
}
int main() {
  for (int i = 0; i < 25; i++) {
    pw[i] = (1ll << i);
  }
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    G[a].push_back(i + 2);
    fa[i + 2][0] = a;
    depth[i + 2] = depth[a] + 1;
    for (int j = 1; j < 22; j++) {
      fa[i + 2][j] = fa[fa[i + 2][j - 1]][j - 1];
    }
    if (i == 0) {
      ps = make_pair(1, 2);
      ori = 1;
      cout << 1 << " ";
      continue;
    } else {
      int x1 = query(i + 2, ps.first);
      int x2 = query(i + 2, ps.second);
      if (x1 >= x2 && x1 >= ori)
        ori = x1, ps = make_pair(i + 2, ps.first), cout << x1 << " ";
      else if (x2 >= x1 && x2 >= ori)
        ori = x2, ps = make_pair(i + 2, ps.second), cout << x2 << " ";
      else if (ori >= x1 && ori >= x2)
        cout << ori << " ";
    }
  }
  cout << endl;
  return 0;
}
