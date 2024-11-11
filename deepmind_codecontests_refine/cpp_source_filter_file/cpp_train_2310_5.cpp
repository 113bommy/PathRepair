#include <bits/stdc++.h>
using namespace std;
int n, id;
char s[500005], Min;
int l[500005];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  l[1] = 1, Min = s[1], id = 1;
  ;
  for (int i = 2; i <= n; i++) {
    if (s[i] <= s[1]) Min = s[i], id = i;
    l[i] = id;
  }
  for (int i = 1; i <= n; i++) {
    if (l[i] == i)
      printf("Mike\n");
    else
      printf("Ann\n");
  }
  return 0;
}
