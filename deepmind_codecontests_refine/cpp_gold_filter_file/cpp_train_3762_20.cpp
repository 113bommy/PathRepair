#include <bits/stdc++.h>
using namespace std;
int n, a[500000];
int read() {
  int p = 0, q = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch == '-' ? q = -1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') p = p * 10 + ch - '0', ch = getchar();
  return p * q;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n / 2; i++)
    ans += (long long)(a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
  cout << ans << endl;
  return 0;
}
