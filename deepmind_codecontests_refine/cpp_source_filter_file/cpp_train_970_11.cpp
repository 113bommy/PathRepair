#include <bits/stdc++.h>
using namespace std;
using vvll = vector<vector<long long int> >;
using vll = vector<long long int>;
const long long int inf = 1e18;
const long long int maxs = 200200;
const long long int mod = 1e9 + 7;
long long int getPow(long long int num, long long int pow) {
  long long int res = 1;
  num %= mod;
  while (pow) {
    if (pow & 1) res = (res * num) % mod;
    num = (num * num) % mod;
    pow >>= 1;
  }
  return res;
}
long long int INV(long long int num) {
  num %= mod;
  return getPow(num, mod - 2);
}
int connected;
int root[2005], sz[2005], isValid[2005];
int n;
void init() {
  for (int i = 1; i <= n; i++) {
    root[i] = i;
    sz[i] = 1;
  }
  connected = n;
}
int rt(int k) {
  while (k != root[k]) {
    root[k] = root[root[k]];
    k = root[k];
  }
  return k;
}
void merge(int u, int v) {
  int rt1 = rt(u);
  int rt2 = rt(v);
  if (rt1 == rt2) return;
  connected--;
  if (sz[rt1] > sz[rt2]) swap(rt1, rt2);
  sz[rt2] += sz[rt1];
  sz[rt1] = 0;
  root[rt1] = root[rt2];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  init();
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (root[a] == root[b]) isValid[root[a]] = 1;
  }
  int ans = INT_MIN;
  for (int i = 1; i <= n; i++)
    if (isValid[root[i]] == 0) ans = max(ans, sz[i]);
  cout << ans;
  return 0;
}
