#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> mp;
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    mp[s[i]]++;
  }
  ans = mp['n'];
  for (int i = 0; i < ans; i++) {
    cout << "1 ";
  }
  ans = n - ans * 3;
  ans /= 3;
  for (int i = 0; i < ans; i++) {
    cout << "0 ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  while (tc--) solve();
  return 0;
}
