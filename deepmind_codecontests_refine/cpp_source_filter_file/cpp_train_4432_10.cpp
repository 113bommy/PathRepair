#include <bits/stdc++.h>
using namespace std;
void func(void) {
  freopen("input.c", "r", stdin);
  freopen("output.c", "w", stdout);
}
string c = "fedabc";
int main() {
  unsigned long long n, q, i, j = 0, temp, t, k, ans = 0, sum = 0, cnt = 0, m,
                              fg = 0, x, y, mx = 0, mx1 = 0,
                              mn = 10000000000000000, mn1 = 10000000000000000;
  char a;
  cin >> n >> a;
  ans = n / 4;
  if (n % 4 == 0) ans--;
  ans *= 16;
  if (n % 2 == 0) ans += 1;
  for (i = 0; i < c.size(); i++) {
    if (c[i] == a) {
      ans += i + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
