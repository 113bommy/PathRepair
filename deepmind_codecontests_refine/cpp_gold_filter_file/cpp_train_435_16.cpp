#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  string s, c;
  cin >> s >> c;
  int n = s.length();
  vector<int> mn(n);
  mn[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] < s[mn[i + 1]])
      mn[i] = i;
    else
      mn[i] = mn[i + 1];
  }
  if (s < c) {
    cout << s << endl;
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (s[mn[i]] < s[i]) {
      swap(s[mn[i]], s[i]);
      break;
    }
  }
  if (s < c) {
    cout << s << endl;
  } else
    cout << "---" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
