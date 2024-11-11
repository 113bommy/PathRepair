#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int a[maxn];
int l, r;
int n;
inline void prework() {
  int i = 1;
  while (a[i + 1] > a[i]) i++;
  l = i;
  i = n;
  while (a[i - 1] > a[i]) i--;
  r = i;
}
bool solve(int i, int j, int player) {
  if (a[i] == a[j]) {
    if ((l - i + 1) & 1)
      return player;
    else if ((j - r + 1) & 1)
      return player;
    else
      return player ^ 1;
  } else if (a[i] > a[j]) {
    if ((l - i + 1) & 1)
      return player;
    else
      return solve(i, j - 1, player ^ 1);
  } else if (a[i] < a[j]) {
    if ((j - r + 1) & 1)
      return player;
    else
      return solve(i + 1, j, player ^ 1);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  prework();
  if (solve(1, n, 1))
    printf("Alice\n");
  else
    printf("BOb\n");
  return 0;
}
