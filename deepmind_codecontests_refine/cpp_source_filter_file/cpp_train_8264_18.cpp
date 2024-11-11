#include <bits/stdc++.h>
using namespace std;
vector<long long> val, arr;
long long init(long long n) {
  long long size = 1;
  while (size < n) size *= 2;
  size = size * 2;
  return size;
}
void build(long long x, long long l, long long r, long long ctr) {
  if (r - l == 1) {
    val[x] = arr[l];
    return;
  }
  long long m = (l + r) / 2;
  build(2 * x + 1, l, m, ctr + 1);
  build(2 * x + 2, m, r, ctr + 1);
  if (ctr % 2)
    val[x] = val[2 * x + 1] ^ val[2 * x + 2];
  else
    val[x] = val[2 * x + 1] | val[2 * x + 2];
}
void setv(long long i, long long v, long long x, long long l, long long r,
          long long ctr) {
  if (r - l == 1) {
    val[x] = v;
    return;
  }
  long long m = (l + r) / 2;
  if (i < m)
    setv(i, v, 2 * x + 1, l, m, ctr + 1);
  else
    setv(i, v, 2 * x + 2, m, r, ctr + 1);
  if (ctr % 2)
    val[x] = val[2 * x + 1] ^ val[2 * x + 2];
  else
    val[x] = val[2 * x + 1] | val[2 * x + 2];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, q;
  cin >> n >> q;
  long long z = n;
  n = n << 1;
  long long size = init(n);
  arr.resize(n);
  val.resize(size);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (z % 2 == 0)
    build(0, 0, size / 2, 1);
  else
    build(0, 0, size / 2, 0);
  while (q--) {
    long long i, v;
    cin >> i >> v;
    if (z % 2 == 0)
      setv(i - 1, v, 0, 0, size / 2, 1);
    else
      setv(i - 1, v, 0, 0, size / 2, 0);
    cout << val[0] << "\n";
  }
  return 0;
}
