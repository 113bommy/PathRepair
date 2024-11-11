#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k, cnt = 0, have[1010], a[N], f[N][2];
int getfl(int x) {
  if (x >= 0) {
    return 0;
  }
  return 1;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    have[x] = 1;
  }
  for (int i = 0; i < N; i++) {
    f[i][0] = 1e9;
    f[i][1] = 1e9;
  }
  for (int i = 1; i <= 1000; i++) {
    if (have[i]) {
      a[++cnt] = i - n;
    }
  }
  n = cnt;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= 0) {
      f[a[i]][0] = 1;
    } else {
      f[abs(a[i])][1] = 1;
    }
    q.push(a[i]);
  }
  while (!q.empty() && (f[0][0] == 1e9)) {
    int x = q.front(), fl = getfl(x);
    for (int j = 1; j <= cnt; j++) {
      if (abs(a[j] + x) > 1000) {
        continue;
      }
      if (f[abs(a[j] + x)][getfl(a[j] + x)] > f[abs(x)][fl] + 1) {
        f[abs(a[j] + x)][getfl(a[j] + x)] = f[abs(x)][fl] + 1;
        q.push(a[j] + x);
      }
    }
    q.pop();
  }
  if (f[0][0] == 1e9) {
    puts("-1");
  } else {
    printf("%d", f[0][0]);
  }
  return 0;
}
