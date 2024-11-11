#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int l[N], r[N];
int x0, n;
int flag;
void input() {
  scanf("%d%d", &x0, &n);
  int a, b;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    if (a == b) flag = true;
    l[i] = a, r[i] = b;
  }
}
void init() {
  sort(l + 1, l + 1 + n);
  sort(r + 1, r + 1 + n);
}
void solve() {
  if (flag) {
    puts("-1");
    return;
  }
  init();
  int st = l[n], ed = r[1];
  if (st == ed)
    printf("%d\n", abs(x0 - st));
  else if (st > ed)
    puts("-1");
  else if (st <= x0 && x0 <= ed)
    puts("0");
  else {
    printf("%d\n", min(abs(x0 - st), abs(x0 - ed)));
  }
}
void test() { printf("%d\n", min(abs(x0 - 10), abs(x0 - 0))); }
int main() {
  input();
  solve();
  return 0;
}
