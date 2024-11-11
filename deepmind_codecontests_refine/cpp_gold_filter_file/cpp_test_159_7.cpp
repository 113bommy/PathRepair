#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 1;
const long long infll = 1e18 + 1;
const int mod = 998244353;
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
struct smth {
  int x;
};
const int maxn = 1e6 + 1;
int p[maxn];
long long h[maxn];
void solve() {
  int n;
  cin >> n;
  vector<long long> f(n + 1);
  f[0] = 0;
  long long s = 0;
  map<long long, int> mp;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] ^ h[i];
    mp[f[i]] = i;
    s ^= f[i];
  }
  if (s == 0) {
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      cout << i << ' ';
    }
    return;
  }
  if (mp.count(s)) {
    cout << n - 1 << '\n';
    for (int j = 1; j <= n; j++) {
      if (mp[s] != j) {
        cout << j << ' ';
      }
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (mp.count(s ^ f[i]) && mp[s ^ f[i]] != i) {
      cout << n - 2 << '\n';
      for (int j = 1; j <= n; j++) {
        if (mp[s ^ f[i]] != j && i != j) {
          cout << j << ' ';
        }
      }
      return;
    }
  }
  cout << n - 3 << '\n';
  for (int i = 1; i <= n; i++) {
    if (i != 2 && i != n && i != (n - 1) / 2) {
      cout << i << ' ';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  t = 1;
  int cnt = 0;
  for (int i = 2; i < maxn; i++) {
    if (p[i] == 0) {
      cnt++;
      for (int j = i; j < maxn; j += i) {
        chmax(p[j], i);
      }
    }
  }
  p[1] = 0;
  set<long long> gen;
  while (gen.size() != cnt) {
    gen.insert(rnd());
  }
  for (int i = 2; i < maxn; i++) {
    if (p[i] == i) {
      h[i] = *gen.begin();
      gen.erase(gen.begin());
    } else {
      h[i] = h[i / p[i]] ^ h[p[i]];
    }
  }
  while (t--) {
    solve();
  }
  return 0;
}
