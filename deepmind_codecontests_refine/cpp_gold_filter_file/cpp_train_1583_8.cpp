#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
inline void solve(), read();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
string s, ans;
long long n;
vector<long long> prime;
multiset<char> used;
inline void solve() {
  vector<long long> cnt(26, 0);
  for (long long i = 0; i < n; i++) {
    ++cnt[s[i] - 'a'];
  }
  auto it = max_element((cnt).begin(), (cnt).end());
  char u = it - cnt.begin() + 'a';
  long long v = *it;
  for (long long i = 0; i < n; i++) {
    if (s[i] != u) {
      used.insert(s[i]);
    }
  }
  prime.assign(n + 1, 1);
  ans.assign(n, -1);
  for (long long i = 1; i <= n; i++) {
    if (i == 1 || prime[i] && i > n / 2) {
      if (!used.empty()) {
        ans[i - 1] = *used.begin();
        used.erase(used.begin());
      } else {
        ans[i - 1] = u;
        --v;
        if (v < 0) {
          cout << "NO"
               << "\n";
          return;
        }
      }
      continue;
    }
    for (long long j = 2 * i; j <= n; j += i) {
      prime[j] = 0;
    }
    ans[i - 1] = u;
    --v;
    if (v < 0) {
      cout << "NO"
           << "\n";
      return;
    }
  }
  cout << "YES"
       << "\n";
  cout << ans << "\n";
}
inline void read() {
  cin >> s;
  n = (long long)((s).size());
}
