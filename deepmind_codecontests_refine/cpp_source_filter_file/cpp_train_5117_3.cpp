#include <bits/stdc++.h>
using namespace std;
char zhi[] = "AEFHIJKLMNTVWXYZ";
int inzhi(char a) {
  int l = strlen(zhi);
  for (int i = 0; i < l; i++) {
    if (a == zhi[i]) {
      return 1;
    }
  }
  return 0;
}
char s[1100];
int main() {
  scanf("%s", s);
  int l = strlen(s);
  int gao1 = 0;
  int gao2 = 0;
  for (int i = 0; i < l; i++) {
    s[i] = (inzhi(s[i]));
    if (s[i] == 1) gao1 = 1;
    if (s[i] == 0) gao2 = 1;
  }
  if (gao1 == 1 && gao2 == 1)
    printf("NO");
  else
    printf("YES");
  return 0;
}
