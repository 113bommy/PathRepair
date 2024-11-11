#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
int sc[maxn], sl[maxn], tc[maxn], tl[maxn], fi[maxn];
int main() {
  int N, M, n = 0, m = 0;
  long long ans = 0;
  int a;
  char b;
  scanf("%d%d", &N, &M);
  while (N--) {
    scanf("%d-%c", &a, &b);
    if (n && b == sc[n - 1] + 'a')
      sl[n - 1] += a;
    else
      sc[n] = b - 'a', sl[n++] = a;
  }
  while (M--) {
    scanf("%d-%c", &a, &b);
    if (m && b == tc[m - 1] + 'a')
      tl[m - 1] += a;
    else
      tc[m] = b - 'a', tl[m++] = a;
  }
  if (m == 1) {
    for (int i = 0; i < n; i++)
      if (tc[0] == sc[i]) ans += max(0LL, sl[i] - tl[0] + 1LL);
  } else {
    fi[1] = fi[2] = 1;
    for (int i = 2; i < m; i++) {
      int j = fi[i];
      while (j > 1 && (tc[i] != tc[j] || tl[i] != tl[j])) j = fi[j];
      fi[i + 1] = (tc[i] == tc[j] && tl[i] == tl[j] ? j + 1 : 1);
    }
    int j = 1;
    for (int i = 0; i < n - 1; i++) {
      while (j > 1 && (tc[j] != sc[i] || sl[i] != tl[j])) j = fi[j];
      if (tc[j] == sc[i] && tl[j] == sl[i]) j++;
      if (j == m - 1) {
        if ((tc[0] == sc[i + 2 - m] && tl[0] <= sl[i + 2 - m]) &&
            (tc[m - 1] == sc[i + 1] && tl[m - 1] <= sl[i + 1]))
          ans++;
        j = fi[j];
      }
    }
  }
  printf("%lld\n", ans);
}
