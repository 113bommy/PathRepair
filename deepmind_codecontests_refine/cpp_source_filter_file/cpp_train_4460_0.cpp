#include <bits/stdc++.h>
using namespace std;
int a[1010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  long long ans = (long long)-1e18;
  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) {
    long long cur = 0;
    for (int j = i; j < n; j += 2) {
      if (j == i || a[j] > 0) {
        cur += a[j];
      }
      if (cur > ans) {
        ans = cur;
        l = i;
        r = j;
      }
    }
  }
  printf("%lld\n", ans);
  vector<int> w;
  for (int i = n - 1; i > r; --i) {
    w.push_back(i);
  }
  for (int i = 0; i < l; ++i) {
    w.push_back(i);
  }
  vector<long long> z;
  for (int i = l; i <= r; ++i) {
    z.push_back(a[i]);
  }
  while ((int)z.size() > 1) {
    vector<long long> nz;
    if (z[2] > 0) {
      w.push_back(1);
      nz.push_back(z[0] + z[2]);
      for (int i = 3; i < (int)z.size(); ++i) {
        nz.push_back(z[i]);
      }
    } else {
      w.push_back(2);
      nz.push_back(z[0]);
      nz.push_back(z[1] + z[3]);
      for (int i = 4; i < (int)z.size(); ++i) {
        nz.push_back(z[i]);
      }
    }
    z = nz;
  }
  assert(z[0] == ans);
  printf("%d\n", (int)w.size());
  for (int e : w) {
    printf("%d\n", e + 1);
  }
}
