#include <bits/stdc++.h>
using namespace std;
int main() {
  bool b = false;
  long long n, d, ans = 0;
  string s;
  cin >> n >> d >> s;
  for (int i = 0; i < s.size() - 1; i++) {
    b = false;
    for (int j = d; j > 0; j--) {
      if (s[i + j] == '1') {
        b = true;
        i += j;
        break;
      }
    }
    if (b == false) {
      cout << -1;
      return 0;
    }
    ans++;
  }
  cout << ans;
}
