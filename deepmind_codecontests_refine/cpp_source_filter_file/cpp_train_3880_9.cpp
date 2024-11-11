#include <bits/stdc++.h>
using namespace std;
int count1[12], count2[12], c1[12], c2[12];
char s[100010];
int r1[100010];
int r2[100010];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  memset(count1, 0, sizeof(count1));
  memset(count2, 0, sizeof(count2));
  for (int i = 0; s[i]; i++) {
    count1[s[i] - '0']++;
    count2[s[i] - '0']++;
  }
  int zeros = min(count1[0], count2[0]);
  count1[0] -= zeros;
  count2[0] -= zeros;
  memcpy(c1, count1, sizeof(c1));
  memcpy(c2, count2, sizeof(c2));
  int maior = 0, bestd = -1;
  for (int d = 1; d <= 9; d++)
    if (c1[d] > 0 and c2[10 - d] > 0) {
      memcpy(count1, c1, sizeof(c1));
      memcpy(count2, c2, sizeof(c2));
      int tot = 1;
      count1[d]--;
      count2[10 - d]--;
      for (int i = 0; i <= 9; i++) {
        while (count1[i] > 0 and count2[9 - i] > 0) {
          tot++;
          count1[i]--;
          count2[9 - i]--;
        }
      }
      if (tot > maior) {
        maior = tot;
        bestd = d;
      }
    }
  for (int i = 0; i < zeros; i++) {
    r1[i] = 0;
    r2[i] = 0;
  }
  int t = zeros, j;
  if (zeros == n) goto resp;
  if (bestd == -1) {
    goto sobra;
  } else
    t++;
  memcpy(count1, c1, sizeof(c1));
  memcpy(count2, c2, sizeof(c2));
  r1[zeros] = bestd;
  r2[zeros] = 10 - bestd;
  count1[bestd]--;
  count2[10 - bestd]--;
  for (int i = 0; i <= 9; i++) {
    while (count1[i] > 0 and count2[9 - i] > 0) {
      r1[t] = i;
      r2[t++] = 9 - i;
      count1[i]--;
      count2[9 - i]--;
    }
  }
sobra:;
  j = t;
  for (int i = 0; i <= 9; i++)
    while (count1[i] > 0) {
      r1[j++] = i;
      count1[i]--;
    }
  j = t;
  for (int i = 0; i <= 9; i++)
    while (count2[i] > 0) {
      r2[j++] = i;
      count2[i]--;
    }
resp:;
  for (int i = n - 1; i >= 0; i--) printf("%d", r1[i]);
  printf("\n");
  for (int i = n - 1; i >= 0; i--) printf("%d", r2[i]);
  printf("\n");
  return 0;
}
