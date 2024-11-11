#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
int an[410000];
int wz[410000];
int jl[410000];
int ans[410000];
int main() {
  int z;
  int n, m;
  int i, j, k;
  int l, r;
  int u, v, w;
  int a, b, c, d;
  int x, y;
  int t, tmp;
  cin >> z;
  while (z--) {
    scanf("%d", &n);
    int mi = 0x1f1f1f1f;
    for (i = 0; i < n; i++) {
      scanf("%d", &an[i]);
      mi = min(mi, an[i]);
    }
    memset(wz, -1, n * 4);
    memset(jl, 0, n * 4 + 4);
    memset(ans, 0x1f1f1f1f, n * 4 + 4);
    for (i = 0; i < n; i++) {
      { jl[an[i]] = max(jl[an[i]], i - wz[an[i]]); }
      wz[an[i]] = i;
    }
    for (i = 0; i < n; i++) {
      jl[an[i]] = max(jl[an[i]], n - wz[an[i]]);
    }
    for (i = 0; i < n; i++) {
      if (ans[jl[an[i]]] > an[i]) ans[jl[an[i]]] = an[i];
    }
    ans[n] = mi;
    int tmp = -1;
    for (i = 1; i <= n; i++) {
      if (ans[i] == 0x1f1f1f1f) {
        printf("%d ", tmp);
      } else {
        if (tmp == -1)
          tmp = ans[i];
        else if (ans[i] < tmp) {
          tmp = ans[i];
        }
        printf("%d ", tmp);
      }
    }
    puts("");
  }
  return 0;
}
