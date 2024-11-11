#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e6 + 30;
const int MAXN = 1e2 + 2;
const long long INF = 1e18 + 7;
const long long BINF = 1e15;
const int mod = 1e6 + 3;
const long double EPS = 1e-15;
const long long dx[] = {0, 0, 1, -1};
const long long dy[] = {1, -1, 0, 0};
struct ln {
  long double k, b;
};
int n;
long long a[MXN];
long long p1[MXN], p2[MXN], p3[MXN];
long long mx = -INF;
int sz;
ln t[MXN];
bool check(ln q, ln w, ln e, ln r, int u) {
  return u * ((w.b - q.b) * (e.k - r.k) - (r.b - e.b) * (q.k - w.k)) < EPS;
}
double intr(ln q, ln w) { return (w.b - q.b) / (q.k - w.k); }
long double Find1(long double x) {
  int l = 1, r = sz - 1;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (intr(t[mid], t[mid + 1]) - x < EPS) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (intr(t[l], t[l + 1]) - x < EPS) {
    return t[l].k * x + t[l].b;
  } else if (intr(t[r], t[r + 1]) - x < EPS) {
    return t[r].k * x + t[r].b;
  }
  return t[sz].k * x + t[sz].b;
}
long double Find(long double x) {
  int l = 1, r = sz - 1;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (intr(t[mid], t[mid + 1]) - x < -EPS) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (intr(t[l], t[l + 1]) - x > -EPS) {
    return t[l].k * x + t[l].b;
  } else if (intr(t[r], t[r + 1]) - x > -EPS) {
    return t[r].k * x + t[r].b;
  }
  return t[sz].k * x + t[sz].b;
}
void add(ln q, int u) {
  while (sz >= 2 && check(q, t[sz - 1], t[sz], t[sz - 1], u)) {
    sz--;
  }
  t[++sz] = q;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p2[i] = p2[i - 1] + a[i] * i;
    p1[i] = p1[i - 1] + a[i] * (i - 1);
    p3[i] = p3[i - 1] + a[i] * (i + 1);
  }
  for (int i = 1; i <= n; i++) {
    add({i * 1.0, (p2[i - 1] - p3[i - 1]) * 1.0}, 1);
    long long x = (Find(a[i]));
    mx = max(mx, x + p2[n] - p2[i] + p3[i - 1]);
  }
  sz = 0;
  for (int i = n; i >= 1; i--) {
    add({i * 1.0, (p1[i] - p2[i]) * 1.0}, -1);
    long long x = (Find1(a[i]));
    mx = max(mx, x + p2[i - 1] - p1[i] + p2[n]);
  }
  cout << mx << ' ';
  return 0;
}
