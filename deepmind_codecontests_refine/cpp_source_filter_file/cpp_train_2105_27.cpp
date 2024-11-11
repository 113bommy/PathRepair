#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string str;
  cin >> str;
  long long int l = 0, r = 0;
  for (long long int i = 0; i < n; i++) {
    if (str[i] == 'L')
      l++;
    else
      r++;
    cout << l + r + 1;
  }
}
int main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
