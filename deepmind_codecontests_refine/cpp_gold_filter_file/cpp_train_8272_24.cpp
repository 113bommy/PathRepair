#include <bits/stdc++.h>
using namespace std;
const long long modl = 1e9 + 7;
const long long base = 1e6 + 33;
long long f[1000010];
long long p[1000010];
inline long long get(int l, int r) {
  long long ret = (f[r] - f[l - 1] * p[r - l + 1]) % modl;
  if (ret < 0) ret += modl;
  return ret;
}
int n, k;
char s[1000010];
int ans[1000010];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  f[0] = 0;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = (f[i - 1] * base + s[i]) % modl;
    p[i] = (p[i - 1] * base) % modl;
  }
  for (int len = 1; len <= n / k; len++) {
    bool ok = true;
    for (int i = 0, j = 0; i < k; i++, j += len) {
      if (j + len > n || get(j + 1, j + len) != get(1, len)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      int k_len = k * len;
      int l = 1;
      int r = min(len, n - k_len);
      while (l < r) {
        int mid = (l + r) / 2;
        if (k_len + mid > n || get(k_len + 1, k_len + mid) != get(1, mid))
          r = mid;
        else
          l = mid + 1;
      }
      if (k_len + l > n || get(k_len + 1, k_len + l) != get(1, l)) l--;
      ans[k_len]++;
      ans[k_len + l + 1]--;
    }
  }
  long long temp = 0;
  for (int i = 1; i <= n; i++) {
    temp += ans[i];
    printf("%d", temp > 0);
  }
  return 0;
}
