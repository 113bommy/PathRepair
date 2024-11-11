#include <bits/stdc++.h>
using namespace std;
const int maxn = 202;
int a[maxn];
int s;
int mi[maxn];
int ma[maxn];
int main() {
  int n, res = -10000, lmi, lma, smi, sma, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      s = smi = sma = lmi = lma = 0;
      for (int i = l; i <= r; i++) {
        s += a[i];
        if (a[i] < 0) mi[lmi++] = a[i];
      }
      for (int i = 0; i < l; i++) ma[lma++] = a[i];
      for (int i = r + 1; i < n; i++) ma[lma++] = a[i];
      sort(mi, mi + lmi);
      sort(ma, ma + lma);
      if (s > res) res = s;
      for (int i = 1; i <= lmi && i <= lma && i <= k; i++) {
        smi += mi[lmi - i];
        sma += ma[lmi - i];
        if (s - smi + sma > res) res = s - smi + sma;
      }
    }
  }
  printf("%d", res);
}
