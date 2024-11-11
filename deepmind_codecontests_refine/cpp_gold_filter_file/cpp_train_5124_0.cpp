#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  int mx = 0;
  int i = 0;
  while (i < n) {
    if (s[i] == 'A') {
      while (i < n && s[i] == 'A') i++;
      int cnt = 0;
      while (i < n && s[i] == 'P') {
        ++cnt;
        i++;
      }
      mx = max(cnt, mx);
    } else
      i++;
  }
  cout << mx << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
