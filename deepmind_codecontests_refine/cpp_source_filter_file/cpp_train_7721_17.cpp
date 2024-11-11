#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  string s[n];
  vector<long long> marks(m);
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < m; i++) cin >> marks[i];
  vector<long long> fre(5, 0);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < 5; j++) fre[j] = 0;
    for (long long j = 0; j < n; j++) fre[s[j][i] - 'A']++;
    long long mx = 0;
    for (long long j = 0; j < 5; j++)
      if (fre[mx] < fre[i]) mx = i;
    ans += fre[mx] * marks[i];
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
