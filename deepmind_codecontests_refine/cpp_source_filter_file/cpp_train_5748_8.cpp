#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5;
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
vector<long long> pre(N, 1);
vector<long long> an;
long long pr[N];
vector<long long> prime;
set<long long> set_of_prime;
void seive() {
  for (long long i = 2; i < N; i++) {
    if (!pr[i]) {
      prime.push_back(i);
      set_of_prime.insert(i);
      for (long long j = i * i; j < N; j += i) {
        pr[j] = 1;
      }
    }
    pr[i] ^= 1;
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> temp = a;
  sort((temp).begin(), (temp).end());
  long long q;
  cin >> q;
  while (q--) {
    long long k, pos;
    cin >> k >> pos;
    long long s = a.size();
    map<long long, long long> m;
    for (long long i = s - 1; i >= (s - 1 - k); i--) {
      m[temp[i]]++;
    }
    vector<long long> now;
    for (long long j = 0; j < n; j++) {
      if (m[a[j]]) {
        m[a[j]]--;
        now.push_back(j);
      }
    }
    cout << a[now[pos - 1]] << endl;
  }
}
signed main() {
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
