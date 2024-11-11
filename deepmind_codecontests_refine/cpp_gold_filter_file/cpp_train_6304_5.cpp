#include <bits/stdc++.h>
using namespace std;
char a[200100];
long long n, t, i;
int main() {
  cin >> n >> t;
  a[0] = '0';
  cin >> (a + 1);
  bool postComma = false;
  bool found = false;
  for (i = 1; i <= n; i++) {
    if (a[i] == '.') postComma = true;
    if (postComma && a[i] >= '5' && a[i] <= '9') {
      found = true;
      break;
    }
  }
  if (!found) {
    cout << a + 1;
    return 0;
  }
  i--;
  t--;
  while (a[i] == '4' && t) {
    i--;
    t--;
  }
  long long imp = i;
  a[imp + 1] = 0;
  while (true) {
    if ('0' <= a[i] && a[i] <= '8') {
      a[i]++;
      break;
    }
    if (a[i] == '9') a[i] = '0';
    i--;
  }
  for (long long i = imp; i > 0; i--)
    if (a[i] == '0')
      a[i] = 0;
    else {
      if (a[i] == '.') a[i] = 0;
      break;
    }
  cout << (a[0] == '0' ? a + 1 : a);
  return 0;
}
