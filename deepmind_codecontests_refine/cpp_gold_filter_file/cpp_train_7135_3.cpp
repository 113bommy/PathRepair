#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int mod = 1e9 + 7;
struct line {
  long long k, b;
  line(long long _k = 0, long long _b = 0) {
    k = _k;
    b = _b;
  }
} L[N], st[N];
int n, a[N], m, ptr, sz;
long long second[N], sum[N], ans, mx;
long long first(line l, int x) { return 1ll * l.k * x + l.b; }
bool cmp(line a, line b) {
  if (a.b == b.b) return a.k > b.k;
  return a.b > b.b;
}
long double inter(line a, line b) {
  return (long double)(b.b - a.b) / (long double)(a.k - b.k);
}
void add(line cur) {
  while (sz >= 2 && inter(st[sz - 1], cur) < inter(st[sz - 1], st[sz])) sz--;
  st[++sz] = cur;
}
void build() {
  sort(L + 1, L + m + 1, &cmp);
  sz = 0;
  ptr = 1;
  mx = (long long)-1e18;
  for (int i = 1; i <= m; i++) {
    if (mx < L[i].k) {
      mx = L[i].k;
      add(L[i]);
    }
  }
}
long long get_max(int x) {
  while (ptr + 1 <= sz && first(st[ptr + 1], x) >= first(st[ptr], x)) ptr++;
  return first(st[ptr], x);
}
void go(int l = 1, int r = n) {
  if (l > r) return;
  if (l == r) {
    ans = max(ans, (long long)a[l]);
    return;
  }
  int mid = (l + r) / 2;
  go(l, mid);
  go(mid + 1, r);
  m = 0;
  for (int i = mid + 1; i <= r; i++) L[++m] = line(-sum[i], second[i]);
  build();
  for (int i = l - 1; i < mid; i++)
    ans = max(ans, 1ll * i * sum[i] - second[i] + get_max(i));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    second[i] = second[i - 1] + 1ll * i * a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  go();
  cout << ans;
  return 0;
}
