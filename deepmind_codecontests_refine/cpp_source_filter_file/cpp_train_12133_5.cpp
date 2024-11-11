#include <bits/stdc++.h>
using namespace std;
long long n, i, a[1010], m, j;
string s;
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long fabs(long long a) {
  if (a >= 0)
    return a;
  else
    return -a;
}
int main() {
  cin >> n;
  cin >> s;
  m = n - 1;
  a[1] = 1;
  for (i = 1; i <= m; i++) {
    if (s[i - 1] == '=') a[i + 1] = a[i];
    if (s[i - 1] == 'R') a[i + 1] = a[i] + 1;
    if (s[i - 1] == 'L') {
      if (a[i] != 1)
        a[i + 1] = a[i] - 1;
      else {
        a[i + 1] = 1;
        j = i;
        while (j > 0) {
          if ((s[j - 1] == 'L') && (a[j + 1] >= a[j]))
            a[j] = a[j + 1] + 1;
          else if ((s[j - 1] == '=') && (a[j] != a[j + 1]))
            a[j] = a[j + 1];
          else
            j = -1;
          j--;
        }
      }
    }
  }
  for (i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
