#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num;
  bool sign = false;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = true;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return sign ? -num : num;
}
int main() {
  long long n = getnum(), ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (getnum())
      cnt++;
    else
      ans += cnt;
  }
  cout << ans;
}
