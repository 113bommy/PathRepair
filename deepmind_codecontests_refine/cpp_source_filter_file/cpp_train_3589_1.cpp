#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(register T& t) {
  register T f = 1;
  register char ch = getchar();
  t = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  t *= f;
  return t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const long long p = 998244353;
inline long long power(register long long x, register long long k = p - 2) {
  register long long re = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) re = re * x % p;
  return re;
}
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) return x = 1, y = 0, a;
  long long gc = exgcd(b, a % b, y, x);
  return y -= a / b * x, gc;
}
long long n, m, X, Y, gc;
vector<int> B, G;
vector<int> Bs[200005], Gs[200005];
struct per {
  long long s, beg;
  bool IsG;
};
bool cmp(per a, per b) { return a.s < b.s; }
long long solve(long long x, vector<int>& b, vector<int>& g) {
  if (g.size() >= m) return -1;
  if (b.size() == 0 && g.size() == 0) printf("-1\n"), exit(0);
  map<long long, bool> mp;
  static per S[200005];
  int S_top = 0;
  for (auto i : g) {
    if (mp.count(i)) continue;
    S_top++;
    S[S_top].s = x * i % m;
    S[S_top].IsG = 1;
    S[S_top].beg = i;
    mp[i] = 1;
  }
  for (auto i : b) {
    if (mp.count(i % m)) continue;
    S_top++;
    S[S_top].s = x * i % m;
    S[S_top].IsG = 0;
    S[S_top].beg = i;
    mp[i % m] = 1;
  }
  sort(S + 1, S + S_top + 1, cmp);
  S[S_top + 1] = S[1];
  long long dis = 0, ans = 0;
  for (int i = 1; i <= S_top; i++) {
    dis = min(dis + n * (S[i].s - S[i - 1].s), S[i].beg);
    if (S[i].IsG && S[i].s + 1 == S[i + 1].s) continue;
    ans = max(ans, dis + n * ((S[i + 1].s - 1 - S[i].s + m) % m));
  }
  return ans;
}
int main() {
  read(n, m);
  gc = exgcd(n, m, X, Y);
  X = (X % m + m) % m;
  Y = (Y % n + n) % n;
  int b, g;
  read(b);
  for (int i = 1, x; i <= b; i++) read(x), B.push_back(x);
  read(g);
  for (int i = 1, x; i <= g; i++) read(x), G.push_back(x);
  sort(B.begin(), B.end());
  sort(G.begin(), G.end());
  if (gc > b + g) return printf("-1\n"), 0;
  for (auto i : B) Bs[i % gc].push_back(i / gc);
  for (auto i : G) Gs[i % gc].push_back(i / gc);
  long long ans = 0;
  n / gc;
  m /= gc;
  for (int i = 0; i < gc; i++) {
    ans = max(ans, solve(X, Bs[i], Gs[i]) * gc + i);
    swap(n, m);
    ans = max(ans, solve(Y, Gs[i], Bs[i]) * gc + i);
    swap(n, m);
  }
  printf("%lld\n", ans);
  return 0;
}
