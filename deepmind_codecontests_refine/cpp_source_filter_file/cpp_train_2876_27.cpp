#include <bits/stdc++.h>
int n, m, v[100005];
int Fa[100005], Pre[100005], s[100005];
int Sum[100005], Ans[100005], Pow[100005], Sp[100005];
std::vector<std::pair<int, int> > q[100005];
const int P = 1000000007;
int Get(const int x) { return x == Fa[x] ? x : Fa[x] = Get(Fa[x]); }
void Merge(const int a, const int b) {
  if ((a - Pre[a] > 31 && Sum[b] > 0) ||
      Sum[a] + ((long long)Sum[b] << (a - Pre[a])) > P)
    Sum[b] = P;
  else
    Sum[b] = Sum[a] + (Sum[b] << (a - Pre[a]));
  Fa[a] = Fa[b], Pre[b] = Pre[a];
}
inline int Query(const int a, const int b) {
  return (s[a] - (long long)s[b + 1] * Pow[b - a + 1] % P + P) % P;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = Pow[0] = 1; i <= n; ++i)
    Pre[Fa[i] = i] = i - 1, scanf("%d", &v[i]), Pow[i] = (Pow[i - 1] << 1) % P;
  for (int i = n; i >= 1; --i) s[i] = (((long long)s[i + 1] << 1) + v[i]) % P;
  for (int i = 1, l, r; i <= m; ++i)
    scanf("%d%d", &l, &r), q[r].push_back(std::make_pair(l, i));
  for (int i = 1; i <= n; ++i) {
    for (Sum[i] = v[i]; Pre[i] && Sum[i] >= 0;) Merge(Pre[i], i);
    Sp[i] = (Sp[Pre[i]] + ((long long)Query(Pre[i] + 1, i) << 1)) % P;
    for (auto j : q[i]) {
      int a = j.first, b = Get(a);
      Ans[j.second] = (Sp[i] - Sp[b] + P + (long long)Query(a, b)) % P;
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", Ans[i]);
  return 0;
}
