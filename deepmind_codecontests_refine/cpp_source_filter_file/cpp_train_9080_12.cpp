#include <bits/stdc++.h>
using namespace std;
const int mod = 998353244;
int add(int& a, int b) { return a = (a + b) % mod; }
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string s, t;
  cin >> s >> t;
  const int n = s.size(), m = t.size();
  vector<int> cur(n + 1, 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    char c = s[i - 1];
    vector<int> nxt(n + 1);
    for (int j = 0; i + j <= n; j++)
      if (j >= m || t[j] == c) add(nxt[j], cur[j + 1]);
    for (int j = 0; i + j <= n; j++)
      if (i + j - 1 >= m || t[i + j - 1] == c) add(nxt[j], cur[j]);
    swap(cur, nxt);
    if (i >= m) add(ans, cur[0]);
  }
  cout << ans << '\n';
}
