#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m, ans = 1;
set<char> cnt[105];
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      cnt[j].insert(s[j]);
    }
  }
  for (int j = 0; j < m; j++) ans = (ans * cnt[j].size()) % mod;
  cout << ans;
  return 0;
}
