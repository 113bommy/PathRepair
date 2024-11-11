#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long double PI = acos(-1);
const long double EPS = 1e-9;
int mod_pow(int a, int b) {
  if (!b) return 1;
  if (b & 1) return mod_pow(a, b - 1) * a % MOD;
  int power = mod_pow(a, b >> 1);
  return power * power % MOD;
}
int modular_inverse(int a) { return mod_pow(a, MOD - 2); }
vector<int> movy = {0, 0, 1, -1};
vector<int> movx = {1, -1, 0, 0};
int n, q, p, lg;
long long a[MAXN], bit[MAXN], x;
void update(int i, long long v) {
  while (i <= n) {
    bit[i] += v;
    i += i & (-i);
  }
}
long long sum(int i) {
  long long ret = 0;
  while (i > 0) {
    ret += bit[i];
    i -= i & (-i);
  }
  return ret;
}
int find(long long v) {
  int pos = 0, k = 0;
  while (1 << (k + 1) <= n) k++;
  while (k >= 0) {
    if (pos + (1 << k) <= n && bit[pos + (1 << k)] < v) {
      pos += (1 << k);
      v -= bit[pos];
    }
    k--;
  }
  return pos + 1;
}
int query() {
  long long s = 0;
  while (1) {
    int pos = find(2 * s);
    if (pos > n) return -1;
    s = sum(pos);
    if (s == a[pos] * 2) return pos;
  }
}
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i]);
  }
  while (q--) {
    cin >> p >> x;
    update(p, x - a[p]);
    a[p] = x;
    cout << query() << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
