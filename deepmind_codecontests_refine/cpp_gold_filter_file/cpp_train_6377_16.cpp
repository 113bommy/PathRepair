#include <bits/stdc++.h>
const int N = 200100;
int a[N], b[N], i, l;
char s[N];
int max(int c, int d) {
  if (c > d)
    return c;
  else
    return d;
}
bool judge(char z) {
  char x;
  x = tolower(z);
  if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;
  return false;
}
int main() {
  scanf("%s", &s);
  l = strlen(s);
  for (i = 0; i < l; ++i)
    if (judge(s[i]))
      a[i + 1] = a[i] + 1;
    else
      a[i + 1] = a[i] - 2;
  int ans = 0, tmp = 0;
  for (i = 0; i < l + 1; ++i) {
    if (a[i] > tmp) {
      tmp = a[i];
      b[tmp] = i;
    }
  }
  for (i = 0; i < l + 1; ++i)
    if (a[i] <= 0)
      ans = i;
    else
      ans = max(ans, i - b[a[i]]);
  int num = 0;
  for (i = 0; i < l + 1 - ans; ++i)
    if (a[i + ans] <= a[i]) num++;
  if (ans != 0)
    printf("%d %d\n", ans, num);
  else
    printf("No solution\n");
  return 0;
}
