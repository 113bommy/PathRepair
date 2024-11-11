#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000;
const int MAX_M = 1000000;
const int BN = 20;
int cs[BN], bs[MAX_M], ds[BN];
bool check(int k) {
  memcpy(ds, cs, sizeof(cs));
  for (int i = k - 1; i >= 0; i--) {
    int bi = bs[i], j = bi;
    for (; j < BN; j++) {
      if (ds[j]) {
        ds[j]--;
        break;
      } else
        ds[j]++;
    }
    if (j >= BN) return false;
  }
  return true;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    for (int j = 0, bj = 1; j < BN; j++, bj <<= 1)
      if (ai & bj) cs[j]++;
  }
  for (int i = 0; i < m; i++) scanf("%d", bs + i);
  sort(bs, bs + m);
  int k0 = 0, k1 = m + 1;
  while (k0 + 1 < k1) {
    int k = (k0 + k1) / 2;
    if (check(k))
      k0 = k;
    else
      k1 = k;
  }
  printf("%d\n", k0);
  return 0;
}
