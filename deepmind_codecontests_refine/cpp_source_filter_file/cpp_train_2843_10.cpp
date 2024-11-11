#include <bits/stdc++.h>
using namespace std;
char T[100 * 1000 + 1], P[100][1000 + 1];
int n, L, len[100], pf[100][1000];
int mx[100][100 * 1000], soFar[100];
int can[100];
int GetLen(char c, int l, char *P, int *pf) {
  while (l && P[l] != c) l = pf[l - 1];
  if (P[l] == c) l++;
  return l;
}
void BuildFailure(char *P, int *pf) {
  pf[0] = 0;
  for (int i = 1; P[i]; i++) pf[i] = GetLen(P[i], pf[i - 1], P, pf);
}
int main() {
  scanf("%s %d", T, &n);
  L = strlen(T);
  for (int i = 0; i < (n); i++) {
    scanf("%s", P[i]);
    len[i] = strlen(P[i]);
    BuildFailure(P[i], pf[i]);
  }
  for (int i = 0; i < (L); i++) {
    for (int j = 0; j < (n); j++) {
      soFar[j] = GetLen(T[i], soFar[j], P[j], pf[j]);
      mx[j][i + 1] = max(soFar[j], mx[j][i]);
    }
  }
  memset(pf, 0, sizeof pf);
  memset(soFar, 0, sizeof soFar);
  for (int i = 0; i < (n); i++) {
    reverse(P[i], P[i] + len[i]);
    BuildFailure(P[i], pf[i]);
  }
  for (int i = L - 1; i >= 0; i--) {
    for (int j = 0; j < (n); j++) {
      soFar[j] = GetLen(T[i], soFar[j], P[j], pf[j]);
      if (mx[j][i] >= len[j] - soFar[j] && soFar[j] && len[j] - soFar[j]) {
        can[j] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < (n); i++) ans += can[i];
  cout << ans << endl;
  return 0;
}
