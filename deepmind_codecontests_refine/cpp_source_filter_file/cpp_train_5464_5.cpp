#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
map<int, int> ma;
int a[2 * 100000 + 3];
void invcnt(int l, int r, int mid, long long &cnt) {
  int i, j, k, c[mid + r + 1];
  i = l;
  k = l;
  j = mid + 1;
  while (l <= mid && j <= r) {
    if (a[i] < a[j]) {
      c[k] = a[i];
      k++;
      i++;
    } else {
      c[k] = a[j];
      k++;
      j++;
      cnt += (mid - i + 1);
    }
  }
  while (i <= mid) {
    c[k] = a[i];
    k++;
    i++;
  }
  while (j <= r) {
    c[k] = a[j];
    k++;
    j++;
  }
  for (i = l; i < k; i++) a[i] = c[i];
}
void mergesort(int l, int r, long long &inv) {
  long long lc = 0, rc = 0, sc = 0;
  if (l < r) {
    int mid = (l + r) >> 1;
    mergesort(l, mid, lc);
    mergesort(mid + 1, r, rc);
    invcnt(l, r, mid, sc);
    inv = lc + rc + sc;
  }
  return;
}
int main() {
  int n, i, j;
  cin >> n;
  for (j = 0; j < n; j++) {
    int a, b;
    cin >> a >> b;
    if (!ma.count(a) && !ma.count(b)) {
      ma[a] = b;
      ma[b] = a;
    } else if (ma.count(a) && !ma.count(b)) {
      int temp = ma[a];
      ma[b] = temp;
      ma[a] = b;
    } else if (!ma.count(a) && ma.count(b)) {
      int temp = ma[b];
      ma[a] = temp;
      ma[b] = a;
    } else {
      int temp = ma[a];
      ma[a] = ma[b];
      ma[b] = temp;
    }
  }
  int sz = 0;
  vector<int> v;
  for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++) {
    a[sz] = it->second;
    sz++;
    v.push_back(it->first);
  }
  long long ans = 0;
  mergesort(0, sz - 1, ans);
  for (j = 0; j < v.size(); j++) {
    int k = v[j];
    ans += ((abs(ma[k] - k) - 1) -
            (lower_bound(v.begin(), v.end(), max(ma[k], k)) -
             upper_bound(v.begin(), v.end(), min(k, ma[k]))));
  }
  cout << ans;
  return 0;
}
