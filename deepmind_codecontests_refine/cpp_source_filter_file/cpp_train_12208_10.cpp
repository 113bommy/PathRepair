#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
long long a[2000005], b[2000005];
signed main() {
  long long n = read(), sum = 0;
  for (long long i = 1; i <= n; i++) a[i] = read(), sum += a[i];
  long long x = (sum * 2 / n - n + 1) / 2;
  long long y = sum - (2 * x + n - 1) * n / 2;
  for (long long i = 1; i <= y; i++) b[i] = i + x;
  for (long long i = y + 1; i <= n; i++) b[i] = i + x - 1;
  for (long long i = 1; i <= n; i++) printf("%d ", b[i]);
  cout << "\n";
  return 0;
}
