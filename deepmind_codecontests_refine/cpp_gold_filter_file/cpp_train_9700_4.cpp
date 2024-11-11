#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:300000000")
using namespace std;
pair<int, bool> a[150];
pair<int, bool> temp[150];
double b[150];
int main() {
  for (int i = 0; i < (150); ++i) b[i] = 0.;
  int n, k, q;
  cin >> n >> k;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i].first;
    a[i].second = false;
  }
  cin >> q;
  int len = n / k;
  int cnt = 0;
  for (int i = 0; i < (q); ++i) {
    int t;
    bool uni = true;
    for (int j = 0; j < (len); ++j) {
      cin >> t;
      --t;
      if (a[t].second) {
        uni = false;
        continue;
      }
      b[cnt] += a[t].first;
      a[t].second = true;
    }
    if (uni) {
      b[cnt] /= len;
      ++cnt;
    }
  }
  sort(a, a + n);
  memcpy(temp, a, sizeof(a));
  {
    int j = 0;
    for (int w = 0; w < (n % k); ++w) {
      while (j < n && a[j].second) ++j;
      if (j == n) break;
      a[j].second = true;
    }
    bool ok = true;
    j = n - 1;
    for (int w = 0; w < len; ++w) {
      while (j >= 0 && a[j].second) --j;
      if (j < 0) {
        ok = false;
        break;
      }
      b[cnt] += a[j].first;
      a[j].second = true;
    }
    if (ok) {
      b[cnt] /= len;
      ++cnt;
    } else
      b[cnt] = 0.;
  }
  {
    memcpy(a, temp, sizeof(temp));
    int j = n - 1;
    for (int w = 0; w < (n % k); ++w) {
      while (j >= 0 && a[j].second) --j;
      if (j < 0) break;
      a[j].second = true;
    }
    bool ok = true;
    j = 0;
    for (int w = 0; w < len; ++w) {
      while (j < n && a[j].second) ++j;
      if (j == n) {
        ok = false;
        break;
      }
      b[cnt] += a[j].first;
      a[j].second = true;
    }
    if (ok) {
      b[cnt] /= len;
      ++cnt;
    } else
      b[cnt] = 0.;
  }
  sort(b, b + cnt);
  printf("%.7lf %.7lf", b[0], b[cnt - 1]);
  return 0;
}
