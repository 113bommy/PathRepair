#include <bits/stdc++.h>
using namespace std;
long long int n, m;
const int mx = 101;
long long int par[mx], size[mx], freq[mx];
void initialize() {
  for (long long int i = 1; i <= n; i++) {
    par[i] = i;
    size[i] = 1;
  }
}
long long int find_par(long long int a) {
  if (par[a] == a) return a;
  return find_par(par[a]);
}
void union_set(long long int a, long long int b) {
  a = find_par(a);
  b = find_par(b);
  if (a == b) return;
  if (size[a] < size[b]) swap(a, b);
  par[b] = a;
  size[a] += size[b];
}
void solve() {
  long long int t, k, z, p, q, u, v, x, y, ct = 0, flag = 0;
  cin >> n >> m;
  cin >> t;
  unordered_map<long long int, long long int> boy;
  unordered_map<long long int, long long int> girl;
  while (t--) {
    cin >> x;
    boy[x] = 1;
  }
  cin >> t;
  while (t--) {
    cin >> x;
    girl[x] = 1;
  }
  ct = 0;
  long long int boySize = boy.size();
  long long int girlSize = girl.size();
  while (true) {
    x = ct % n;
    y = ct % m;
    if (boy.find(x) != boy.end()) {
      girl[y] = 1;
    }
    if (girl.find(y) != girl.end()) {
      boy[x] = 1;
    }
    if (boy.size() == n && girl.size() == m) {
      cout << "Yes\n";
      break;
    }
    boySize = boy.size();
    girlSize = girl.size();
    ct++;
    if (ct > m * n + 2) {
      cout << "No\n";
      break;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  solve();
}
