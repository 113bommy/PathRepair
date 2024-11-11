#include <bits/stdc++.h>
using namespace std;
pair<int, int> f(int a, int q) {
  int ta[4];
  int tq[4];
  for (int i = 0; i < 4; i++) ta[i] = a % 10, a /= 10;
  for (int i = 0; i < 4; i++) tq[i] = q % 10, q /= 10;
  int x = 0, y = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < i; j++)
      if (ta[i] == ta[j]) x = 5;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < i; j++)
      if (tq[i] == tq[j]) x = 5;
  for (int i = 0; i < 4; i++)
    if (tq[i] == ta[i]) x++;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (tq[i] == ta[j] && i != j) y++;
  return make_pair(x, y);
}
int a[10];
pair<int, int> b[10];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i], &b[i].first, &b[i].second);
  int ans = -1;
  for (int an = 0; an < 10000; an++) {
    bool x = true;
    for (int i = 0; i < n; i++)
      if (f(an, a[i]) != b[i]) {
        x = false;
        break;
      }
    if (x && ans != -1) {
      puts("Need more data");
      return 0;
    } else if (x)
      ans = an;
  }
  if (ans == -1)
    puts("Incorrect data");
  else
    printf("%04d\n", ans);
  return 0;
}
