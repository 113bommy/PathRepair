#include <bits/stdc++.h>
using namespace std;
int in[300005], out[300005], tt = 0;
long long int mod = 1e9 + 7, h[300005];
vector<int> v[300005];
struct node {
  long long int a, b, c;
} bit[300005];
void upd(int i, long long int x, long long int k, long long int hh) {
  while (i <= 300004) {
    bit[i].a += x;
    bit[i].b += k;
    bit[i].c += hh;
    bit[i].a %= mod;
    bit[i].b %= mod;
    bit[i].c %= mod;
    i += i & -i;
  }
}
long long int get(int i, int at) {
  long long int r = 0;
  while (i) {
    r = (r + bit[i].a - h[at] * bit[i].b + bit[i].c) % mod;
    i -= i & -i;
  }
  return (r + mod) % mod;
}
void dfs(int at, int hh = 0) {
  in[at] = ++tt;
  h[at] = hh;
  for (__typeof(v[at].begin()) it = v[at].begin(); it != v[at].end(); it++)
    dfs(*it, hh + 1);
  out[at] = tt;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    v[a].push_back(i);
  }
  dfs(1, 0);
  int q;
  cin >> q;
  while (q--) {
    int t;
    long long int at, x, k;
    cin >> t;
    if (t == 1) {
      cin >> at >> x >> k;
      upd(in[at], x, k, (h[at] * k) % mod);
      upd(out[at] + 1, x, k, (h[at] * k) % mod);
    } else {
      cin >> at;
      long long int ans = (get(in[at], at)) % mod;
      cout << (ans + mod) % mod;
      cout << "\n";
    }
  }
  return 0;
}
