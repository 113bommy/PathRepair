#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, M;
  cin >> n >> M;
  vector<char> s(n);
  int m = M;
  vector<int> p(m), b(n), yes(n, 0), cnt(26, 0);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  sort(p.begin(), p.end());
  int top = 0;
  for (int i = 0; i < n; i++) {
    if (top >= m) break;
    if (p[top] != i)
      cnt[s[i] - 'a'] += m;
    else {
      int t = top;
      while (top < M - 1 && p[top] == p[top + 1]) top++;
      int c = ++top - t;
      cnt[s[i] - 'a'] += m;
      m -= c;
    }
  }
  for (int i = 0; i < 26; i++) cout << cnt[i] << " ";
  cout << endl;
  return;
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
  return 0;
}
