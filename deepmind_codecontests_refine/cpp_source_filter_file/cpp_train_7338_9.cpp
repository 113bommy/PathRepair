#include <bits/stdc++.h>
using namespace std;
char x[300005];
int n, m;
int qian(int pp) {
  if (pp == 0) return 0;
  if (x[pp - 1] == '.')
    return 1;
  else
    return 0;
}
int hou(int pp) {
  if (pp == n - 1) return 0;
  if (x[pp + 1] == '.')
    return 1;
  else
    return 0;
}
int main(void) {
  scanf("%d%d\n", &n, &m);
  scanf("%s", x);
  int kaishi = 0;
  int changdu = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] == '.' && kaishi == 0) {
      kaishi = 1;
      changdu++;
    } else if (x[i] == '.') {
      changdu++;
    } else if (x[i] != '.' && kaishi == 1) {
      sum = sum + changdu - 1;
      kaishi = 0;
      changdu = 0;
    }
  }
  if (kaishi == 1) sum = sum + changdu - 1;
  for (int i = 1; i <= n; i++) {
    int a;
    char c;
    scanf("%d %c", &a, &c);
    if (c == '.' && x[a - 1] == '.')
      printf("%d\n", sum);
    else if (c != '.' && x[a - 1] != '.')
      printf("%d\n", sum);
    else if (c == '.' && x[a - 1] != '.') {
      sum = sum + qian(a - 1) + hou(a - 1);
      x[a - 1] = c;
      printf("%d\n", sum);
    } else if (c != '.' && x[a - 1] == '.') {
      sum = sum - qian(a - 1) - hou(a - 1);
      x[a - 1] = c;
      printf("%d\n", sum);
    }
  }
  return 0;
}
