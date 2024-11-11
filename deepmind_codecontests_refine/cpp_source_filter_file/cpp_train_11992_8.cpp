#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  int p = 0, q = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 'o') p++;
    if (a[i] == 'n') q++;
    if (a[i] == 'e') r++;
  }
  int l = min(min(p, q), r);
  string ans = "";
  for (int i = 0; i < l; i++) ans += "1";
  int k = (n - (l * 3)) / 4;
  for (int i = 0; i < k; i++) ans += "0";
  cout << ans;
}
