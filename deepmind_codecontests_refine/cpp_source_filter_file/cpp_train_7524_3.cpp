#include <bits/stdc++.h>
using namespace std;
string s, s1;
int a[300], b[300];
bool check() {
  for (int i = 'a'; i <= 'z'; i++) {
    if (a[i] > b[i]) return 0;
  }
  return 1;
}
int main() {
  cin >> s >> s1;
  int n = s.size(), m = s1.size();
  if (m > n) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    a[s[i]]++;
    b[s1[i]]++;
  }
  int ans = check();
  for (int i = m; i < n; i++) {
    a[s[i]]++;
    a[s[i - m]]--;
    ans += check();
  }
  cout << ans + 1 << endl;
  return 0;
}
