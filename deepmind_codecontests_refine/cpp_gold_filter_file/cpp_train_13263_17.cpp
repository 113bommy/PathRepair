#include <bits/stdc++.h>
using namespace std;
string s;
int n, len, tot, sum;
int f[1100], a[1100];
int main() {
  cin >> s;
  len = s.size();
  for (int i = 0; i < len; i++) {
    if (s[i] != ',')
      tot = tot * 10 + int(s[i] - '0');
    else {
      if (!f[tot]) {
        a[++n] = tot;
        f[tot] = 1;
      }
      tot = 0;
    }
    if (i == len - 1) {
      if (!f[tot]) {
        a[++n] = tot;
        f[tot] = 1;
      }
      tot = 0;
    }
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int total = 0, begin = a[i];
    while (a[i] == begin + total && i <= n) {
      i++;
      total++;
    }
    i--;
    if (total + begin != a[i]) total--;
    if (total == 0) {
      if (!sum)
        cout << a[i];
      else
        cout << ',' << a[i];
    } else {
      if (!sum)
        cout << begin << '-' << begin + total;
      else
        cout << ',' << begin << '-' << begin + total;
    }
    sum++;
  }
  return 0;
}
