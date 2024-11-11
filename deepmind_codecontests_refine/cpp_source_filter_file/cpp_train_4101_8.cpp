#include <bits/stdc++.h>
using namespace std;
const int me = 100005;
const int fix = 26;
const int mod = 1.e9 + 7;
const long long big = 1LL << 55;
int n, k;
long long a[me];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int s1, s2, s3, s4;
    scanf("%d.%d.%d.%d", &s1, &s2, &s3, &s4);
    a[i] |= 1LL * (1 << 24) * s1;
    a[i] |= 1LL * (1 << 16) * s2;
    a[i] |= 1LL * (1 << 8) * s3;
    a[i] |= s4;
  }
  long long mask = 0;
  for (int i = 31; i >= 0; i--) {
    mask |= (1LL << i);
    unordered_set<long long> s;
    for (int j = 0; j < n; j++) s.insert(mask & a[j]);
    if (s.size() == k) {
      int s1 = mask & 255;
      mask >>= 8;
      int s2 = mask & 255;
      mask >>= 8;
      int s3 = mask & 255;
      mask >>= 8;
      int s4 = mask;
      printf("%d.%d.%d.%d\n", s4, s3, s2, s1);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
