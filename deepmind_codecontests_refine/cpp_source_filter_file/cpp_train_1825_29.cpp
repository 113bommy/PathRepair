#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
long long tl[maxn], tc[maxn], sl[maxn], sc[maxn], fi[maxn];
void get_fi(int m) {
  fi[1] = fi[2] = 1;
  for (int i = 2; i < m; i++) {
    int j = fi[i];
    while (j > 1 && (sc[j] != sc[i] || sl[j] != sl[i])) j = fi[j];
    fi[i + 1] = (sc[j] == sc[i] && sl[j] == sl[i] ? j + 1 : 1);
  }
}
int main() {
  int N, M, a, n = 0, m = 0;
  long long ans = 0;
  char b;
  scanf("%d %d", &N, &M);
  while (N--) {
    scanf("%d-%c", &a, &b);
    if (n && b == tc[n - 1] + 'a')
      tl[n - 1] += a;
    else
      tc[n] = b - 'a', tl[n++] = a;
  }
  while (M--) {
    scanf("%d-%c", &a, &b);
    if (m && b == sc[m - 1] + 'a')
      sl[m - 1] += a;
    else
      sc[m] = b - 'a', sl[m++] = a;
  }
  if (m == 1) {
    for (int i = 0; i < n; i++)
      if (sc[0] == tc[i]) ans += max(0ll, tl[i] - sl[0] + 1);
  } else {
    int j = 1;
    get_fi(m);
    for (int i = 1; i < n - 1; i++) {
      while (j > 1 && (tc[i] != sc[j] || tl[i] != sl[j])) j = fi[j];
      if (tc[i] == sc[j] && tl[i] == sl[j]) j++;
      if (j == m - 1) {
        if ((sc[m - 1] == tc[i + 1] && sl[m - 1] <= tl[i + 1]) &&
            (sc[0] == tc[i + 2 - m] && sl[0] <= tl[i + 2 - m]))
          ans++;
        j = fi[j];
      }
    }
  }
  printf("%lld\n", ans);
}
