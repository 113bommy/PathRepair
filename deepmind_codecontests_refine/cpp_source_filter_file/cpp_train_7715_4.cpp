#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int fx, fy;
int n = read();
char s[200010];
int cheque(int mid) {
  int x = 0, y = 0;
  for (int i = n; i > mid; i--) {
    if (s[i] == 'U') ++y;
    if (s[i] == 'D') --y;
    if (s[i] == 'R') ++x;
    if (s[i] == 'L') --x;
  }
  for (int i = 1; i + mid - 1 <= n; i++) {
    if (mid - abs(fx - x) - abs(fy - y) >= 0 &&
        (mid - abs(fx - x) - abs(fy - y)) % 2 == 0)
      return 1;
    if (s[i] == 'U') ++y;
    if (s[i] == 'D') --y;
    if (s[i] == 'R') ++x;
    if (s[i] == 'L') --x;
    if (s[mid + i] == 'U') --y;
    if (s[mid + i] == 'D') ++y;
    if (s[mid + i] == 'R') --x;
    if (s[mid + i] == 'L') ++x;
  }
  if (mid - abs(fx - x) - abs(fy - y) >= 0 &&
      (mid - abs(fx - x) - abs(fy - y)) % 2 == 0)
    return 1;
  return 0;
}
int main() {
  scanf("%s", s + 1);
  fx = read();
  fy = read();
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U') ++y;
    if (s[i] == 'D') --y;
    if (s[i] == 'R') ++x;
    if (s[i] == 'L') --x;
  }
  if (x == fx && y == fy) {
    cout << 0 << endl;
    return 0;
  }
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (cheque(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans << endl;
}
