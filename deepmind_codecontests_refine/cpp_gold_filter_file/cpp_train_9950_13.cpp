#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int N, M;
char S[MAXN], T[MAXN];
int fwd[MAXN], rev[MAXN];
int main() {
  scanf("%s %s", S + 1, T + 1);
  N = strlen(S + 1);
  M = strlen(T + 1);
  for (int i = 1, cura = 0; i <= M; i++) {
    while (cura <= N && S[cura] != T[i]) {
      cura++;
    }
    fwd[i] = cura;
    cura = min(N, cura) + 1;
  }
  rev[M + 1] = N + 1;
  for (int i = M, cura = N; i >= 1; i--) {
    while (cura && S[cura] != T[i]) {
      cura--;
    }
    rev[i] = cura;
    cura = max(1, cura) - 1;
  }
  pair<int, int> mx(0, 0);
  for (int i = 0, j = 1; i <= M; i++) {
    if (fwd[i] == N + 1) {
      break;
    }
    while (j <= M && (i >= j || fwd[i] >= rev[j])) {
      j++;
    }
    mx = max(mx, make_pair(M + 1 - j + i, i));
  }
  bool pr = false;
  for (int i = 1; i <= mx.second; i++) {
    pr = true;
    putchar(T[i]);
  }
  for (int i = (M + 1) - (mx.first - mx.second); i <= M; i++) {
    pr = true;
    putchar(T[i]);
  }
  if (!pr) {
    putchar('-');
  }
  puts("");
}
