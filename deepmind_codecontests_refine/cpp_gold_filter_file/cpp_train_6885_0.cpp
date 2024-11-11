#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int fa[maxn], qe[maxn];
int n, sz[maxn];
void fl() { fflush(stdout); }
void pt(int x) { printf("%d\n", x); }
int yo() {
  fl();
  int x;
  scanf("%d", &x);
  return x;
}
pair<int, int> a[maxn];
int ST[maxn];
set<int> second;
int GAOIT(int L, int R, int owo) {
  pt(R - L + 1);
  for (int i = L; i <= R; i++) pt(ST[i]);
  pt(1);
  pt(1);
  pt(owo);
  fl();
  return yo();
}
int main() {
  n = yo();
  sz[1] = n;
  a[1] = pair<int, int>(n, 1);
  for (int i = 2; i <= n; i++) {
    pt(1);
    pt(1);
    pt(n - 1);
    for (int j = 2; j <= n; j++) {
      pt(j);
    }
    pt(i);
    fl();
    sz[i] = yo();
    a[i] = pair<int, int>(sz[i], i);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int tp = 0;
    for (auto o : second) {
      ST[++tp] = o;
    }
    for (int j = 1; j <= tp;) {
      if (!GAOIT(j, tp, a[i].second)) break;
      int L = j;
      int R = tp;
      int mid, ans = 0;
      while (L <= R) {
        int mid = (L + R) >> 1;
        if (GAOIT(L, mid, a[i].second))
          ans = mid, R = mid - 1;
        else
          L = mid + 1;
      }
      fa[ST[ans]] = a[i].second;
      second.erase(ST[ans]);
      j = ans + 1;
    }
    second.insert(a[i].second);
  }
  puts("ANSWER");
  for (int i = 2; i <= n; i++) {
    printf("%d %d\n", i, fa[i]);
  }
}
