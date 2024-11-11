#include <bits/stdc++.h>
using namespace std;
const long long MX = 3e5 + 9;
const long double pi = acos(-1);
const long long mod = 1e9 + 7;
bool cmp(int a, int b) { return a > b; }
long long po(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long x = po(a, b / 2);
  x *= x % mod;
  if (b % 2) {
    x *= a % mod;
  }
  return x % mod;
}
vector<int> v;
int vis[MX];
int par[MX];
int a[MX];
int temp, cnt;
long long p[MX];
int finds(int x) {
  if (x == par[x]) {
    return x;
  }
  return par[x] = finds(par[x]);
}
int main() {
  int n;
  cin >> n;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    p[i] = (p[i - 1] * 2 * 1ll) % mod;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i == finds(a[i])) {
      v.push_back(i);
    } else {
      par[i] = finds(a[i]);
    }
  }
  long long ans = 1;
  long long edges = n;
  for (int i = 0; i < v.size(); i++) {
    int u = v[i], c = 1;
    while (a[u] != v[i]) {
      u = a[u];
      c++;
    }
    edges -= c;
    ans = (ans * ((p[c] - 2 + mod) % mod)) % mod;
  }
  ans = (ans * (p[edges] + mod) % mod) % mod;
  cout << ans;
  return 0;
}
