#include <bits/stdc++.h>
using lint = long long int;
using pii = std::pair<int, int>;
int start[100010];
int end[100010];
int di[100010];
int sz = 500;
lint buk[1000];
lint arr[100010];
int p[100010];
int main(void) {
  memset(start, 0xff, sizeof(start));
  memset(p, 0xff, sizeof(p));
  int n;
  lint k;
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < 1000; i++) {
    buk[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    di[i] = i / sz;
    if (start[di[i]] == -1) start[di[i]] = i;
    end[di[i]] = std::max(end[di[i]], i);
    arr[i] %= k;
    buk[di[i]] = (buk[di[i]] * arr[i]) % k;
  }
  for (int i = 0; i < n; i++) {
    long long q = 1;
    for (int j = i; j < n; j++) {
      if (start[di[j]] == j && (buk[di[j]] * q) % k != 0) {
        q = (buk[di[j]] * q) % k;
        j = end[di[j]];
        continue;
      }
      q = (q * arr[j]) % k;
      if (q == 0) {
        p[i] = j;
        break;
      }
    }
  }
  lint ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] != -1) {
      ans += n - p[i];
    }
  }
  printf("%lld", ans);
  return 0;
}
