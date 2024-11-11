#include <bits/stdc++.h>
using namespace std;
const long long mo = 1000000009;
long long n, a, b, k, now, ans, s[100010];
char c;
long long read() {
  long long tot = 0, fh = 1;
  char c = getchar();
  while ((c - '0' < 0) || (c - '0' > 9)) {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while ((c - '0' >= 0) && (c - '0' <= 9)) {
    tot = tot * 10 + c - '0';
    c = getchar();
  }
  return tot * fh;
}
int Pow(int x, int y) {
  long long tot = 1, tmp = x;
  while (y) {
    if ((y & 1) == 1) tot = tot * tmp % mo;
    tmp = tmp * tmp % mo;
    y = y >> 1;
  }
  return tot;
}
int main() {
  n = read();
  a = read();
  b = read();
  k = read();
  c = getchar();
  while (c != '-' && c != '+') c = getchar();
  for (int i = 1; i <= k; i++) {
    if (c == '+')
      s[i] = 1;
    else
      s[i] = -1;
    c = getchar();
  }
  while (k + k <= n + 1 && k <= 10000) {
    for (int i = k + 1; i <= k + k; i++) s[i] = s[i - k];
    k = k + k;
  }
  for (int i = 1; i <= (n + 1) / k; i++) {
    int tmp = (i - 1) * k;
    long long x = Pow(a, n - tmp), y = Pow(b, tmp);
    now = (now + x * y % mo) % mo;
  }
  ans = (ans + now * s[1] + mo) % mo;
  for (int i = 2; i <= k; i++) {
    long long x = Pow(a, mo - 2), y = b;
    now = now * x % mo * y % mo;
    ans = (ans + now * s[i] + mo) % mo;
  }
  for (int i = (n + 1) / k * k; i <= n; i++) {
    long long x = Pow(a, n - i), y = Pow(b, i);
    now = x * y % mo;
    int tmp = (i + 1) % k;
    if (tmp == 0) tmp = k;
    ans = (ans + now * s[tmp] + mo) % mo;
  }
  cout << ans << endl;
  return 0;
}
