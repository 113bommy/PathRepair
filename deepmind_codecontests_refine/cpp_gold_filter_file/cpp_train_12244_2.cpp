#include <bits/stdc++.h>
using namespace std;
int n, k, l = 0, mx = 0;
string s;
int main() {
  cin >> n >> k;
  cin >> s;
  sort(s.begin(), s.end());
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == s[i]) {
      l++;
    } else {
      if ((l + 1) > mx) {
        mx = l + 1;
      }
      l = 0;
    }
  }
  if (mx > k) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
