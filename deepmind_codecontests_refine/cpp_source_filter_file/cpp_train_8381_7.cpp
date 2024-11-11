#include <bits/stdc++.h>
using namespace std;
int ans, k;
string s;
int main() {
  cin >> s;
  for (k = 0; k < s.size(); k++) {
    if (((int)s[k] - 48) % 4 == 0) ans++;
    if (k >= 1) {
      if ((((int)s[k - 1] - 48) * 10 + (int)s[k] - 48) % 4 == 0) ans += k;
    }
  }
  cout << ans;
}
