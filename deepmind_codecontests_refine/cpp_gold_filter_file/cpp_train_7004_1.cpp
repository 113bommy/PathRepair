#include <bits/stdc++.h>
int seq[200200];
int pos[200200];
int seqk[200200];
int ord[200200];
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &seq[i]);
      pos[seq[i]] = i;
      ord[i + 1] = 0;
    };
    for (int i = 0; i < k; i++) {
      scanf("%d", &seqk[i]);
      ord[seqk[i]] = i + 1;
    };
    long long erg = 1;
    for (int i = 0; i < k; i++) {
      long long mul = 0;
      if (pos[seqk[i]] > 0) {
        if (ord[seq[pos[seqk[i]] - 1]] <= i) mul++;
      };
      if (pos[seqk[i]] < n - 1) {
        if (ord[seq[pos[seqk[i]] + 1]] <= i) mul++;
      };
      erg *= mul;
      erg %= 998244353ll;
    };
    printf("%lld\n", erg);
  };
  return 0;
};
