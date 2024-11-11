#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
bool isSubSequence(string a, string b) {
  int m = a.size();
  int n = b.size();
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (a[j] == b[i]) j++;
  }
  return (j == m);
}
void r(string s, string t) {
  int ans = 0;
  int max_len = s.size() - t.size();
  for (int l = 1; l <= max_len; l++) {
    for (int j = 0; j < s.size() - l; j++) {
      string p = s;
      p.erase(j, l);
      if (isSubSequence(t, p)) {
        ans = max(ans, l);
      }
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  r(s, t);
  return 0;
}
