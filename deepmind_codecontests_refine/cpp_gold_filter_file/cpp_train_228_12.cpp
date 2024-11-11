#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int a[26] = {0};
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  vector<int> pre(n);
  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    ++pre[p - 1];
  }
  for (int i = n - 1; i > 0; i--) {
    pre[i - 1] += pre[i];
  }
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a'] += pre[i];
  }
  for (int i = 0; i < 26; i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
