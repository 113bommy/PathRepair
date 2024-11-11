#include <bits/stdc++.h>
char buf[100002];
int levels = 0;
int level(long long n) { return __builtin_ctzll(n); }
int main() {
  long long N;
  int Q;
  scanf("%I64d%d", &N, &Q);
  while (((N + 1) % (1LL << levels)) == 0) levels++;
  levels--;
  for (int i = 0; i < Q; i++) {
    long long S;
    scanf("%I64d %s", &S, buf);
    int p = 0;
    while (buf[p] != '\0') {
      int lev = level(S);
      long long step = 1LL << lev;
      if (buf[p] == 'U' && lev < levels - 1) {
        if (S - step > 0 && S - step <= N)
          S = (level(S - step) > level(S + step)) ? S + step : S - step;
        else if (S - step > 0)
          S -= step;
        else
          S += step;
        lev++;
      } else if (buf[p] == 'L' && lev > 0 && S - step / 2 > 0)
        S -= step / 2, lev--;
      else if (buf[p] == 'R' && lev > 0 && S + step / 2 <= N)
        S += step / 2, lev--;
      p++;
    }
    printf("%I64d\n", S);
  }
}
