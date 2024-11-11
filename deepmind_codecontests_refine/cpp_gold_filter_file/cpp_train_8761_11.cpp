#include <bits/stdc++.h>
using namespace std;
const int MN = 100005, inf = 1000000005, mod = 1000000007;
const long long INF = 1000000000000000005LL;
char S[MN];
int suma[MN];
int piep[MN][2], ostp[MN][2], pies[MN][2], osts[MN][2];
void pie() {
  printf("tokitsukaze");
  exit(0);
}
void dru() {
  printf("quailty");
  exit(0);
}
void rr() {
  printf("once again");
  exit(0);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", S + 1);
  for (int j = 0; j < 2; ++j) {
    piep[0][j] = inf;
    ostp[0][j] = -inf;
  }
  for (int i = 1; i <= n; ++i) {
    suma[i] = suma[i - 1] + (S[i] == '1');
    for (int j = 0; j < 2; ++j) {
      piep[i][j] = piep[i - 1][j];
      ostp[i][j] = ostp[i - 1][j];
      if (S[i] - '0' == j) {
        piep[i][j] = min(piep[i][j], i);
        ostp[i][j] = i;
      }
    }
  }
  for (int j = 0; j < 2; ++j) {
    pies[n + 1][j] = inf;
    osts[n + 1][j] = -inf;
  }
  for (int i = n; i > 0; --i) {
    for (int j = 0; j < 2; ++j) {
      pies[i][j] = pies[i + 1][j];
      osts[i][j] = osts[i + 1][j];
      if (S[i] - '0' == j) {
        pies[i][j] = i;
        osts[i][j] = max(osts[i][j], i);
      }
    }
  }
  int p0, o0, p1, o1, rem = 0;
  for (int i = 1; i <= n - k + 1; ++i) {
    int s = suma[i - 1] + suma[n] - suma[i + k - 1];
    if (s + k == n || !s) pie();
    p0 = min(piep[i - 1][0], pies[i + k][0]);
    o0 = max(ostp[i - 1][0], osts[i + k][0]);
    p1 = min(piep[i - 1][1], pies[i + k][1]);
    o1 = max(ostp[i - 1][1], osts[i + k][1]);
    if (min(o1 - p1, max(o0, i + k - 1) - min(i, p0)) >= k) rem = 1;
    if (min(max(o1, i + k - 1) - min(i, p1), o0 - p0) >= k) rem = 1;
  }
  if (rem) rr();
  dru();
}
