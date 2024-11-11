#include <bits/stdc++.h>
const int inf = (1ll << 31) - 1;
const int maxn = (int)1e5 + 10;
using namespace std;
int n;
int c[100100];
long long cur[100100];
int v[100100];
int q;
long long con = -1000000000000000ll;
int main() {
  scanf("%d %d\n", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    c[i]--;
  }
  while (q--) {
    int a, b;
    scanf("%d %d\n", &a, &b);
    long long ans1 = con, ans2 = con, ans = 0;
    int c1 = -1, c2 = -1;
    for (int i = 0; i < n; i++) {
      cur[i] = con;
    }
    for (int i = 0; i < n; i++) {
      long long anscur = cur[c[i]] + v[i] * 1ll * a;
      anscur = max(anscur, b * 1ll * v[i]);
      if (c[i] != c1) {
        anscur = max(anscur, ans1 + b * 1ll * v[i]);
      }
      if (c[i] != c2) {
        anscur = max(anscur, ans2 + b * 1ll * v[i]);
      }
      if (c1 == c[i]) {
        ans1 = max(anscur, ans1);
      } else if (c2 == c[i]) {
        ans2 = max(anscur, ans2);
      } else if (ans1 < anscur) {
        ans2 = ans1;
        c2 = c1;
        ans1 = ans2;
        c1 = c[i];
      } else if (ans2 < anscur) {
        ans2 = anscur;
        c2 = c[i];
      }
      if (ans1 < ans2) {
        swap(ans1, ans2);
        swap(c1, c2);
      }
      cur[c[i]] = max(cur[c[i]], anscur);
    }
    for (int i = 0; i < n; i++) ans = max(ans, cur[c[i]]);
    ans = max(ans1, ans);
    ans = max(ans2, ans);
    printf("%I64d\n", ans);
  }
  return 0;
}
