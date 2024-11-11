#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 100;
const long long MAXN = 100500;
long long a[MAXN * 2];
long long b[MAXN * 2];
long long t[MAXN * 6];
void build(long long v, long long l, long long r) {
  if (l == r) {
    t[v] = a[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(v * 2, l, mid);
  build(v * 2 + 1, mid + 1, r);
  t[v] = max(t[v * 2], t[v * 2 + 1]);
}
long long getmax(long long v, long long l, long long r, long long pos) {
  if (l == r) {
    if (pos == l) {
      return -INF;
    } else {
      return t[v];
    }
  }
  if (l > pos || r < pos) {
    return t[v];
  }
  long long mid = (l + r) / 2;
  return max(getmax(v * 2, l, mid, pos), getmax(v * 2 + 1, mid + 1, r, pos));
}
int main() {
  long long n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sum += b[i];
  }
  build(1, 1, n);
  for (int i = n; i >= 1; i--) {
    cout << (sum - b[i]) * (getmax(1, 1, n, i)) << " ";
  }
}
