#include <bits/stdc++.h>
using namespace std;
long long base, now, n, ans;
string s;
long long num(int x, int y) {
  long long now = 1, ret = 0;
  for (int i = y; i >= x; i--) {
    ret += now * (s[i] - '0');
    now *= 10;
  }
  return ret;
}
int main() {
  cin >> base;
  long long test = base;
  int m = 0;
  while (test) {
    m++;
    test /= 10;
  }
  now = 1;
  cin >> s;
  n = s.length();
  s = 'a' + s;
  for (int i = n; i >= 1; i--) {
    int j = max(1, i - m + 1);
    if (num(j, i) > base) j++;
    while (j < i && s[j] == '0') j++;
    ans += num(j, i) * now;
    now *= base;
    i = j;
  }
  cout << ans << endl;
  return 0;
}
