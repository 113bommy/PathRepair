#include <bits/stdc++.h>
static const int t[5][2] = {{3, 3}, {4, 6}, {5, 9}, {7, 7}, {8, 0}};
bool check(int x, int y) {
  for (int i = 0; i != 5; ++i)
    if (t[i][0] == x || t[i][1] == y) return true;
  return false;
}
int main(int argc, char* argv[]) {
  char s[1024] = {};
  scanf("%s", s);
  int n = 0;
  while (s[n] != '\0') ++n;
  for (int i = 0; i != n; ++i) {
    const int x = int(s[i] - '0');
    const int y = int(s[n - 1 - i] - '0');
    if (check(x, y) || check(y, x)) continue;
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  return 0;
}
