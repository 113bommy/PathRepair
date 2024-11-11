#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string str, s;
  int L = 0, R = 1e9;
  int ans = 0;
  cout << ans << " " << 1 << endl;
  cin >> s;
  for (int i = 1; i < n; i++) {
    ans = L + R >> 1;
    cout << ans << " " << 1 << endl;
    cin >> str;
    if (str == s) {
      L = ans;
    } else {
      R = ans;
    }
  }
  cout << L << " " << 2 << " " << R << " " << 0 << endl;
}
