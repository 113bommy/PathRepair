#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int N, X[100010], V[100010], P[100010], Q[100010];
struct mat {
  int p[2][2];
  mat operator*(mat a) {
    mat res;
    for (int i = 0; i < (2); i++)
      for (int j = 0; j < (2); j++) res.p[i][j] = 0;
    for (int i = 0; i < (2); i++)
      for (int k = 0; k < (2); k++)
        for (int j = 0; j < (2); j++)
          res.p[i][j] = (res.p[i][j] + (long long)p[i][k] * a.p[k][j]) % mod;
    return res;
  }
  void init() {
    for (int a = 0; a < (2); a++)
      for (int b = 0; b < (2); b++) p[a][b] = (a == b ? 1 : 0);
  }
};
mat T[1 << 18], MV[100010];
const int ADD = 1 << 17;
void upd(int a) {
  T[ADD + a] = MV[a];
  for (int t = (ADD + a) / 2; t; t >>= 1) T[t] = T[t * 2 + 1] * T[t * 2];
}
mat read(int l, int r) {
  l += ADD, r += ADD;
  mat rl, rr;
  rl.init();
  rr.init();
  while (l <= r) {
    if (l & 1) rl = T[l++] * rl;
    if (!(r & 1)) rr = rr * T[r--];
    l >>= 1, r >>= 1;
  }
  return rr * rl;
}
pair<int, int> apply(mat M, pair<int, int> a) {
  pair<int, int> res = pair<int, int>(0, 0);
  res.first =
      ((long long)M.p[0][0] * a.first + (long long)M.p[0][1] * a.second) % mod;
  res.second =
      ((long long)M.p[1][0] * a.first + (long long)M.p[1][1] * a.second) % mod;
  return res;
}
int pw(int x, int y = mod - 2) {
  int res = 1;
  while (y) {
    if (y & 1) res = (long long)res * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return res;
}
struct event {
  pair<int, int> tm;
  int i, ri, rj;
  bool operator<(const event &rhs) const {
    return (long long)tm.first * rhs.tm.second <
           (long long)tm.second * rhs.tm.first;
  }
};
vector<event> E;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d%d", X + i, V + i, P + i);
    P[i] = (long long)P[i] * pw(100) % mod;
    Q[i] = (mod + 1 - P[i]) % mod;
  }
  for (int i = 1; i < N; i++) {
    MV[i].p[0][0] = MV[i].p[0][1] = P[i + 1];
    MV[i].p[1][0] = MV[i].p[1][1] = Q[i + 1];
  }
  for (int i = 1; i < N; i++) T[ADD + i] = MV[i];
  for (int i = ADD - 1; i; i--) T[i] = T[i * 2 + 1] * T[i * 2];
  for (int i = 1; i < N; i++) {
    int len = X[i + 1] - X[i];
    if (V[i] > V[i + 1])
      E.push_back({pair<int, int>(len, V[i] - V[i + 1]), i, 0, 0});
    E.push_back({pair<int, int>(len, V[i] + V[i + 1]), i, 0, 1});
    if (V[i] < V[i + 1])
      E.push_back({pair<int, int>(len, V[i + 1] - V[i]), i, 1, 1});
  }
  sort((E).begin(), (E).end());
  int ans = 0;
  for (auto ele : E) {
    int ntm = ele.tm.first * (long long)pw(ele.tm.second) % mod;
    int x = ele.i;
    int l_p, r_p;
    mat m = read(1, x - 1);
    pair<int, int> mv = apply(m, pair<int, int>(P[1], Q[1]));
    l_p = (ele.ri == 0 ? mv.first : mv.second);
    m = read(x + 1, N - 1);
    pair<int, int> temp = pair<int, int>(P[x + 1], Q[x + 1]);
    if (ele.rj == 0)
      temp.second = 0;
    else
      temp.first = 0;
    mv = apply(m, temp);
    r_p = (mv.first + mv.second) % mod;
    ans = (ans + (long long)ntm * l_p % mod * (long long)r_p) % mod;
    MV[x].p[ele.rj][ele.ri] = 0;
    upd(x);
  }
  printf("%d\n", ans);
  return 0;
}
