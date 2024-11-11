#include <bits/stdc++.h>
using namespace std;
long long fast(long long base, long long expo) {
  long long res = 1;
  while (expo > 0) {
    if (expo % 2 == 1) res = (res * base) % 1000000007;
    base = (base * base) % 1000000007;
    expo /= 2;
  }
  return res % 1000000007;
}
vector<pair<long long, pair<long long, long long>>> inp;
vector<long long> v, mtn;
long long s, r;
void dfs(long long &ans, long long i, long long val) {
  val += 1;
  ans = max(ans, val);
  for (long long j = i - 1; j >= 0; j--) {
    if (inp[i].first - inp[j].first >= 2 * (r - 1)) {
      ans = max(ans, mtn[j] + 1);
      break;
    }
    if (inp[i].first - inp[j].first >=
        abs(inp[j].second.first - inp[i].second.first) +
            abs(inp[j].second.second - inp[i].second.second))
      ans = max(ans, v[j] + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, t, x, y;
  cin >> r >> n;
  for (long long i = 0; i < n; i++) {
    cin >> t >> x >> y;
    if (x + y - 2 <= t) inp.push_back({t, {x, y}});
  }
  long long ans = 0, temp = 0;
  s = inp.size();
  mtn.assign(s + 1, 0);
  v.assign(s, 0);
  for (long long i = 0; i < s; i++) {
    temp = 0;
    dfs(temp, i, 0);
    v[i] = temp;
    if (i) mtn[i] = max(mtn[i - 1], v[i]);
    ans = max(ans, temp);
  }
  cout << ans;
  return 0;
}
