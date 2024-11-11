#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  int n, k, d[30];
  memset(d, 0, sizeof(d));
  cin >> s;
  cin >> k;
  n = s.size();
  if (k > n)
    cout << "impossible";
  else {
    for (int i = 0; i < n; ++i) ++d[s[i] - 'a'];
    for (int i = 0; i <= 'z' - 'a'; ++i) k -= min(1, d[i]);
    cout << k;
  }
  return 0;
}
