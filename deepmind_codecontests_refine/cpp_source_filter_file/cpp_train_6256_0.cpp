#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const long long INF = (1LL << 61);
const int inf = (1 << 30), nn = 2e5 + 5;
int fir[nn], last[nn], a[nn];
int seg[4 * nn];
void build(int n, int s, int e) {
  if (s == e) {
    seg[n] = a[s];
    return;
  }
  int mid = (s + e) / 2;
  build(2 * n, s, mid);
  build(2 * n + 1, mid + 1, e);
  seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}
int query(int n, int s, int e, int l, int r) {
  if (s > r || e < l)
    return inf;
  else if (s >= l && e <= r)
    return seg[n];
  else {
    int mid = (s + e) / 2;
    return min(query(2 * n, s, mid, l, r), query(2 * n + 1, mid + 1, e, l, r));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  bool isq = 0, is0 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == q) isq = 1;
    if (!a[i]) is0 = 1;
  }
  if (!isq && !is0) {
    cout << "NO";
    return 0;
  } else if (!isq && is0) {
    for (int i = 0; i < n; i++) {
      if (!a[i]) {
        a[i] = q;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      if (i)
        a[i] = a[i - 1];
      else {
        int j;
        for (j = 0; j < n && !a[j]; j++)
          ;
        a[0] = a[j];
      }
    }
  }
  build(1, 0, n - 1);
  fill(fir, fir + nn, -1);
  fill(last, last + nn, -1);
  for (int i = 0; i < n; i++) {
    if (fir[i] == -1) {
      fir[a[i]] = i;
      last[a[i]] = i;
    } else
      last[a[i]] = i;
  }
  for (int i = 1; i <= q; i++) {
    int l = fir[i], r = last[i];
    int minn = query(1, 0, n - 1, l, r);
    if (minn < i) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  return 0;
}
