#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int inf = INT_MAX;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if ((i - 1 >= 0 && s[i - 1] == '1') || (i + 1 < n && s[i + 1] == '1')) {
        cout << "No";
        return 0;
      }
    }
  }
  for (int i = 2; i < n; i++) {
    if (s[i] == '0' && s[i - 1] == '0' && s[i - 2] == '0') {
      cout << "No";
      return 0;
    }
  }
  if ((n > 2 && s[0] == '0' && s[1] == '0') ||
      (n > 2 && s[n - 1] == '0' && s[n - 2] == '0') ||
      (n == 2 && s[0] == '0' && s[1] == '0') || (n == 1 && s[0] == '0')) {
    cout << "No";
    return 0;
  }
  cout << "Yes";
  return 0;
}
