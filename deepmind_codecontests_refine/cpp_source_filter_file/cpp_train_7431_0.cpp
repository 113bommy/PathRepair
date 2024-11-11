#include <bits/stdc++.h>
using namespace std;
char a[1005], b[1005];
int main() {
  int s1 = 0, s2 = 0;
  scanf("%s %s", &a, &b);
  int len1 = strlen(a);
  int len2 = strlen(b);
  for (int i = 0; i < len1; i++)
    if (a[i] - '1') s1++;
  for (int i = 0; i < len2; i++)
    if (b[i] - '1') s2++;
  if (s1 & 1) s1++;
  if (s1 >= s2)
    puts("YES");
  else
    puts("NO");
}
