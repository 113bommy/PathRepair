#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using graph = vector<vector<int>>;
using pii = pair<int, int>;
using vpii = vector<pii>;
void solve() {
  int n;
  cin >> n;
  string s;
  int a[26];
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    s += temp;
  }
  for (int i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (a[i] % n != 0) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
