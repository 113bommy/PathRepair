#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5 + 5), INF = int(1e9);
map<int, int> mempos, T;
int h, m, n, res, tree[N], pos[N], s[N], num_tree;
bool was[N];
vector<int> q[N], t[N];
void dfs(int a) {
  was[a] = 1;
  q[num_tree].push_back(a);
  a = (a + m) % h;
  if (!was[a]) dfs(a);
}
void update(int nt, int v, int val) {
  v += s[nt] - 1;
  t[nt][v] = val;
  v /= 2;
  while (v) {
    t[nt][v] = min(t[nt][v * 2], t[nt][v * 2 + 1]);
    v /= 2;
  }
}
int mini(int nt, int L, int R, int l, int r, int v) {
  if (R <= l || r <= L) return INF;
  if (l <= L && R <= r) return t[nt][v];
  int mid = (L + R) / 2;
  return min(mini(nt, L, mid, l, r, v * 2), mini(nt, mid, R, l, r, v * 2 + 1));
}
int main() {
  cin >> h >> m >> n;
  for (int i = 0; i < h; i++) {
    if (!was[i]) {
      dfs(i);
      int l = (q[num_tree]).size();
      for (int j = 0; j < l; j++) {
        tree[q[num_tree][j]] = num_tree;
        pos[q[num_tree][j]] = j + 1;
      }
      int sz = 1;
      while (sz < l) sz *= 2;
      t[num_tree].resize(sz * 2);
      for (int j = 0; j < l; j++) t[num_tree][sz + j] = j + 1;
      for (int j = sz + l; j < sz * 2; j++) t[num_tree][j] = INF;
      for (int j = sz - 1; j > 0; j--)
        t[num_tree][j] = min(t[num_tree][j * 2], t[num_tree][j * 2 + 1]);
      s[num_tree] = sz;
      num_tree++;
    }
  }
  for (int i = 0; i < n; i++) {
    char type;
    cin >> type;
    if (type == '+') {
      int id, hash;
      cin >> id >> hash;
      int nt = tree[hash];
      int p = pos[hash];
      int fr = mini(nt, 1, s[nt] + 1, p, s[nt] + 1, 1);
      if (fr == INF) fr = mini(nt, 1, s[nt] + 1, 1, s[nt] + 1, 1);
      update(nt, fr, INF);
      mempos[id] = fr;
      T[id] = nt;
      if (fr < p) fr += (q[nt]).size();
      res += (fr - p);
    } else {
      int id;
      cin >> id;
      update(T[id], mempos[id], mempos[id]);
    }
  }
  cout << res << endl;
  return 0;
}
