#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, a[200009], fl2, fl = 0, i = 0, m, k, sum = 0, ct = 0;
    string s;
    cin >> n >> m >> k >> s;
    sum += k;
    while (i < n) {
      fl2 = 0;
      ct = 0;
      while (i < n && fl == 0 && s[i] == '0') {
        fl2 = 1;
        ct++;
        i++;
      }
      if (fl2 == 1) {
        if (i == n) sum += m + k;
        sum += (ct - 1) * m + (ct - 1) * k;
      }
      ct = 0;
      fl2 = 0;
      while (i < n && s[i] == '1') {
        ct++;
        i++;
        fl2 = 1;
      }
      if (fl2 == 1) {
        if (fl == 0) {
          fl = 1;
          sum += 2 * m + ct * m;
        } else
          sum += m + ct * m;
        sum += 2 * (ct + 1) * k;
      }
      ct = 0;
      fl2 = 0;
      while (i < n && fl == 1 && s[i] == '0') {
        fl2 = 1;
        i++;
        ct++;
      }
      if (fl2 == 1) {
        if (i == n) {
          if (fl == 1)
            sum += 2 * m + (ct - 1) * m;
          else
            sum += m * ct;
          sum += k * ct;
        } else if (2 * k * (ct - 1) + (ct)*m <=
                   max(ct - 2, (long long)0) * m + 4 * m + (ct - 1) * k) {
          sum += 2 * k * (ct - 1) + (ct - 1) * m;
          fl = 1;
        } else {
          sum += max(ct - 2, (long long)0) * m + 2 * m + (ct - 1) * k;
          fl = 0;
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
