#include <bits/stdc++.h>
const int N = 2e5 + 5;
int n, a[N], sum[N << 1], b[N], s[N], cnt;
bool pd[N << 1];
inline bool cmp(int x, int y) { return b[x] < b[y]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
    s[a[i]] = a[i];
  }
  std::sort(s + 1, s + n + 1, cmp);
  if (b[s[n]] == b[s[n - 1]]) {
    printf("%d\n", n);
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (i == s[n])
      continue;
    else if (b[i] > 520) {
      memset(sum, -1, sizeof(sum));
      memset(pd, 0, sizeof(pd));
      sum[N] = 0;
      int tmp = N;
      for (int v = 1; v <= n; v++) {
        if (a[v] == s[n])
          pd[tmp++] = true;
        else if (a[v] == i)
          pd[tmp--] = true;
        if (sum[tmp] == -1)
          sum[tmp] = v;
        else if (pd[tmp]) {
          ans = std::max(ans, v - sum[tmp]);
        }
      }
    }
  for (int i = 1; i <= 520; i++) {
    int l = 0;
    for (int v = 0; v <= n; v++) sum[v] = b[v] = 0;
    for (int v = 1; v <= n; v++) {
      --b[sum[a[v]]];
      ++b[++sum[a[v]]];
      while (l < v && b[i + 1] != 0) {
        ++l;
        --b[sum[a[l]]];
        ++b[--sum[a[l]]];
      }
      if (b[i] > 1) ans = std::max(ans, i - l);
    }
  }
  printf("%d\n", ans);
  return 0;
}
