#include <bits/stdc++.h>
using namespace std;
int cnt[30];
void ff() {
  for (long long i = 0; i <= 29; i++) cnt[i] = 0;
}
int main() {
  int n, m;
  string str[109];
  int f[109][109];
  for (long long i = 0; i <= 108; i++)
    for (long long j = 0; j <= 108; j++) f[i][j] = 1;
  cin >> n >> m;
  for (long long i = 0; i <= n - 1; i++) cin >> str[i];
  ff();
  for (long long i = 0; i <= n - 1; i++) {
    ff();
    for (long long j = 0; j <= m - 1; j++) {
      cnt[int(str[i][j]) - int('a')]++;
    }
    for (long long j = 0; j <= m - 1; j++) {
      if (cnt[int(str[i][j]) - int('a')] > 1) f[i][j] = 0;
    }
  }
  for (long long i = 0; i <= m - 1; i++) {
    ff();
    for (long long j = 0; j <= n - 1; j++) {
      cnt[int(str[j][i]) - int('a')]++;
    }
    for (long long j = 0; j <= m - 1; j++) {
      if (cnt[int(str[j][i]) - int('a')] > 1) f[j][i] = 0;
    }
  }
  for (long long i = 0; i <= n - 1; i++)
    for (long long j = 0; j <= m - 1; j++)
      if (f[i][j]) cout << str[i][j];
}
