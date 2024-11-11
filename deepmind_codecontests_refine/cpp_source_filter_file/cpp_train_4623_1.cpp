#include <bits/stdc++.h>
using namespace std;
int aa[100000];
int bb[100000];
int a[200000];
int b[200000];
pair<int, int> pii[100000];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i != n; ++i) {
    cin >> aa[i] >> bb[i];
  }
  copy(aa, aa + n, a);
  copy(aa, aa + n, a + n);
  copy(bb, bb + n, b);
  copy(bb, bb + n, b + n);
  sort(a, a + 2 * n);
  sort(b, b + 2 * n);
  long long sum = 0;
  long long s1 = 0;
  long long s2 = 0;
  for (int i = 0; i != n * 2; ++i) {
    if (i < n) {
      sum -= a[i];
      sum -= b[i];
    } else {
      sum += a[i];
      sum += b[i];
    }
    if (n - 1 == i) {
      s1 -= a[i];
      s2 -= b[i];
    }
    if (n == i) {
      s1 += a[i];
      s2 += b[i];
    }
  }
  if (0 == n % 2) {
    int *paa = aa;
    int *pbb = bb;
    int *pa = a;
    int *pb = b;
    if (s1 > s2) {
      swap(pa, pb);
      swap(paa, pbb);
    }
    for (int i = 0; i != n; ++i) pii[i] = make_pair(paa[i], pbb[i]);
    sort(pii, pii + n);
    int h11, h12, h21, h22;
    h11 = h12 = pii[0].second;
    for (int i = 0; i != n / 2; ++i) {
      h12 = max(h12, pii[i].second);
      h11 = min(h11, pii[i].second);
    }
    h21 = h22 = pii[n / 2].second;
    for (int i = n / 2; i != n; ++i) {
      h22 = max(h12, pii[i].second);
      h21 = min(h11, pii[i].second);
    }
    if (h12 <= h21 || h11 >= h22)
      cout << sum << endl;
    else
      cout << sum - 2 * min(s1, s2) << endl;
  } else {
    for (int i = 0; i != n; ++i) pii[i] = make_pair(aa[i], bb[i]);
    pair<int, int> pt = make_pair(a[n], b[n]);
    if (count(pii, pii + n, pt) == 1) {
      sort(pii, pii + n);
      int h11, h12, h21, h22;
      h11 = h12 = pii[0].second;
      for (int i = 0; i != n / 2; ++i) {
        h12 = max(h12, pii[i].second);
        h11 = min(h11, pii[i].second);
      }
      h21 = h22 = pii[n / 2 + 1].second;
      for (int i = n / 2 + 1; i != n; ++i) {
        h22 = max(h12, pii[i].second);
        h21 = min(h11, pii[i].second);
      }
      if (h12 <= h21 || h11 >= h22) {
        cout << sum << endl;
        return 0;
      }
      int t1 = min(a[n + 1] - a[n], a[n - 1] - a[n - 2]);
      int t2 = min(b[n + 1] - b[n], b[n - 1] - b[n - 2]);
      cout << sum - 2 * min(t1, t2) << endl;
    } else {
      cout << sum << endl;
    }
  }
}
