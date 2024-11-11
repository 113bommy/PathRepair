#include <bits/stdc++.h>
using namespace std;
char s[1111111], s1[1111111];
int pre0[1111111], pre[1111111], a[1111111];
bool vis[1111111];
int n, cnt;
void gao(int k, int d) {
  cnt = 0;
  for (int i = 0; i < d; i++) {
    for (int j = i; j < k; j += d) {
      pre0[cnt++] = j;
    }
  }
  for (int i = k; i < n; i++) pre0[i] = i;
  for (int i = 0; i < n - 1; i++) pre[i] = pre0[i + 1];
  pre[n - 1] = pre0[0];
  for (int i = 0; i < n; i++) vis[i] = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cnt = 0;
      a[cnt++] = i;
      vis[i] = 1;
      int j = pre[i];
      while (j != i) {
        a[cnt++] = j;
        vis[j] = 1;
        j = pre[j];
      }
      if (i == 0) {
        for (j = 0; j <= n - k + 1; j++) {
          s1[j] = s[a[j]];
        }
      }
      for (j = 0; j < cnt; j++) {
        int p = a[j] + n - k + 1;
        if (p < n && p > n - k + 1) s1[p] = s[a[(j + n - k + 1) % cnt]];
      }
    }
  }
  s1[n] = '\0';
  for (int i = 0; i < n; i++) s[i] = s1[i];
  puts(s1);
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  int T, k, d;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &k, &d);
    gao(k, d);
  }
  return 0;
}
