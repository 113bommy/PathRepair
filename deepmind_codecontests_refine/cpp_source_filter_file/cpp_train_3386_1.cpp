#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> pr[800555];
long long lz[800555];
long long n, qr[200005], br[200005], ar[200005];
void pre() {
  for (int i = 0; i < 4 * n + 200; i++)
    pr[i] = make_pair(0ll, 1000000000000000000ll);
  for (int i = 0; i < n; i++) ar[i] = br[i];
  sort(ar, ar + n);
  ar[n] = ar[n - 1] + 1;
}
long long dot(pair<long long, long long> p, long long x) {
  return p.first * x + p.second;
}
long long get(long long idx, long long l, long long r, long long x) {
  if (r - l == 1) {
    return dot(pr[idx], x);
  }
  long long mid = (l + r) / 2;
  if (x < ar[mid])
    return min(dot(pr[idx], x), get(2 * idx, l, mid, x));
  else
    return min(dot(pr[idx], x), get(2 * idx + 1, mid, r, x));
}
void add_line(long long idx, long long l, long long r,
              pair<long long, long long> p) {
  long long mid = (l + r) / 2;
  long long lef = dot(p, ar[l]) < dot(pr[idx], ar[l]);
  long long m = dot(p, ar[mid]) < dot(pr[idx], ar[mid]);
  if (m) {
    swap(pr[idx], p);
  }
  if (r - l == 1) return;
  if (lef != m) {
    add_line(2 * idx, l, mid, p);
  } else {
    add_line(2 * idx + 1, mid, r, p);
  }
}
int main() {
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &br[i]);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += (i + 1) * br[i];
  long long ans = 0;
  pre();
  qr[0] = br[0];
  for (int i = 1; i < n + 1; i++) {
    qr[i] = qr[i - 1] + br[i];
  }
  add_line(1, 0, n, make_pair(-1, 0));
  for (int i = 1; i < n; i++) {
    long long x = get(1, 0, n, br[i]) - qr[i - 1] + (i + 1) * br[i];
    add_line(1, 0, n, make_pair(-(i + 1), qr[i - 1]));
    ans = max(ans, -x);
  }
  for (int i = 0; i < n / 2; i++) swap(ar[i], ar[n - i - 1]);
  pre();
  qr[0] = br[0];
  for (int i = 1; i < n + 1; i++) {
    qr[i] = qr[i - 1] + br[i];
  }
  add_line(1, 0, n, make_pair(-1, 0));
  for (int i = 1; i < n; i++) {
    long long x = get(1, 0, n, br[i]) - qr[i - 1] + (i + 1) * br[i];
    add_line(1, 0, n, make_pair(-(i + 1), qr[i - 1]));
    ans = max(ans, -x);
  }
  printf("%lld", sum + max(0ll, ans));
}
