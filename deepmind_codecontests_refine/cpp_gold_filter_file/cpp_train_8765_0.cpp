#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int M = N + 7;
const int MOD = 1e9 + 7;
const long long INF = 1e16 + 17;
const int SQRT = 200;
int pref[M], pos[M];
unordered_map<int, int> p;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  s = "#" + s;
  int tim = 0;
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1];
    if (s[i] == '1') {
      pos[++tim] = i;
      pref[i]++;
    }
  }
  long long ans = 0;
  for (int k = 1; k <= SQRT; ++k) {
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
      int val = i - k * pref[i];
      ans += p[val];
      p[val]++;
    }
    p.clear();
  }
  int sqr = n / SQRT;
  if (sqr * SQRT == n) sqr--;
  int all = pref[n];
  int sq = min(sqr, all);
  pos[all + 1] = n + 1;
  for (int k = 1; k <= sq; ++k) {
    for (int i = 1; i <= n; ++i) {
      int kth = k + pref[i - 1];
      if (kth > all) break;
      int l = max(i, pos[kth]), r = pos[kth + 1] - 1;
      int lenr = r - i + 1, lenl = l - i;
      ans += max(SQRT, lenr / k) - max(lenl / k, SQRT);
    }
  }
  cout << ans << "\n";
  return 0;
}
