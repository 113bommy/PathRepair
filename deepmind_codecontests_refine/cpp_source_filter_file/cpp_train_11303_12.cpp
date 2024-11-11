#include <bits/stdc++.h>
using namespace std;
long long int a[15];
int main() {
  long long int n, m, i, j, k, f, t, oldnum, num, temp, tot, mult, cnt, zcnt,
      numcnt;
  string s;
  cin >> n >> s;
  m = s.length();
  a[0] = 1;
  for (i = 1; i < 10; i++) a[i] = a[i - 1] * 10;
  i = m - 1;
  num = n;
  zcnt = 0;
  while (num > 0) {
    zcnt++;
    num /= 10;
  }
  oldnum = num = 0;
  j = 0;
  f = 0;
  tot = 0;
  mult = 1;
  cnt = 0;
  t = 0;
  while (i >= 0) {
    if (s[i] == '0') {
      if (1) {
        cnt++;
        j++;
        if (j >= zcnt) {
          t = 1;
          oldnum = num;
          numcnt = 0;
          while (num > 0) {
            numcnt++;
            num /= 10;
          }
          j -= max(numcnt, 1LL);
          tot += oldnum * mult;
          mult *= n;
          num = 0;
          oldnum = 0;
          cnt--;
          f = 0;
        }
      }
      i--;
      continue;
    } else {
      temp = a[j] * (s[i] - '0');
      t = 0;
      if (num + temp >= n) {
        oldnum = num;
        num = (s[i] - '0') * a[cnt];
        j = cnt + 1;
        cnt = 0;
        f = 1;
      } else {
        num += temp;
        j++;
        cnt = 0;
        f = 0;
      }
    }
    if (f == 1) {
      tot += oldnum * mult;
      mult *= n;
      if (num == n) {
        num /= 10;
        j--;
      }
      f = 0;
    }
    i--;
  }
  oldnum = num;
  tot += oldnum * mult;
  cout << tot << endl;
  return 0;
}
