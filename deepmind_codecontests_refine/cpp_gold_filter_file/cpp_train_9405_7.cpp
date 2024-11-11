#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a, c, d, r;
  char ch;
  long long int n, i, flag = 0, k, j, f, sum, u, p;
  cin >> n;
  for (i = 1; i <= n; i++) {
    sum = 0;
    u = 1;
    flag = 0;
    cin >> a;
    k = a.size();
    for (j = 0; j < k; j++) {
      if (a[j] >= 'A' && a[j] <= 'Z' && flag == 0) {
        flag = 1;
      } else if (flag == 1 && a[j] >= '0' && a[j] <= '9') {
        flag = 2;
      } else if (flag == 2 && a[j] >= 'A' && a[j] <= 'Z') {
        flag = 3;
      }
    }
    if (flag == 3) {
      for (j = 1; j < k; j++) {
        if (a[j] != 'C') {
          c = c + a[j];
        } else {
          j++;
          break;
        }
      }
      for (; j < k; j++) {
        d = d + a[j];
      }
      f = d.size();
      for (j = 0; j < f; j++) {
        sum = (sum * 10) + (d[j] - 48);
      }
      while (sum != 0) {
        p = sum % 26;
        if (p == 0) {
          r = "Z" + r;
          sum /= 26;
          sum--;
        } else {
          ch = p + 'A' - 1;
          r = ch + r;
          sum /= 26;
        }
      }
      cout << r << c << "\n";
      r.clear();
    } else {
      for (j = 0; j < k; j++) {
        if (a[j] >= 'A' && a[j] <= 'Z') {
          c = c + a[j];
        } else {
          break;
        }
      }
      for (; j < k; j++) {
        d = d + a[j];
      }
      f = c.size();
      for (j = f - 1; j >= 0; j--) {
        sum += (a[j] - 'A' + 1) * u;
        u *= 26;
      }
      cout << "R" << d << "C" << sum << "\n";
    }
    c.clear();
    d.clear();
  }
}
