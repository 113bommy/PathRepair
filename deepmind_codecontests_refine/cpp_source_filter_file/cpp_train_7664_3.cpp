#include <bits/stdc++.h>
using namespace std;
char buf[10010];
string s;
int n;
int num[110], cnt[110];
char lis[25][110][110];
char name[110][110];
bool check(char *a, char *b) {
  int len1 = strlen(a);
  int len2 = strlen(b);
  if (len1 < len2) return 0;
  for (int i = 1; i <= len2; i++) {
    if (a[len1 - i] != b[len2 - i]) return 0;
  }
  return 1;
}
void debug() {
  for (int i = 1; i <= n; i++) {
    printf("%s %d\n", name[i], num[i]);
    for (int j = 1; j <= num[i]; j++) printf("%s ", lis[i][j]);
    printf("\n");
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf(" %s", &name[i]);
    scanf("%d", &num[i]);
    for (int j = 1; j <= num[i]; j++) scanf(" %s", lis[i][j]);
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (num[j] && !strcmp(name[i], name[j])) {
        for (int k = 1; k <= num[j]; k++) strcpy(lis[i][k + num[i]], lis[j][k]);
        num[i] += num[j];
        num[j] = 0;
      }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (num[i]) {
      ans++;
      cnt[i] = num[i];
      for (int k = 1; k <= num[i]; k++)
        for (int l = k + 1; l <= num[i]; l++) {
          if (lis[i][k][0] == 0 || lis[i][l][0] == 0) continue;
          if (check(lis[i][k], lis[i][l])) {
            lis[i][l][0] = 0;
            cnt[i]--;
            continue;
          }
          if (check(lis[i][l], lis[i][k])) {
            lis[i][k][0] = 0;
            cnt[i]--;
            continue;
          }
        }
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (num[i] && !strcmp(name[i], "i")) {
      printf("%s %d", name[i], cnt[i]);
      for (int j = 1; j <= num[i]; j++)
        if (lis[i][j][0] != 0) printf(" %s", lis[i][j]);
      printf("\n");
    }
  for (int i = 1; i <= n; i++)
    if (num[i] && strcmp(name[i], "i")) {
      printf("%s %d", name[i], cnt[i]);
      for (int j = 1; j <= num[i]; j++)
        if (lis[i][j][0] != 0) printf(" %s", lis[i][j]);
      printf("\n");
    }
  return 0;
}
