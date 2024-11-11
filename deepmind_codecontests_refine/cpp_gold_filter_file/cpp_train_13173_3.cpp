#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 501;
signed main() {
  long long n, m;
  cin >> n >> m;
  long long cnt = 0, mx = 0;
  for (long long i = 0; i < m; ++i) {
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '1') != s.size())
      cnt++;
    else {
      mx = max(mx, cnt);
      cnt = 0;
    }
  }
  cout << max(mx, cnt);
  return 0;
}
