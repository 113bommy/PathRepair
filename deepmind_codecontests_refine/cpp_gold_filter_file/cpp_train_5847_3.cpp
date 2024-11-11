#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
long long int powf(long long int bse, long long int co) {
  long long int mul = 1;
  for (long long int i = 0; i < co; i++) {
    mul *= bse;
  }
  return mul;
}
vector<long long int> fact(1007, 0);
void init_fact() {
  fact[0] = 1;
  for (long long int i = 1; i < 1007; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
}
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
vector<bool> prime(10000077, true);
void init_prime() {
  prime[0] = prime[1] = false;
  for (long long int i = 2; i * i < 10000077; i++) {
    if (prime[i]) {
      for (long long int j = i; i * j < 10000077; j++) {
        prime[i * j] = false;
      }
    }
  }
}
vector<long long int> adj[200007];
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  vector<long long int> v;
  long long int cnt = 0;
  for (char c : s) {
    if (c == '(') {
      cnt++;
      v.push_back(cnt);
    } else {
      v.push_back(cnt);
      cnt--;
    }
  }
  long long int len = v.size(), mx = 0;
  vector<long long int> ans(n);
  for (long long int i = 0; i < len; i++) {
    adj[v[i]].push_back(i);
    mx = max(mx, v[i]);
  }
  cnt = 0;
  for (long long int i = 1; i <= mx; i++) {
    for (auto v : adj[i]) {
      ans[v] = cnt % 2;
    }
    cnt++;
  }
  for (auto x : ans) cout << x;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
