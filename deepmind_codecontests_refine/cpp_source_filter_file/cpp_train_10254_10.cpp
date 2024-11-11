#include <bits/stdc++.h>
using namespace std;
char str1[200004];
char str2[200004];
void norm(char *s, const int &len) {
  if (len & 1) return;
  int mid = len >> 1;
  norm(s, mid);
  norm(s + mid, mid);
  if (strncmp(s, s + mid, mid) == 1) rotate(s, s + mid, s + len);
}
int main() {
  scanf(" %s%s", str1, str2);
  int len = strlen(str1);
  norm(str1, len);
  norm(str2, len);
  if (strcmp(str1, str2) == 0)
    puts("YES");
  else
    puts("NO");
  return 0;
}
