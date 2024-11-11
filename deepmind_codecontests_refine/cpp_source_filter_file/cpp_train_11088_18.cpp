#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s = "";
long long arr[1000005] = {0};
long long solve(string st) {
  long long sz = st.size();
  long long t = 1;
  long long x = st[0] - '0';
  for (int i = 1; i < sz; i++) {
    if (st[i] == 1 - x + '0') {
      t++;
      x = 1 - x;
    }
  }
  return t;
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n;
  cin >> s;
  int sz = s.size();
  if (sz == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (sz == 2) {
    cout << 2 << endl;
    return 0;
  }
  long long ans = 0;
  long long t = 0;
  ans = solve(s);
  for (int i = 1; i < int(s.size() - 1); i++) {
    if (s[i - 1] == '0' && s[i] == '0' && s[i + 1] == '0') {
      cout << ans + 2 << endl;
      return 0;
    }
    if (s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '1') {
      cout << ans + 2 << endl;
      return 0;
    }
  }
  int x = 0;
  for (int i = 3; i < sz; i++) {
    if (s[i - 3] == '0' && s[i - 2] == '0' && s[i - 1] == '1' && s[i] == '1') {
      cout << ans + 2 << endl;
      return 0;
    }
    if (s[i - 3] == '1' && s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '0') {
      cout << ans + 2 << endl;
      return 0;
    }
    if ((s[i - 3] == '1' && s[i - 2] == '0' && s[i - 1] == '0' &&
         s[i] == '1') ||
        (s[i - 3] == '0' && s[i - 2] == '1' && s[i - 1] == '1' &&
         s[i] == '0')) {
      x++;
      if (x == 2) {
        cout << ans + 2 << endl;
        return 0;
      }
    }
  }
  if (((s[0] == '0' && s[1] == '0') || (s[0] == '1' && s[1] == '1')) &&
      ((s[sz - 2] == '0' && s[sz - 1] == '0') ||
       (s[sz - 2] == '1' && s[sz - 1] == '1'))) {
    cout << ans + 2 << endl;
    return 0;
  }
  if ((s[0] == '0' && s[1] == '0') || (s[0] == '1' && s[1] == '1') ||
      (s[sz - 2] == '0' && s[sz - 1] == '0') ||
      (s[sz - 2] == '1' && s[sz - 1] == '1')) {
    cout << ans + 1 + x << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
