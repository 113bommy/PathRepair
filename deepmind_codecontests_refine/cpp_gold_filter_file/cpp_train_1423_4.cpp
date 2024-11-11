#include <bits/stdc++.h>
using namespace std;
const int M = 1e8;
const int N = 1e4;
int p[N], a[N], ans[N], pre[N];
inline void init() {
  for (int i = 2; i < N; i++) {
    if (!p[i]) p[++p[0]] = i;
    for (int j = 1; j <= p[0] && p[j] * i < N; j++) {
      p[p[j] * i] = 1;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 1; i <= p[0]; i++) p[i] *= p[i];
}
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0 || a[i] == 1 || a[i] == -1) continue;
    for (int k = 1; k < p[0] && p[k] <= abs(a[i]); k++) {
      while (a[i] % p[k] == 0) a[i] /= p[k];
    }
  }
  memset(pre, -1, sizeof pre);
  for (int i = 0; i < n; i++) {
    if (!~pre[i]) {
      int lab = i;
      for (int j = i + 1; j < n; j++) {
        if (a[j] == a[i]) {
          pre[j] = lab;
          lab = j;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    bool zero = false;
    int cnt = 0;
    for (int j = i; j < n; j++) {
      if (a[j] == 0)
        zero = true;
      else if (pre[j] < i)
        cnt++;
      ans[cnt ? cnt : zero]++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
