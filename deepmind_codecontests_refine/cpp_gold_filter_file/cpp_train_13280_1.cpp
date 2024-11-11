#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e10 + 10;
const int maxn = 1e7 + 100;
int n, x, Max;
long long k, tot;
int num[maxn], tmp[maxn];
long long judge(int mid) {
  if (mid == 0) {
    return INF;
  }
  long long ret = 0;
  memcpy(tmp, num, sizeof(num));
  for (int i = Max; i >= mid; --i) {
    if (i / 2 >= mid) {
      tmp[i / 2] += tmp[i];
      tmp[(i + 1) / 2] += tmp[i];
    } else {
      ret += tmp[i];
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  while (scanf("%d%I64d", &n, &k) != EOF) {
    Max = 0;
    tot = 0;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      Max = max(Max, x);
      ++num[x];
      tot += x;
    }
    if (tot < k) {
      printf("-1\n");
      continue;
    }
    int low = 1, high = maxn;
    int mid;
    while (high - low > 1) {
      mid = (low + high) >> 1;
      if (judge(mid) >= k) {
        low = mid;
      } else {
        high = mid;
      }
    }
    printf("%d\n", low);
  }
  return 0;
}
