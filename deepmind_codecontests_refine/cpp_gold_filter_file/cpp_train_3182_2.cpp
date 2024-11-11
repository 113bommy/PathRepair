#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0, i, j, n;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  string s;
  getline(cin, s);
  bool flag = true;
  for (i = 0; i < n; i++) {
    cnt = 0;
    getline(cin, s);
    for (j = 0; j < s.length(); j++) {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
          s[j] == 'u' || s[j] == 'y')
        cnt++;
    }
    if (cnt != a[i]) flag = false;
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
