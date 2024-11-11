#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int add(int a, int b) { return a + b < mod ? a + b : a + b - mod; }
int mul(int a, int b) { return int(1LL * a * b % mod); }
int fexp(int b, int e = mod - 2) {
  int ans = 1;
  while (e) {
    if (e & 1) ans = mul(ans, b);
    b = mul(b, b);
    e /= 2;
  }
  return ans;
}
const int N = 1005;
int n, m;
int mat[N][N];
int r, c;
int inv[N];
int solve() {
  map<int, vector<int>> occ;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (mat[i][j] > mat[r][c]) continue;
      if (mat[i][j] == mat[r][c]) {
        if (i != r or j != c) continue;
      }
      occ[mat[i][j]].push_back(i);
    }
  int s0 = 0, s1 = 0, s2 = 0, dp = 0;
  int ans = 0;
  while (!occ.empty()) {
    vector<int> vec = occ.begin()->second;
    occ.erase(occ.begin());
    vector<int> to_upp;
    for (int id : vec) {
      int tmp = 0;
      tmp = add(tmp, s2);
      tmp = add(tmp, mod - mul(2 * id, s1));
      tmp = add(tmp, mul(mul(id, id), s0));
      tmp = add(tmp, dp);
      tmp = mul(tmp, inv[s0]);
      to_upp.push_back(tmp);
    }
    for (int i = 0; i < (int)vec.size(); i++) {
      ans = to_upp[i];
      s0 = add(s0, 1);
      s1 = add(s1, vec[i]);
      s2 = add(s2, mul(vec[i], vec[i]));
      dp = add(dp, to_upp[i]);
    }
  }
  return ans;
}
int main() {
  for (int i = 1; i < N; i++) inv[i] = fexp(i);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &mat[i][j]);
  scanf("%d %d", &r, &c);
  int ans = 0;
  ans = add(ans, solve());
  for (int i = 1; i <= max(n, m); i++)
    for (int j = i + 1; j <= max(n, m); j++) {
      swap(mat[i][j], mat[j][i]);
    }
  swap(n, m);
  swap(r, c);
  ans = add(ans, solve());
  printf("%d\n", ans);
}
