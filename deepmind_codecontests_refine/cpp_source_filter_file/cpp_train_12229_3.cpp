#include <bits/stdc++.h>
using namespace std;
bool o1;
long long n, m, P, a[505], b[3], f[505][505];
char s[505];
bool o2;
int main() {
  cin >> n >> m >> P;
  for (long long i = 1; i <= m; i++) {
    scanf("%s", s + 1);
    for (long long j = 1; j <= n; j++)
      if (s[j] == '1') a[j]++;
  }
  for (long long i = 1; i <= n; i++) b[a[i]]++;
  f[b[1]][b[0]] = 1;
  for (long long i = n; i >= 0; i--) {
    for (long long j = n; j >= 0; j--) {
      if (j && i) (f[i][j - 1] += f[i][j] * j % P * i % P) %= P;
      if (i - 2 >= 0) (f[i - 2][j] += i * (i - 1) / 2 % P * f[i][j] % P) %= P;
      if (j - 2 >= 0)
        (f[i + 2][j - 2] += j * (j - 1) / 2 % P * f[i][j] % P) %= P;
    }
  }
  cout << f[0][0];
  return 0;
}
