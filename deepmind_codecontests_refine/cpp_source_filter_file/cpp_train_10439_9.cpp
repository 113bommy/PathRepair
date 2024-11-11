#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, a[N];
long long f[N][3], sm[N];
void chkmx(long long &a, long long b) {
  if (a < b) a = b;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i & 1)
      sm[i] = sm[i - 1] + a[i];
    else
      sm[i] = sm[i - 1] - a[i];
  }
  if (n == 1) return cout << a[1], 0;
  memset(f, -0x3f, sizeof(f));
  f[1][1] = -a[1];
  for (int i = 2; i <= n; i++) {
    if (i & 1)
      chkmx(f[i][(i + 1) / 2 % 3], sm[i - 1] - a[i]);
    else
      chkmx(f[i][(i - 1) / 2 % 3], sm[i - 1] + a[i]);
    for (int j = 0; j < 2; j++)
      chkmx(f[i][(j + 1) % 3], f[i - 1][j] - a[i]),
          chkmx(f[i][j], f[i - 1][j] + a[i]);
  }
  cout << f[n][((1 - n) % 3 + 3) % 3];
}
