#include <bits/stdc++.h>
using namespace std;
char s[200010];
int a = 0, b;
int main() {
  int n, t;
  cin >> n >> t;
  bool end = 0;
  getchar();
  for (int i = 1; i <= n; i++) {
    s[i] = getchar();
    if (s[i] == '.') a = i;
    if (a && s[i] >= '5' && s[i] <= '9') {
      b = i;
      break;
    }
  }
  for (int i = b; i > a; i--) {
    if (!t) break;
    if (s[i] >= '5') {
      if (s[i - 1] != '.')
        s[i - 1]++, n = i - 1;
      else
        s[i - 2]++, n = i - 2;
      t--;
    }
  }
  bool ok = 0;
  for (int i = a - 1; i >= 1; i--)
    if (s[i] == '0' + 10) {
      if (i >= 2)
        s[i] -= 10, s[i - 1]++;
      else
        ok = 1, s[i] -= 10;
    }
  if (ok) putchar('1');
  for (int i = 1; i <= n; i++) putchar(s[i]);
  cout << endl;
  return 0;
}
