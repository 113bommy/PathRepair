#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, ans = 0, a[200] = {0};
  string s;
  cin >> n >> s;
  for (i = 0; i < s.length(); i++) {
    a[s[i]]++;
    if (s[i] >= 65 && s[i] <= 90) {
      if ((a[s[i] + 32]) == 0) {
        ans++;
      } else
        (a[s[i] + 32])--;
    }
  }
  cout << ans << endl;
  return 0;
}
