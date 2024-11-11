#include <bits/stdc++.h>
const int maxn = 1001;
int a[maxn];
int n;
int foo() {
  int s = 0;
  int p1, p2, i, dp;
  if (a[1] == 1) {
    for (i = 1; i < n; i++)
      if (a[i] == a[i + 1]) break;
    if (i == n) return 0;
    s = i;
    p1 = i + a[i];
  } else {
    s = 0;
    p1 = 0;
  }
  p2 = p1 + 1;
  while (p2 <= n) {
    while (p2 <= n && a[p2] != 1) p2++;
    if (p2 > n) {
      s += (p2 - p1 - 1) / 2;
      break;
    }
    dp = p2 - p1;
    if (dp % 2 == 1) {
      s += (dp + 1) / 2;
      p1 = p2 - 1;
    } else {
      s += dp / 2 - 1;
      p1 = p2;
    }
    p2++;
  }
  return s;
}
int main() {
  using std::cin;
  using std::cout;
  cin >> n;
  int i, s1, s2;
  for (i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == '0')
      a[i] = 0;
    else
      a[i] = 1;
  }
  s1 = foo();
  for (i = 1; i <= n; i++) a[i] = 1 - a[i];
  s2 = foo();
  if (s1 < s2)
    cout << s1;
  else
    cout << s2;
  cout << '\n';
  return 0;
}
