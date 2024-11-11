#include <bits/stdc++.h>
#pragma GCC optimize(2)
const int maxn = 2e6 + 5, mod = 1e9 + 7, line = 2e6;
const int base = 17, M = 998244353;
struct matrix {
  static const int maxn = 5, S = 4;
  int data[maxn][maxn];
  void clear() { memset(data, 0, sizeof(data)); }
  matrix() { clear(); }
  int *operator[](const int &id) { return data[id]; }
  matrix operator*(matrix Alpha) {
    matrix answer;
    for (int i = 1; i <= S; i++) {
      for (int j = 1; j <= S; j++) {
        for (int k = 1; k <= S; k++) {
          answer[i][j] += 1ll * data[i][k] * Alpha[k][j] % mod;
          answer[i][j] %= mod;
        }
      }
    }
    return answer;
  }
};
long long k;
int m;
matrix Rin, Pepper;
int prefix[maxn], ksm[maxn];
std::string Alpha, Beta, Gamma, Zeta;
inline int El_Psy_Congroo(int l, int r) {
  return (prefix[r] - (l ? 1ll * ksm[r - l + 1] * prefix[l - 1] % M : 0) + M) %
         M;
}
matrix fastpow(matrix &g, long long x) {
  if (x <= 0) {
    puts("El Psy Congroo");
    std::exit(0);
  }
  if (x == 1) return g;
  matrix tmp = fastpow(g, x >> 1);
  return x & 1 ? tmp * tmp * g : tmp * tmp;
}
int main() {
  scanf("%lld%d", &k, &m);
  ksm[0] = 1;
  for (int i = 1; i <= line; i++) ksm[i] = 1ll * ksm[i - 1] * base % M;
  Pepper[1][1] = Pepper[1][2] = Pepper[2][1] = Pepper[3][1] = Pepper[3][4] =
      Pepper[4][3] = 1;
  for (int _ = 1; _ <= m; _++) {
    std::cin >> Gamma;
    int gamma = 0;
    for (unsigned int i = 0; i < Gamma.size(); i++)
      gamma = (1ll * gamma * base % M + Gamma[i] - 'a') % M;
    if (k == 1) {
      if (Gamma == "a")
        printf("1\n");
      else
        printf("0\n");
      continue;
    }
    Alpha = "a", Beta = "b";
    int Okabe = 0, Rintaro = 0, Mad = 0, Scientist = 0;
    int length = 0;
    for (length = 2; Beta.size() <= Gamma.size() * 4 && length < k; length++) {
      Zeta = Beta + Alpha;
      Alpha = Beta;
      Beta = Zeta;
    }
    prefix[0] = Beta[0] - 'a';
    for (unsigned int i = 1; i < Beta.size(); i++)
      prefix[i] = (1ll * prefix[i - 1] * base % M + Beta[i] - 'a') % M;
    for (unsigned int i = 0; i + Gamma.size() <= Beta.size(); i++)
      if (El_Psy_Congroo(i, i + Gamma.size() - 1) == gamma) Okabe++;
    if (k <= length) {
      printf("%d\n", Okabe);
      continue;
    }
    for (unsigned int i = Alpha.size() - Gamma.size() + 1; i < Alpha.size();
         i++)
      if (i >= 0 && i + Gamma.size() - 1 < Beta.size() &&
          El_Psy_Congroo(i, i + Gamma.size() - 1) == gamma)
        Mad++;
    Zeta = Beta + Alpha;
    Alpha = Beta;
    Beta = Zeta;
    prefix[0] = Beta[0] - 'a';
    for (unsigned int i = 1; i < Beta.size(); i++)
      prefix[i] = (1ll * prefix[i - 1] * base % M + Beta[i] - 'a') % M;
    for (unsigned int i = 0; i + Gamma.size() <= Beta.size(); i++)
      if (El_Psy_Congroo(i, i + Gamma.size() - 1) == gamma) Rintaro++;
    if (k == length + 1) {
      printf("%d\n", Rintaro);
      continue;
    }
    for (unsigned int i = Alpha.size() - Gamma.size() + 1; i < Alpha.size();
         i++)
      if (i >= 0 && i + Gamma.size() - 1 < Beta.size() &&
          El_Psy_Congroo(i, i + Gamma.size() - 1) == gamma)
        Scientist++;
    Rin.clear();
    Rin[1][1] = Rintaro, Rin[1][2] = Okabe, Rin[1][3] = Mad,
    Rin[1][4] = Scientist;
    Rin = Rin * fastpow(Pepper, k - length - 1);
    printf("%d\n", (Rin[1][1] + mod) % mod);
  }
  return 0;
}
