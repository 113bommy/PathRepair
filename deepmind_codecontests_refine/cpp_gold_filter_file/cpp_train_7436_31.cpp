#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, ans;
  cin >> n >> k;
  ans = n / 2;
  string s;
  cin >> s;
  if (ans < k) {
    for (int i = k; i < n; i++) {
      cout << "RIGHT" << endl;
    }
    for (int j = n - 1; j >= 0; j--) {
      cout << "PRINT " << s[j] << endl;
      if (j != 0) cout << "LEFT" << endl;
    }
  } else {
    for (int i = k - 1; i > 0; i--) {
      cout << "LEFT" << endl;
    }
    for (int j = 0; j < n; j++) {
      cout << "PRINT " << s[j] << endl;
      if (j != n - 1) cout << "RIGHT" << endl;
    }
  }
  return 0;
}
