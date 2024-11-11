#include <bits/stdc++.h>
using namespace std;
int read() {
  int k = 0;
  char c = getchar();
  for (; c < '0' || c > '9';) c = getchar();
  for (; c >= '0' && c <= '9'; c = getchar()) k = (k << 3) + (k << 1) + c - 48;
  return k;
}
long long a[100010 << 1], ans;
int main() {
  int n = read();
  for (int i = 1; i <= n << 1; i++) a[i] = read();
  sort(a + 1, a + (n << 1) + 1);
  ans = (a[n] - a[1]) * (a[n << 1] - a[n + 1]);
  for (int i = 2; i <= n + 1; i++)
    ans = min((a[n << 1] - a[1]) * (a[i + n - 1] - a[i]), ans);
  cout << ans;
  return 0;
}
