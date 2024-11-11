#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
using vll = vector<long long>;
using vi = vector<int>;
long long mod = 1000000007;
long long mod2 = 998244353;
long long ipow(long long base, long long k, long long M) {
  base %= M;
  k = k % (M - 1);
  long long total = 1;
  while (k) {
    if (k & 1) {
      total = (total * base) % M;
    }
    base = (base * base) % M;
    k >>= 1;
  }
  return total;
}
long long fact(long long n) {
  long long ans = 1;
  for (long long i = 1; i <= n; i++) {
    ans = ans * i;
    ans = ans % mod;
  }
  return ans;
}
long long modu(long long a, long long b) {
  long long c = a % b;
  return (c < 0) ? c + b : c;
}
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  map<char, long long> cnt;
  vector<char> order;
  for (long long i = n - 1; i >= 0; i--) {
    if (cnt[s[i]] == 0) {
      order.push_back(s[i]);
    }
    cnt[s[i]]++;
  }
  long long ct = order.size();
  map<char, long long> times;
  for (long long i = 0; i < order.size(); i++) {
    if (cnt[order[i]] % ct != 0) {
      cout << -1 << "\n";
      return;
    }
    times[order[i]] = cnt[order[i]] / ct;
    ct--;
  }
  cnt.clear();
  long long good = 0;
  string t = "";
  for (long long i = 0; i < n; i++) {
    cnt[s[i]]++;
    t.push_back(s[i]);
    if (cnt[s[i]] > times[s[i]]) {
      cout << -1 << " nig\n";
      return;
    }
    if (cnt[s[i]] == times[s[i]]) good++;
    if (good == order.size()) break;
  }
  long long ind = t.length();
  map<char, bool> vis;
  for (long long i = order.size() - 1; i >= 0; i--) {
    vis[order[i]] = 1;
    for (long long j = 0; j < t.length(); j++) {
      if (vis[t[j]]) continue;
      if (t[j] != s[ind++]) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  if (ind != s.length()) {
    cout << -1 << "\n";
    return;
  }
  cout << t << " ";
  for (long long i = order.size() - 1; i >= 0; i--) cout << order[i];
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tc = 1;
  cin >> tc;
  long long caseno = 1;
  while (tc--) {
    solve();
    caseno++;
  }
}
