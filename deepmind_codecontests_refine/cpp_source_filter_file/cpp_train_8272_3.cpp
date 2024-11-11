#include <bits/stdc++.h>
using namespace std;
void buildZ(char *P, int L, int *Z) {
  int l = 0, r = 0;
  Z[0] = L;
  for (int i = (1); i <= (L - 1); i++) {
    if (i > r) {
      l = r = i;
      while (r < L && P[r - l] == P[r]) r++;
      Z[i] = r - l;
      r--;
    } else {
      int k = i - l;
      if (Z[k] < r - i + 1)
        Z[i] = Z[k];
      else {
        l = i;
        while (r < L && P[r - l] == P[r]) r++;
        Z[i] = r - l;
        r--;
      }
    }
  }
}
const int MAX = 1 << 20;
int Z[MAX], n, k;
int valid[MAX];
int info[MAX];
char P[MAX];
int main() {
  scanf("%d %d %s", &n, &k, P);
  buildZ(P, n, Z + 1);
  int cur = 0;
  for (int i = (1); i <= (n); i++) {
    cur += info[i];
    valid[i] |= cur > 0;
    if (i % k) continue;
    int l = i / k, c = 1;
    for (int j = 1; j <= i; j += l) c &= Z[j] >= l;
    valid[i] = 1;
    if (c && i != n && Z[i + 1]) {
      info[i + 1]++;
      info[i + 1 + min(Z[i + 1], l)]--;
    }
  }
  for (int i = (1); i <= (n); i++) printf("%d", valid[i]);
  puts("");
  return 0;
}
