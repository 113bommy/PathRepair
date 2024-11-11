#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const int N = 1e5 + 2;
int n, q, S[N], F[N], H[N], R[N], t;
vector<pair<int, int> > G[N], Q[N];
int SEG[N << 2][2], LAZY[N << 2];
void Apply(int x, int id, int s, int e) {
  LAZY[id] = (LAZY[id] + x % MOD + MOD) % MOD;
  SEG[id][1] = (SEG[id][1] + 1LL * x * x % MOD * (e - s) % MOD +
                2LL * x * SEG[id][0] % MOD + MOD) %
               MOD;
  SEG[id][0] = (SEG[id][0] + 1LL * (e - s) * x % MOD + MOD) % MOD;
}
void Shift(int id, int s, int e) {
  if (LAZY[id] == 0) return;
  Apply(LAZY[id], id << 1, s, (s + e) >> 1);
  Apply(LAZY[id], id << 1 ^ 1, (s + e) >> 1, e);
  LAZY[id] = 0;
}
void Update(int l, int r, int x, int id = 1, int s = 0, int e = t) {
  if (l >= e || s >= r) return;
  if (l <= s && e <= r) return Apply(x, id, s, e);
  Shift(id, s, e);
  Update(l, r, x, id << 1, s, (s + e) >> 1),
      Update(l, r, x, id << 1 ^ 1, (s + e) >> 1, e);
  SEG[id][0] = (SEG[id << 1][0] + SEG[id << 1 ^ 1][0]) % MOD,
  SEG[id][1] = (SEG[id << 1][1] + SEG[id << 1 ^ 1][1]) % MOD;
}
int Get(int l, int r, int id = 1, int s = 0, int e = t) {
  if (l >= e || s >= r) return 0;
  if (l <= s && e <= r) return SEG[id][1];
  Shift(id, s, e);
  return (Get(l, r, id << 1, s, (s + e) >> 1) +
          Get(l, r, id << 1 ^ 1, (s + e) >> 1, e)) %
         MOD;
}
void DFST(int v, int p = 0) {
  S[v] = t++;
  for (auto [u, w] : G[v])
    if (u != p) H[u] = (H[v] + w) % MOD, DFST(u, v);
  F[v] = t;
}
void DFSQ(int v, int p = 0) {
  for (auto [u, i] : Q[v])
    R[i] = (2LL * Get(S[u], F[u]) - SEG[1][1] + MOD) % MOD;
  for (auto [u, w] : G[v])
    if (u != p) {
      Update(0, t, +w), Update(S[u], F[u], -2 * w);
      DFSQ(u, v);
      Update(0, t, -w), Update(S[u], F[u], +2 * w);
    }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  mt19937 Rnd(time(0));
  cin >> n;
  for (int i = 1; i < n; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    G[v].push_back(make_pair(u, w));
    G[u].push_back(make_pair(v, w));
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v, u;
    cin >> v >> u;
    Q[v].push_back(make_pair(u, i));
  }
  DFST(1);
  for (int i = 1; i <= n; i++) Update(S[i], S[i] + 1, H[i]);
  DFSQ(1);
  for (int i = 0; i < q; i++) cout << R[i] << '\n';
  return 0;
}
