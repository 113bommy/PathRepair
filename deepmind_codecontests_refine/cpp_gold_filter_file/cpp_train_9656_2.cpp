#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > final;
void move(int a, int b, int cnt) {
  for (int _ = (1); _ <= (cnt); _++) final.push_back(make_pair(a, b));
}
int A[30];
void solve(int a, int b, int c, int L, int order) {
  if (L > n) return;
  int R = L;
  while (R <= n && A[R] == A[L]) R++;
  int cnt = R - L;
  if (R > n) {
    if (order) {
      move(a, b, cnt - 1);
      move(a, c, 1);
      move(b, c, cnt - 1);
    } else
      move(a, c, cnt);
    return;
  }
  if (R == L + 1 || !order) {
    solve(a, c, b, R, 0);
    move(a, c, cnt);
    solve(b, a, c, R, 0);
  } else {
    solve(a, b, c, R, 0);
    move(a, b, cnt);
    solve(c, b, a, R, 0);
    move(b, c, cnt);
    solve(a, b, c, R, 1);
  }
}
void lemon() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &A[i]);
  solve(1, 2, 3, 1, 1);
  printf("%d\n", final.size());
  for (typeof((final).begin()) it = (final).begin(); it != (final).end(); it++)
    printf("%d %d\n", it->first, it->second);
}
int main() {
  ios::sync_with_stdio(true);
  lemon();
  return 0;
}
