#include <bits/stdc++.h>
using namespace std;
int N, M;
int val[5050], tmp[5050];
char ar1[5050], ar2[5050], ar3[5050];
bool f(int m) {
  int i, j;
  for (i = 0; i < 26; i++) tmp[i] = val[i];
  for (i = 1; i <= m; i++) {
    tmp[ar2[i] - 'a']--;
    ar3[i] = ar2[i];
  }
  for (i = (m == M ? 0 : ar2[m + 1] - 'a' + 1); i < 26; i++)
    if (tmp[i]) {
      tmp[i]--;
      ar3[m + 1] = i + 'a';
      break;
    }
  if (i > 25) return 0;
  return 1;
}
void ctrl() {
  int i, j;
  for (i = 1; i <= M; i++) {
    for (j = ar2[i] - 'a' + 1; j < 26; j++)
      if (tmp[j]) return;
    if (tmp[ar2[i] - 'a']) {
      tmp[ar2[i] - 'a']--;
      continue;
    }
    printf("-1\n");
    exit(0);
  }
  if (M >= N) {
    printf("-1\n");
    exit(0);
  }
}
int main() {
  int i, j;
  scanf(" %s %s", ar1 + 1, ar2 + 1);
  N = strlen(ar1 + 1);
  M = strlen(ar2 + 1);
  for (i = 1; i <= N; i++) val[ar1[i] - 'a']++;
  for (i = 0; i < 26; i++) tmp[i] = val[i];
  ctrl();
  for (i = 0; i < 26; i++) tmp[i] = val[i];
  for (i = 1; i <= min(N, M); i++)
    if (tmp[ar2[i] - 'a'])
      tmp[ar2[i] - 'a']--;
    else
      break;
  i--;
  for (; i >= 0; i--)
    if (f(i)) break;
  for (i += 2; i <= N; i++)
    for (j = 0; j < 25; j++)
      if (tmp[j]) {
        tmp[j]--;
        ar3[i] = j + 'a';
        break;
      }
  for (i = 1; i <= N; i++) printf("%c", ar3[i]);
  printf("\n");
  return 0;
}
