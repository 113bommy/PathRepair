#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const int MAXN = (int)3e5 + 5;
vector<int> primes[1000005];
int x, p, k;
vector<pair<int, int> > v(1 << 7);
int calc(int a) {
  int cnt = 1;
  int num = 0;
  int tmp = a;
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
  int l = x + 1, r = 6e6 + 5e5 + 3e4 + 4e3 + 0e2 + 2e1 + 8e0;
  while (l < r) {
    int m = (l + r) / 2;
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
  for (int i = 2; i < 1000005; i++) {
    if (!primes[i].size()) {
      for (int j = i; j < 1000005; j += i) {
        primes[j].push_back(i);
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
