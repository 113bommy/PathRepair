#include <bits/stdc++.h>
using namespace std;
struct ju {
  long long a[2][2];
};
struct xiang {
  long long a[2];
} an;
struct seg {
  int l, r;
  ju x;
} t[50010 * 4];
struct Info {
  long long x, y;
} b[50010];
map<long long, long long> g;
long long k, mo, a[50010], no;
int n, m;
ju operator*(ju x, ju y) {
  ju z;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      z.a[i][j] = 0;
      for (int k = 0; k <= 1; k++)
        z.a[i][j] = (z.a[i][j] + x.a[i][k] * y.a[k][j]) % mo;
    }
  }
  return z;
}
xiang operator*(xiang x, ju y) {
  xiang z;
  for (int i = 0; i <= 1; i++) {
    z.a[i] = 0;
    for (int j = 0; j <= 1; j++) z.a[i] = (z.a[i] + x.a[j] * y.a[j][i]) % mo;
  }
  return z;
}
bool c1(const Info &a, const Info &b) { return a.x < b.x; }
long long que(long long x) {
  if (x < 0) x += n;
  if (g[x]) return g[x];
  return a[x % n];
}
void build(int nu, int l, int r) {
  t[nu].l = l;
  t[nu].r = r;
  if (l == r) {
    ju no;
    no.a[0][0] = 0;
    no.a[0][1] = que(l - 2);
    no.a[1][0] = 1;
    no.a[1][1] = que(l - 1);
    t[nu].x = no;
  } else {
    build(nu * 2, l, (l + r) / 2);
    build(nu * 2 + 1, (l + r) / 2 + 1, r);
    t[nu].x = t[nu * 2].x * t[nu * 2 + 1].x;
  }
}
ju que(int nu, int l, int r) {
  if (t[nu].l == l && t[nu].r == r) return t[nu].x;
  int mid = (t[nu].l + t[nu].r) / 2;
  if (l > mid) return que(nu * 2 + 1, l, r);
  if (r <= mid) return que(nu * 2, l, r);
  return que(nu * 2, l, mid) * que(nu * 2 + 1, mid + 1, r);
}
ju po(ju x, long long y) {
  ju z = x;
  y--;
  while (y) {
    if (y % 2) z = x * z;
    x = x * x;
    y /= 2;
  }
  return z;
}
void tr() {
  swap(an.a[0], an.a[1]);
  an.a[1] = (an.a[1] * que(no - 1) + an.a[0] * que(no)) % mo;
  no++;
}
void tr(long long x) {
  if (x <= no) return;
  if (x / n == no / n) {
    an = an * que(1, (no + 1) % n, x % n);
    no = x;
    return;
  }
  if (no % n != n - 1) {
    an = an * que(1, (no + 1) % n, n - 1);
    no = no / n * n + n - 1;
  }
  long long g = (x - no) / n;
  if (g) {
    an = an * po(t[1].x, g);
    no += g * n;
  }
  if (x <= no) return;
  an = an * que(1, (no + 1) % n, x % n);
  no = x;
  return;
}
int main() {
  cin >> k >> mo;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i].x >> b[i].y;
    g[b[i].x] = b[i].y;
  }
  sort(b + 1, b + m + 1, c1);
  while (m >= 1 && b[m].x >= k) m--;
  if (k == 0) {
    puts("0");
    return 0;
  }
  build(1, 0, n - 1);
  an.a[0] = 0;
  an.a[1] = 1 % mo;
  no = 1;
  for (int i = 1; i <= m; i++) {
    tr(b[i].x);
    if (no < k && no == b[i].x) tr();
    if (no < k && no == b[i].x + 1) tr();
  }
  tr(k);
  cout << an.a[1] << endl;
  return 0;
}
