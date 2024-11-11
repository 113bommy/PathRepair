#include <bits/stdc++.h>
using namespace std;
int n;
char s[200001];
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  int i = -1;
  while ((i < n - 1) && (s[i + 1] == '<')) i++;
  int j = n;
  while ((j > 1) && (s[j - 1] == '>')) j--;
  int ans = 0;
  if (i >= 0) ans += i + 1;
  if (j < n) ans += n - j + 1;
  printf("%d\n", ans);
  return 0;
}
