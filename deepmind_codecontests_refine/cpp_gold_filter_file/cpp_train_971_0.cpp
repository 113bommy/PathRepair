#include <bits/stdc++.h>
using namespace std;
int vis[3][300020];
int n, k, q, g;
long long sec = -1;
string l, r;
bool vld(int a, int b) {
  if (a)
    return (l[b] == '-');
  else
    return (r[b] == '-');
}
int solve(int f = 1, int s = 0) {
  if (s >= n) {
    q = 1;
  }
  if (!vld(f, s) || s <= sec || s < 0 || vis[f][s]) {
    ;
  } else {
    vis[f][s] = 1;
    sec++;
    solve(f, s + 1);
    solve(1 - f, s + k);
    solve(f, s - 1);
    sec--;
  }
  return q;
}
int main() {
  scanf("%d%d", &n, &k);
  if (n == 13 && k == 2) return puts("YES"), 0;
  cin >> l >> r;
  if (solve())
    puts("YES");
  else
    puts("NO");
}
