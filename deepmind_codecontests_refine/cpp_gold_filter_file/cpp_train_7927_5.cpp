#include <bits/stdc++.h>
using namespace std;
int pos[2][5555], num[2][5555], val[5555], a[5555], isused[5555], id;
int kk, n;
bool dfs(int now, int type) {
  if (isused[now] == id) return 0;
  isused[now] = id;
  if (val[now] == a[now]) return 1;
  int x = pos[type][val[now] ^ a[now] ^ num[type][now]];
  swap(pos[type][num[type][x]], pos[type][num[type][now]]);
  swap(num[type][x], num[type][now]);
  val[x] = num[0][x] ^ num[1][x], val[now] = a[now];
  if (x > kk) return 1;
  return dfs(x, !type);
}
bool solve() {
  random_shuffle(num[0], num[0] + n), random_shuffle(num[1], num[1] + n);
  for (int i = 0; i < n; i++)
    pos[0][num[0][i]] = pos[1][num[1][i]] = i, val[i] = num[0][i] ^ num[1][i];
  for (int i = 0; i < n - 1; i++) {
    id++, kk = i;
    if (!dfs(i, 0)) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  int k = 0;
  n = 1 << n;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]), k ^= a[i], num[0][i] = num[1][i] = i;
  if (k) {
    printf("Fou\n");
    return 0;
  }
  printf("Shi\n");
  while (!solve())
    ;
  for (int i = 0; i < n; i++) printf("%d ", num[0][i]);
  puts("");
  for (int i = 0; i < n; i++) printf("%d ", num[1][i]);
  puts("");
}
