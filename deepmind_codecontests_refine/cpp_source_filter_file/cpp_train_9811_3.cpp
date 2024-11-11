#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int compare(long long int a, long long int b, long long int val) {
  if (abs(a - val) >= abs(b - val))
    return b;
  else
    return a;
}
long long int binarysearch(long long int a[], long long int n,
                           long long int val) {
  if (val >= a[n - 1]) return a[n - 1];
  if (val <= a[0]) return a[0];
  long long int l = 0, r = n - 1, mid = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (a[mid] == val) return val;
    if (a[mid] > val) {
      if (val > a[mid - 1] && mid > 0) return compare(a[mid], a[mid - 1], val);
      r = mid;
    } else {
      if (val < a[mid + 1] && mid < n - 1)
        return compare(a[mid], a[mid + 1], val);
      l = mid + 1;
    }
  }
  return a[l];
}
void solve() {
  long long int nr, ng, nb;
  cin >> nr >> ng >> nb;
  long long int r[nr], g[ng], b[nb], ans = INT_MAX;
  for (long long int i = 0; i < nr; i++) cin >> r[i];
  for (long long int i = 0; i < ng; i++) cin >> g[i];
  for (long long int i = 0; i < nb; i++) cin >> b[i];
  sort(r, r + nr);
  sort(g, g + ng);
  sort(b, b + nb);
  for (long long int i = 0; i < nr; i++) {
    long long int g1 = binarysearch(g, ng, r[i]);
    long long int b1 = binarysearch(b, nb, r[i]);
    long long int r1 = r[i];
    long long int c = pow(abs(g1 - b1), 2);
    c += pow(abs(r1 - b1), 2);
    c += pow(abs(g1 - r1), 2);
    ans = min(ans, c);
  }
  for (long long int i = 0; i < ng; i++) {
    long long int r1 = binarysearch(r, nr, g[i]);
    long long int b1 = binarysearch(b, nb, g[i]);
    long long int g1 = g[i];
    long long int c = pow(abs(g1 - b1), 2);
    c += pow(abs(r1 - b1), 2);
    c += pow(abs(g1 - r1), 2);
    ans = min(ans, c);
  }
  for (long long int i = 0; i < nb; i++) {
    long long int g1 = binarysearch(g, ng, b[i]);
    long long int r1 = binarysearch(r, nr, b[i]);
    long long int b1 = b[i];
    long long int c = pow(abs(g1 - b1), 2);
    c += pow(abs(r1 - b1), 2);
    c += pow(abs(g1 - r1), 2);
    ans = min(ans, c);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
