#include <bits/stdc++.h>
using namespace std;
char wo[50000][5];
char s[50000];
int poss[50000][3];
map<string, int> mp;
int ID[50000];
bool cmp(int t, int k) {
  if (strcmp(wo[t], wo[k]) < 0) return true;
  return false;
}
int main() {
  int N, ct;
  char str[6];
  scanf("%s", s);
  N = strlen(s);
  memset(poss, 0, sizeof(poss));
  if (N > 6) poss[N - 1][0] = 1;
  if (N > 7) poss[N - 1][1] = 1;
  for (int i = N - 2; i > 5; i--) {
    if (s[i - 1] != s[i + 1] || s[i] != s[i + 2]) {
      if (poss[i + 2][0]) poss[i][0] = 1;
    }
    if (poss[i + 3][1]) poss[i][0] = 1;
    if (poss[i + 2][0]) poss[i][1] = 1;
    if (s[i - 2] != s[i + 1] || s[i - 1] != s[i + 2] || s[i] != s[i + 3]) {
      if (poss[i + 3][1]) poss[i][3] = 1;
    }
  }
  mp.clear();
  ct = 0;
  for (int i = (6); i < (N); i++) {
    str[0] = s[i - 1];
    str[1] = s[i];
    str[2] = 0;
    if (poss[i][0]) {
      if (!mp.count(str)) {
        mp[str] = ct;
        strcpy(wo[ct++], str);
      }
    }
    if (i > 6) {
      str[0] = s[i - 2];
      str[1] = s[i - 1];
      str[2] = s[i];
      str[3] = 0;
      if (poss[i][1]) {
        if (!mp.count(str)) {
          mp[str] = ct;
          strcpy(wo[ct++], str);
        }
      }
    }
  }
  for (int i = (0); i < (ct); i++) ID[i] = i;
  sort(ID, ID + ct, cmp);
  printf("%d\n", ct);
  for (int i = (0); i < (ct); i++) printf("%s\n", wo[ID[i]]);
  return 0;
}
