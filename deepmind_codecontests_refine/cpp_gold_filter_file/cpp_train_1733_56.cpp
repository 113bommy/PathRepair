#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const int MAXN = (int)3e5 + 5;
vector<long long> primes[1000005];
bool vis[1000005];
long long x, p, k;
vector<pair<int, int> > v(1 << 7);
long long calc(long long a) {
  int cnt = 1;
  int num = 0;
  long long tmp = a;
  a = 0;
  for (int i = 1; i < (1 << primes[p].size()); i++) {
    if (cnt * 2 == i) {
      cnt *= 2;
      num++;
    }
    v[i] = {v[i - cnt].first * primes[p][num], v[i - cnt].second + 1};
    if (v[i].second % 2) {
      a += tmp / v[i].first;
    } else {
      a -= tmp / v[i].first;
    }
  }
  return tmp - a;
}
void solve() {
  cin >> x >> p >> k;
  k += calc(x);
  long long l = x + 1, r = 1e7;
  while (l < r) {
    long long m = (l + r) / 2;
    if (calc(m) >= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (long long i = 2; i < 1000005; i++) {
    if (!vis[i]) {
      for (long long j = i; j < 1000005; j += i) {
        primes[j].push_back(i);
        vis[j] = 1;
      }
    }
  }
  v[0] = {1, 0};
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
