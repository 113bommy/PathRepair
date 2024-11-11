#include <bits/stdc++.h>
using namespace std;
long long a[64], b[64], c[64];
long long aa[64], bb[64];
vector<long long> ans;
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    if (x == 1) {
      a[0]++;
      continue;
    }
    long long y = 1;
    for (long long j = 1; j <= 64; j++) {
      y = y * 2;
      if (y == x) {
        a[j]++;
        break;
      }
      if (y > x) {
        b[j]++;
        break;
      }
    }
  }
  for (long long i = 1; i <= a[0]; i++) {
    for (long long j = 0; j < 64; j++) aa[j] = a[j], bb[j] = b[j], c[j] = 0;
    long long cnt = i;
    for (long long j = 0; cnt != 0; j++) {
      if (aa[j] >= cnt) {
        aa[j] -= cnt;
      } else {
        c[j] = cnt - aa[j];
        cnt -= (cnt - aa[j]);
        aa[j] = 0;
      }
    }
    int q = 63;
    int flag = 0;
    for (int j = 63; j >= 0; j--) {
      while ((aa[j] + bb[j])) {
        if ((aa[j] + bb[j]) > c[q]) {
          aa[j] -= c[q];
          c[q] = 0;
          q--;
          if (q < j) break;
        } else {
          c[q] -= aa[j] + bb[j];
          aa[j] = bb[j] = 0;
        }
      }
    }
    for (int j = 0; j < 64; j++)
      if ((aa[j] + bb[j]) != 0) flag = 1;
    if (flag == 0) ans.push_back(i);
  }
  if (ans.size() == 0) {
    printf("-1\n");
  }
  for (long long i = 0; i < ans.size(); i++) {
    printf("%lld ", ans[i]);
  }
}
