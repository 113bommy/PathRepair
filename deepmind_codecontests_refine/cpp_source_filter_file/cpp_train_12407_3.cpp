#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cc = 0;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> b[i] >> a[i];
  }
  int m = 0;
  for (int i = 0; i <= 10000; i++) {
    cc = 0;
    for (int j = 0; j < n; j++) {
      if (i - a[j] >= 0) {
        if (((i - a[j]) / b[j]) % 2 == 0) {
          if (s[j] == '1') cc++;
        } else {
          if (s[j] == '1')
            ;
          else
            cc++;
        }
      } else {
        if (s[j] == '1') cc++;
      }
    }
    m = max(cc, m);
  }
  cout << m << "\n";
  return 0;
}
