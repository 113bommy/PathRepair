#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
int cnt, n;
char a[100];
void dfs(int l, int r) {
  if (l == n && r == n) {
    a[l + r] = '\0';
    puts(a);
    --cnt;
    if (cnt == 0) return;
  }
  if (l > r) {
    a[l + r] = ')';
    dfs(l, r + 1);
    if (cnt == 0) return;
  }
  if (l < n) {
    a[l + r] = '(';
    dfs(l + 1, r);
    if (cnt == 0) return;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    cnt = n;
    dfs(0, 0);
  }
  return 0;
}
