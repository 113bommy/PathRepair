#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, k, flag, sum, y = 0;
  char m;
  string p, s;
  int prr[150] = {0};
  int srr[150] = {0};
  cin >> t;
  for (i = 0; i < t; i++) {
    for (j = 0; j < 150; j++) {
      prr[j] = 0;
      srr[j] = 0;
    }
    flag = 0;
    cin >> p;
    cin >> s;
    sum = p.length();
    if (sum > s.length()) {
      cout << "NO" << endl;
      continue;
    }
    for (j = 0; j < sum; j++) prr[p[j]]++;
    flag = 0;
    for (j = 0; j <= (s.length() - sum); j++) {
      y = 0;
      flag = 0;
      for (k = j; k < sum + j; k++) srr[s[k]]++;
      for (m = p[y]; y < sum; m = p[++y]) {
        if (prr[m] != srr[m]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        k = 1;
        break;
      } else if (flag == 1) {
        for (k = j; k < sum + j; k++) srr[s[k]]--;
        continue;
      }
    }
    if (flag == 0 && k == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
