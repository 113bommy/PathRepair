#include <bits/stdc++.h>
using namespace std;
int aa[100005], p[10000], bb[100005];
map<int, int> mp;
int main() {
  int k = 0, a, n, ans = 0, m = 0;
  for (int i = 2; i <= 100000; i++) {
    if (aa[i] == 0) {
      p[k] = i;
      k++;
      for (int j = 2 * i; j <= 100000; j += i) {
        aa[j] = 1;
      }
    }
  }
  memset(aa, 0, sizeof(aa));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (mp[a] == 0) bb[m++] = a;
    mp[a]++;
  }
  if (m == 1) {
    if (bb[0] == 1)
      printf("1");
    else
      printf("%d", n);
  } else {
    for (int i = 0; i < m; i++) {
      for (int j = 0; p[j] <= a && j < k; j++) {
        if (bb[i] % p[j] == 0) aa[j] += mp[bb[i]];
      }
    }
    for (int i = 0; i < k; i++) {
      ans = max(ans, aa[i]);
    }
    printf("%d", ans);
  }
  return 0;
}
