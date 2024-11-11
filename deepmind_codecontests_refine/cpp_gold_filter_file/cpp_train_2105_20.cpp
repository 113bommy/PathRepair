#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int n;
  cin >> n;
  char s[n];
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == 'L')
      l++;
    else
      r++;
  }
  cout << l + 1 + r;
}
