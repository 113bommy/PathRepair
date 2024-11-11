#include <bits/stdc++.h>
using namespace std;
bool ok[100][100];
struct pp {
  int x[55][55];
} a, b, T, L;
long long n;
int m, k;
char u, v;
pp mm(pp a, pp b) {
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) {
      long long k = 0;
      for (int t = 1; t <= m; t++) {
        k += 1LL * a.x[i][t] * b.x[t][j];
        if (k >= 1000000007LL) k %= 1000000007LL;
      }
      L.x[i][j] = k;
    }
  return L;
}
pp cal(long long n) {
  if (n == 1) return a;
  T = cal(n / 2);
  if (n % 2 == 0) return mm(T, T);
  return mm(T, mm(T, a));
}
int cc(char a) {
  if (a >= 'a')
    return a - 'a' + 1;
  else
    return a - 'A' + 1 + 26;
}
int main() {
  scanf("%I64d%d%d\n", &n, &m, &k);
  if (n == 1) {
    cout << m;
    return 0;
  }
  memset(ok, true, sizeof(ok));
  for (int i = 1; i <= k; i++)
    scanf("%c%c\n", &u, &v), ok[cc(u)][cc(v)] = false;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) a.x[i][j] = ok[i][j];
  b = cal(n - 1);
  long long res = 0;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) res = (res + b.x[i][j]) % 1000000007LL;
  cout << res;
  return 0;
}
