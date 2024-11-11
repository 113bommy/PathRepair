#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const ll mod = 1e9 + 7;
ll n, K, dp[26];
string s;
bool in[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> K >> s;
  ll sum = 1;
  for (ll i = (0); i <= (((ll)(s).size()) - 1); ++i) {
    ll lst = dp[s[i] - 'a'];
    dp[s[i] - 'a'] = sum;
    (sum += (sum - lst + mod) % mod) %= mod;
  }
  deque<int> dq;
  for (ll i = (((ll)(s).size()) - 1); i >= (0); --i)
    if (!in[s[i] - 'a']) {
      in[s[i] - 'a'] = 1;
      dq.push_front(s[i] - 'a');
    }
  for (ll i = (0); i <= (25); ++i)
    if (!in[i]) dq.push_front(i);
  for (ll i = (1); i <= (n); ++i) {
    int id = dq.front();
    dq.pop_front();
    dq.push_back(id);
    int lst = dp[id];
    dp[id] = sum;
    (sum += (sum - lst + mod) % mod) %= mod;
  }
  cout << sum;
  return 0;
}
