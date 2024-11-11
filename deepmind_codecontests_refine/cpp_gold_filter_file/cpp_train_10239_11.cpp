#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn], b[maxn], Left[maxn], Right[maxn], bestP[maxn], bestQ[maxn],
    bestF[maxn], bestG[maxn];
long long sa[maxn], sb[maxn];
int main() {
  int n;
  scanf("%d", &n);
  n--;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] & 1) {
      sa[i] = sa[i - 1] + a[i];
      sb[i] = sb[i - 1] + (a[i] - 1);
    } else {
      sa[i] = sa[i - 1] + (a[i] - 1);
      sb[i] = sb[i - 1] + a[i];
    }
  }
  int p = 1, q = n;
  int f = 0, sf = 0, g = n + 1, sg = n + 1;
  long long LeftMax = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (sa[n] - sa[i - 1] + (sb[i - 1] - sb[f]) > LeftMax) {
      LeftMax = sa[n] - sa[i - 1] + (sb[i - 1] - sb[f]);
      p = i;
      sf = f;
    }
    bestP[i] = p;
    bestF[i] = sf;
    if (a[i] == 1) f = i;
  }
  long long RightMax = 0;
  for (int i = n; i >= 0; i--) {
    if (sa[i] + sb[g - 1] - sb[i] > RightMax) {
      RightMax = sa[i] + sb[g - 1] - sb[i];
      q = i;
      sg = g;
    }
    bestQ[i] = q;
    bestG[i] = sg;
    if (a[i] == 1) g = i;
  }
  long long ans = 0;
  for (int i = 1; i <= n + 1; i++) {
    int tp = bestP[i];
    int tq = bestQ[i - 1];
    int tf = bestF[i];
    int tg = bestG[i - 1];
    ans = max(ans,
              sa[tq] - sa[tp - 1] + sb[tp - 1] - sb[tf] + sb[tg - 1] - sb[tq]);
  }
  printf("%I64d\n", ans);
  return 0;
}
