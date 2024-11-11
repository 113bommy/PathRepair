#include <bits/stdc++.h>
using namespace std;
double a[4 * int(1e5 + 100)];
double lazy[4 * int(1e5 + 100)];
double lazy1[4 * int(1e5 + 100)];
void build(long long int b[], long long int l, long long int h,
           long long int pos) {
  if (l == h) {
    lazy1[pos - 1] = 1;
    a[pos - 1] = b[l - 1];
  } else {
    build(b, l, (l + h) / 2, 2 * pos);
    build(b, (l + h) / 2 + 1, h, 2 * pos + 1);
    a[pos - 1] = a[2 * pos - 1] + a[2 * pos];
    lazy1[pos - 1] = 1;
  }
}
double query(long long int l, long long int h, long long int le,
             long long int ri, long long int pos) {
  if (lazy[pos - 1]) {
    a[pos - 1] = lazy1[pos - 1] * a[pos - 1] + (h - l + 1) * lazy[pos - 1];
    if (l != h) {
      lazy[2 * pos - 1] = lazy[2 * pos - 1] * lazy1[pos - 1] + lazy[pos - 1];
      lazy[2 * pos] = lazy[2 * pos] * lazy1[pos - 1] + lazy[pos - 1];
      lazy1[2 * pos - 1] *= lazy1[pos - 1];
      lazy1[2 * pos] *= lazy1[pos - 1];
    }
    lazy[pos - 1] = 0;
    lazy1[pos - 1] = 1;
  }
  if (l >= le && h <= ri)
    return a[pos - 1];
  else if (ri < l || le > h)
    return 0;
  else {
    double x = query(l, (l + h) / 2, le, ri, 2 * pos);
    double y = query((l + h) / 2 + 1, h, le, ri, 2 * pos + 1);
    return (x + y);
  }
}
void updateutil(long long int l, long long int h, long long int le,
                long long int ri, long long int pos, double x, double m1) {
  if (lazy[pos - 1]) {
    a[pos - 1] = lazy1[pos - 1] * a[pos - 1] + (h - l + 1) * lazy[pos - 1];
    if (l != h) {
      lazy[2 * pos - 1] = lazy[2 * pos - 1] * lazy1[pos - 1] + lazy[pos - 1];
      lazy[2 * pos] = lazy[2 * pos] * lazy1[pos - 1] + lazy[pos - 1];
      lazy1[2 * pos - 1] *= lazy1[pos - 1];
      lazy1[2 * pos] *= lazy1[pos - 1];
    }
    lazy[pos - 1] = 0;
    lazy1[pos - 1] = 1;
  }
  if (ri < l || le > h)
    return;
  else if (l >= le && h <= ri) {
    a[pos - 1] = m1 * a[pos - 1] + (h - l + 1) * x;
    if (l != h) {
      lazy[2 * pos - 1] = lazy[2 * pos - 1] * m1 + x;
      lazy[2 * pos] = lazy[2 * pos] * m1 + x;
      lazy1[2 * pos - 1] *= m1;
      lazy1[2 * pos] *= m1;
    }
  } else {
    updateutil(l, (l + h) / 2, le, ri, 2 * pos, x, m1);
    updateutil((l + h) / 2 + 1, h, le, ri, 2 * pos + 1, x, m1);
    a[pos - 1] = a[2 * pos - 1] + a[2 * pos];
  }
}
void update(long long int n, long long int l1, long long int r1,
            long long int l2, long long int r2) {
  long long int n1 = (r1 - l1 + 1), n2 = (r2 - l2 + 1);
  double x = query(1, n, l1, r1, 1), y = query(1, n, l2, r2, 1),
         m1 = (1.0 - 1.0 / n1), m2 = (1.0 - 1.0 / n2);
  updateutil(1, n, l1, r1, 1, y / (n1 * n2), m1);
  updateutil(1, n, l2, r2, 1, x / (n1 * n2), m2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, q, s, l1, r1, l2, r2;
  cin >> n >> q;
  long long int b[n];
  for (long long int i = 0; i < n; i++) cin >> b[i];
  build(b, 1, n, 1);
  while (q--) {
    cin >> s;
    if (s == 1) {
      cin >> l1 >> r1 >> l2 >> r2;
      update(n, l1, r1, l2, r2);
    } else {
      cin >> l1 >> r1;
      printf("%.6Lf\n", query(1, n, l1, r1, 1));
    }
  }
}
