#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
char s[N];
int n, vis[N], V, sg[N];
int a[N], m, l[N], r[N], sv[N], svt;
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (n == 1) {
    printf("Second\n");
    return 0;
  }
  sg[1] = 1;
  for (int i = 2; i <= n; ++i) {
    ++V;
    vis[sg[i - 2]] = V;
    for (int j = 2; j <= i - 1; ++j)
      vis[min(sg[j - 2] ^ sg[i - (j + 1)], n + 1)] = V;
    int x = 0;
    while (vis[x] == V) ++x;
    sg[i] = x;
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = (s[i - 1] == s[i + 1]);
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] && !a[i - 1]) l[++m] = i;
    if (a[i] && !a[i + 1]) r[m] = i;
  }
  int tot = 0;
  for (int i = 1; i <= m; ++i) {
    tot ^= sg[r[i] - l[i] + 1];
  }
  for (int i = 1; i <= m; ++i) {
    int cur = tot ^ sg[r[i] - l[i] + 1], tz;
    if (l[i] == r[i]) {
      if (!cur) sv[++svt] = l[i];
    } else {
      for (int j = l[i]; j <= r[i]; ++j) {
        if (j == l[i] || j == r[i])
          tz = sg[r[i] - l[i] - 1];
        else
          tz = sg[(j - 1) - l[i]] ^ sg[r[i] - (j + 1)];
        if ((cur ^ tz) == 0) sv[++svt] = j;
      }
    }
  }
  if (svt) {
    printf("First\n%d\n", sv[1]);
  } else {
    printf("Second\n");
  }
}
