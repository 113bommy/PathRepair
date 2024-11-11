#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
string s;
int a[11];
string ans[] = {"1869", "6198", "1896", "1689", "9168", "6189", "1698"};
int main() {
  cin >> s;
  int i;
  for (i = 0; i < s.length(); i++) {
    a[int(s[i]) - 48]++;
  }
  a[1]--;
  a[6]--;
  a[8]--;
  a[9]--;
  int rem = 0;
  for (i = 1; i <= 9; i++) {
    while (a[i] > 0) {
      cout << i;
      rem = rem * 10 + i;
      rem = rem % 7;
      a[i]--;
    }
  }
  cout << ans[rem];
  while (a[0] > 0) {
    cout << 0;
    a[0]--;
  }
  return 0;
}
