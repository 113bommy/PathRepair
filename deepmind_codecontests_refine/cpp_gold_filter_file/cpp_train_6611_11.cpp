#include <bits/stdc++.h>
using namespace std;
int f[(int)1e6];
int b[(int)1e6];
int freqF[(int)1e6];
int freqB[(int)1e6];
int idx[(int)1e6];
int main(void) {
  int m, n;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &f[i]);
    idx[f[i]] = i + 1;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  memset(freqF, 0, sizeof freqF);
  memset(freqB, 0, sizeof freqB);
  bool imp = false, amb = false;
  for (int i = 0; i < n; ++i) {
    ++freqF[f[i]];
  }
  for (int i = 0; i < m; ++i) {
    ++freqB[b[i]];
  }
  for (int i = 0; i < m; ++i) {
    if (freqF[b[i]] == 0) {
      imp = true;
    }
    if (freqF[b[i]] > 1) {
      amb = true;
    }
  }
  if (imp) {
    puts("Impossible");
  } else if (amb) {
    puts("Ambiguity");
  } else {
    puts("Possible");
    for (int i = 0; i < m; ++i) printf("%s%d", i ? " " : "", idx[b[i]]);
    putchar('\n');
  }
}
