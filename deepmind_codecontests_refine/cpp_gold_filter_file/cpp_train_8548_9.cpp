#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long num = 0, flag = 1;
  char c = ' ';
  for (; c > '9' || c < '0'; c = getchar())
    if (c == '-') flag = -1;
  for (; c >= '0' && c <= '9';
       num = (num << 1) + (num << 3) + c - 48, c = getchar())
    ;
  return num * flag;
}
long long n, k;
signed main() {
  n = read(), k = read();
  string a, b;
  cin >> a >> b;
  long long nowpoint = 1, ans = 0;
  for (long long i = 0; i < n; i++) {
    nowpoint <<= 1;
    if (a[i] == 'b') nowpoint--;
    if (b[i] == 'a') nowpoint--;
    nowpoint = max(nowpoint, 0ll);
    nowpoint = min(nowpoint, k + 5);
    ans += min(nowpoint, k);
  }
  cout << ans << endl;
  return 0;
}
