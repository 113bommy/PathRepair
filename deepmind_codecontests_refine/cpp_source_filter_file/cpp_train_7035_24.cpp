#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n;
string s, p;
long long pos[N];
bool bs(long long ind) {
  set<long long> se;
  for (long long i = 0; i < ind; i++) se.insert(pos[i] - 1);
  long long ptr = 0;
  for (long long i = 0; i < n; i++) {
    if (se.find(i) != se.end()) continue;
    if (s[i] == p[ptr]) ptr++;
    if (ptr == p.length()) return true;
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> s >> p;
  n = s.length();
  for (long long i = 0; i < n; i++) cin >> pos[i];
  long long l = 0, h = n - 1, ans = 0;
  while (l < h) {
    long long mid = l + (h - l) / 2;
    if (bs(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      h = mid - 1;
  }
  cout << ans << "\n";
  return 0;
}
