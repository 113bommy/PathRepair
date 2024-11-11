#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  int n;
  string x, s;
  cin >> n >> x >> s;
  int k = s.size();
  int ans;
  if (s[k - 1] == 'k') {
    if (n == 5 || n == 6) {
      ans = 53;
    } else
      ans = 52;
  } else {
    if (n >= 1 && n <= 29)
      ans = 12;
    else if (n == 30)
      ans = 11;
    else if (n == 31)
      ans = 7;
  }
  cout << ans;
  return 0;
}
