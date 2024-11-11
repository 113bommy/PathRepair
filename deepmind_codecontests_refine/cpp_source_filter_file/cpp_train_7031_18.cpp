#include <bits/stdc++.h>
using namespace std;
int m = 1000, t, a, b;
void init() {
  for (int i = 0; i < 4; i++) {
    scanf("%d", &t);
    m = min(m, t);
  }
  scanf("%d%d", &a, &b);
  if (m < a)
    puts("0");
  else if (m < b)
    printf("%d\n", m - a);
  else
    printf("%d\n", b - a);
}
void fread() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int main() {
  init();
  return 0;
}
