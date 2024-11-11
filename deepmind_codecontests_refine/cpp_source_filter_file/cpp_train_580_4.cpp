#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], b[N], top;
int T, n, G, v, ans[N];
map<int, int> mp;
pair<int, int> q[N];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void exgcd(int x, int y, int &a, int &b) {
  if (!y) {
    a = 1;
    b = 0;
    return;
  }
  exgcd(y, x % y, b, a);
  b -= x / y * a;
}
int getinv(int x, int y) {
  int a, b;
  exgcd(x, y, a, b);
  return (a % y + y) % y;
}
void solve(int l, int r) {
  if (!v) {
    for (int i = (int)(l); i <= (int)(r); i++) ans[q[i].second] = 1;
    return;
  }
  int iv = getinv(v / G, T / G);
  for (int i = (int)(l); i <= (int)(r); i++)
    q[i].first = 1ll * iv * (b[q[i].second] / G) % (T / G);
  sort(q + l, q + r + 1);
  for (int i = (int)(l); i <= (int)(r - 1); i++)
    ans[q[i].second] = q[i + 1].first - q[i].first;
  ans[q[r].second] = T / G + q[l].first - q[r].first;
}
int main() {
  scanf("%d%d", &T, &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(2); i <= (int)(n); i++) b[i] = (b[i - 1] + a[i]) % T;
  v = (a[1] + b[n]) % T;
  G = gcd(v, T);
  for (int i = (int)(1); i <= (int)(n); i++) {
    if (!mp[b[i]]) q[++top] = pair<int, int>(a[i] % G, i);
    mp[b[i]] = 1;
  }
  sort(q + 1, q + top + 1);
  int l = 1;
  for (int i = (int)(2); i <= (int)(n + 1); i++)
    if (i == n + 1 || q[i].first != q[i - 1].first) solve(l, i - 1), l = i;
  for (int i = (int)(1); i <= (int)(n); i++) printf("%d ", ans[i]);
}
