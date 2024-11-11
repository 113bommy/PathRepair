#include <bits/stdc++.h>
int len, ans;
char s[1000005];
bool vis[1000005 << 2];
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  int ip = 0;
  for (int i = 0; i < len; i++) {
    vis[ip + 1000005] = 1;
    if (s[i] == 'R') {
      ip++;
      if (ip == x && x != 0) ip--;
    } else {
      ip--;
      if (ip == x && x != 0) ip++;
    }
    if (i == len - 1 && !vis[ip + 1000005]) return 1;
  }
  return 0;
}
void solve2(int l, int r) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  if (check(mid))
    ans = mid, solve2(mid + 1, r);
  else
    solve2(l, mid - 1);
}
void solve1(int l, int r) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  if (check(mid))
    ans = mid, solve1(l, mid - 1);
  else
    solve1(mid + 1, r);
}
int Fabs(int x) { return (x < 0) ? -x : x; }
int main() {
  scanf("%s", s);
  len = strlen(s);
  if (check(0)) return !printf("1");
  if (s[len - 1] == 'R')
    solve1(-1e6, -1);
  else
    solve2(1, 1e6);
  printf("%d\n", Fabs(ans));
  return 0;
}
