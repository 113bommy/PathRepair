#include <bits/stdc++.h>
using namespace std;
bool check(int base, string s, int limit) {
  int val, res = 0;
  for (typeof(0) i = (0); i < (((int)(s).size())); ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z')
      val = s[i] - 'A' + 10;
    else
      val = s[i] - '0';
    res = res * base + val;
  }
  return res <= limit;
}
int main() {
  string s, min, sec;
  while (cin >> s) {
    int x = s.find(':');
    min = s.substr(0, x);
    sec = s.substr(x + 1);
    int i = 0;
    while (min[i] == '0') ++i;
    min = min.substr(i);
    i = 0;
    while (sec[i] == '0') ++i;
    sec = sec.substr(i);
    int base, ma = 0, val, ma2 = 0;
    if (((int)(min).size()) <= 1 && ((int)(sec).size()) <= 1) {
      bool ok = true;
      for (typeof(0) i = (0); i < (((int)(min).size())); ++i)
        if (min[i] - 'A' > 13) {
          puts("0");
          ok = false;
        }
      if (ok) puts("-1");
      continue;
    }
    ma = *max_element((min).begin(), (min).end());
    if (ma >= '0' && ma <= '9')
      ma -= '0';
    else if (ma >= 'A' && ma <= 'Z')
      ma = ma - 'A' + 10;
    ma2 = *max_element((sec).begin(), (sec).end());
    if (ma2 >= '0' && ma2 <= '9')
      ma2 -= '0';
    else if (ma2 >= 'A' && ma2 <= 'Z')
      ma2 = ma2 - 'A' + 10;
    base = max(ma, ma2) + 1;
    if (!check(base, min, 23) || !check(base, sec, 59)) {
      puts("0");
      continue;
    } else {
      for (int b = base; b < 60; ++b) {
        if (check(b, min, 23) && check(b, sec, 59))
          printf("%d ", b);
        else
          break;
      }
      printf("\n");
    }
  }
  return 0;
}
