#include <bits/stdc++.h>
using namespace std;
bool test = 1;
void solve() {
  string s;
  cin >> s;
  int hash[26] = {0};
  for (auto x : s) {
    hash[x - 'a']++;
  }
  long long sum = 0;
  for (int i = 0; i < 26; i++) {
    sum += (hash[i] > 2) ? 2 : hash[i];
  }
  cout << sum / 2 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  if (test) {
    int t;
    cin >> t;
    while (t--) solve();
  } else
    solve();
  return 0;
}
