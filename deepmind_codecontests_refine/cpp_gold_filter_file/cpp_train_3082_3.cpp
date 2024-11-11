#include <bits/stdc++.h>
using namespace std;
int a, b, l, r;
bool life[30];
int num[60];
int go(int x1, int x2) {
  int now, x;
  memset(life, 0, sizeof(life));
  for (int i = 1; i <= a; i++) num[i] = i;
  for (int i = 1; i <= b; i++) {
    num[i + a] = x1;
    num[i + a * 2 + b] = x2;
  }
  for (int i = b + 1; i <= a + b; i++) life[num[i]] = 1;
  now = 1;
  for (int i = a + b + 1; i <= a * 2 + b; i++) {
    while (life[now]) now++;
    num[i] = now;
    now++;
  }
  now = 0;
  memset(life, 0, sizeof(life));
  for (int i = l; i <= r; i++) {
    x = i % (2 * a + 2 * b);
    if (x == 0) x = 2 * a + 2 * b;
    if (life[num[x]] == 0) {
      now++;
      life[num[x]] = 1;
    }
  }
  return now;
}
int main() {
  int ans;
  scanf("%d%d%d%d", &a, &b, &l, &r);
  if (r - l + 1 >= 2 * a + 2 * b) {
    if (b >= a)
      ans = a + 1;
    else
      ans = 2 * a - b;
  } else {
    l = l % (2 * a + 2 * b);
    if (l == 0) l = 2 * a + 2 * b;
    r = r % (2 * a + 2 * b);
    if (r < l) r += 2 * a + 2 * b;
    ans = 26;
    for (int i = 1; i <= 26; i++)
      for (int j = a + 1; j <= 26; j++) ans = min(ans, go(i, j));
  }
  printf("%d\n", ans);
  return 0;
}
