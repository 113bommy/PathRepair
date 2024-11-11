#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const int maxn = 3e5 + 5;
const int maaxn = 1e7 + 2;
const int minn = 22;
const long long mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279;
long long binpow(long long a, long long p) {
  if (p == 0) return 0;
  if (p % 2 == 1) return (a + binpow(a, p - 1)) % mod;
  long long b = binpow(a, p / 2);
  return (b + b) % mod;
}
int a[maxn];
map<int, vector<int>> dv;
bool sh(int &c, int &b) { return a[c] < a[b]; }
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int j = 2;
    while (a[i] >= j * j) {
      if (a[i] % j == 0) {
        dv[j].push_back(i);
        while (a[i] % j == 0) a[i] /= j;
      }
      j++;
    }
  }
  int p = 2;
  for (auto x : dv) {
    if (dv[p].size() < x.second.size()) p = x.first;
  }
  if (dv[p].size() >= k) {
    for (int i = 0; i < k; i++) {
      cout << dv[p][i] + 1 << " ";
    }
  } else {
    set<int> d;
    for (int i = 0; i < n; i++) d.insert(i);
    for (int i = 0; i < dv[p].size(); i++) d.erase(dv[p][i]);
    vector<int> answ;
    for (auto x : d) answ.push_back(x);
    sort(answ.begin(), answ.end(), sh);
    for (int i = 0; i < k; i++) cout << answ[i] + 1 << " ";
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  cin >> t;
  return 0;
}
