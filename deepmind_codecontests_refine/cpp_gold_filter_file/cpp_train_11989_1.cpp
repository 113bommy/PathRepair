#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans = 0;
  cin >> n;
  long long int a[26] = {0};
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[s[0] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    ans += a[i] / 2 * (a[i] / 2 - 1) / 2 +
           (a[i] - a[i] / 2) * (a[i] - a[i] / 2 - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
