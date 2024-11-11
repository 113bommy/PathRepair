#include <bits/stdc++.h>
long long gcd(long long x, long long y) {
  return y % x == 0 ? x : gcd(y % x, x);
}
template <class T>
T my_abs(T a) {
  if (a < 0) a = -a;
  return a;
}
inline long long read() {
  long long ret = 0, sign = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') sign = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret * sign;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 - '0');
}
using namespace std;
int x, m, n;
int main() {
  cin >> m >> n;
  int y = 1;
  int ans;
  std::vector<int> p;
  for (int i = (int)(1); i <= (int)(n); i++) {
    cout << y << endl;
    cin >> ans;
    if (ans == 0) return 0;
    if (ans == 1)
      p.emplace_back(1);
    else
      p.emplace_back(0);
  }
  int l = 1, r = m, mid;
  int cnt = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    cout << mid << endl;
    cin >> ans;
    if (p[cnt] == 0) ans = -ans;
    cnt = (cnt + 1) % n;
    if (ans == 0) break;
    if (ans < 0)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return 0;
}
