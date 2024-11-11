#include <bits/stdc++.h>
using namespace std;
struct pokr {
  double p1;
  double p2;
  double len;
  pokr(double _p1, double _p2, double _l) : p1(_p1), p2(_p2), len(_l) {}
  pokr() { p1 = p2 = len = 0; }
} d[2100][2100];
int x[2100];
int c[2100][2100];
int a[2100];
int b[2100];
double p, q;
int h;
pokr get_ans(int l, int r) {
  pokr res;
  if (l > r) return pokr(0, 0, 0);
  if (l == r) return pokr(p, q, 0);
  if (c[l][r]) return d[l][r];
  pokr temp = get_ans(l + 1, r);
  res.p1 += p / 2;
  res.p2 += temp.p2 * p / 2;
  res.len += p / 2 * temp.len;
  res.len += p / 2 * temp.p1 * min(x[l + 1] - x[l], h);
  int next = b[l];
  if (next <= r) {
    pokr temp = get_ans(next, r);
    res.p2 += q / 2 * temp.p2;
    res.len += q / 2 * temp.len;
    res.len += q / 2 * (x[next - 1] + h - x[l]);
    res.len += q / 2 * temp.p1 * min(x[next] - x[next - 1] - h, h);
  } else {
    res.p2 += q / 2;
    res.len += q / 2 * (x[r] - x[l]);
  }
  temp = get_ans(l, r - 1);
  res.p2 += q / 2;
  res.p1 += temp.p1 * q / 2;
  res.len += q / 2 * temp.len;
  res.len += q / 2 * temp.p2 * min(x[r] - x[r - 1], h);
  int prev = a[r];
  if (prev >= l) {
    pokr temp = get_ans(l, prev);
    res.p1 += p / 2 * temp.p1;
    res.len += p / 2 * temp.len;
    res.len += p / 2 * (x[r] - x[prev + 1] + h);
    res.len += p / 2 * temp.p2 * min(x[prev + 1] - x[prev] - h, h);
  } else {
    res.p1 += p / 2;
    res.len += p / 2 * (x[r] - x[l]);
  }
  c[l][r] = 1;
  d[l][r] = res;
  return res;
}
int main() {
  int n;
  cin >> n >> h;
  cin >> p;
  q = 1 - p;
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  a[0] = -1;
  for (int i = 1; i < n; i++)
    if (x[i] - x[i - 1] < h)
      a[i] = a[i - 1];
    else
      a[i] = i - 1;
  b[n - 1] = n;
  for (int i = n - 2; i >= 0; i--)
    if (x[i + 1] - x[i] < h)
      b[i] = b[i + 1];
    else
      b[i] = i + 1;
  pokr r = get_ans(0, n - 1);
  printf("%.12f", (r.p1 + r.p2) * h + r.len);
  return 0;
}
