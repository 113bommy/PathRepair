#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i) {
    if (i != v.begin()) os << ", ";
    os << *i;
  }
  os << "]";
  return os;
}
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;
inline void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int main() {
  vector<int> D(MAXN + 1, -1);
  vector<int> Phi(MAXN + 1);
  Phi[1] = 1;
  for (int i = (int)(2); i <= (int)(MAXN); ++i)
    if (D[i] == -1) {
      Phi[i] = i - 1;
      for (int j = 2 * i; j <= MAXN; j += i) D[j] = i;
    } else {
      int j = i, k = 1;
      while (j % D[i] == 0) {
        j /= D[i];
        k *= D[i];
      }
      if (j == 1) {
        Phi[i] = i - i / D[i];
      } else {
        Phi[i] = Phi[j] * Phi[k];
      }
    }
  vector<int> F(MAXN + 1, 0);
  for (int g = (int)(1); g <= (int)(MAXN); ++g)
    for (int i = g; i <= MAXN; i += g)
      add(F[i], (long long)g * Phi[i / g] % MOD);
  vector<int> A0(MAXN + 1, 0), A1(MAXN + 1, 0), A2(MAXN + 1, 0);
  for (int i = (int)(1); i <= (int)(MAXN); ++i) {
    int a = ((2ll * i * i - 6 * i + 1) * i / 3 + 2 * F[i]) % MOD;
    A0[i] = (A0[i - 1] + a) % MOD;
    A1[i] = (A1[i - 1] + (long long)i * a) % MOD;
    A2[i] = (A2[i - 1] + (long long)i * i % MOD * a) % MOD;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int m, n;
    scanf("%d%d", &m, &n);
    int p = min(m, n);
    int res = ((((long long)m * n % MOD + m + n + 1) * A0[p] -
                ((long long)m + n + 2) * A1[p] + A2[p]) %
                   MOD +
               MOD) %
              MOD;
    printf("%d\n", res);
  }
}
