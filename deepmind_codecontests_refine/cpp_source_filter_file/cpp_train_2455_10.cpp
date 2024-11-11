#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int solve();
int main() { return solve(); }
const int dd = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
int solve() {
  int n;
  scanf("%d", &n);
  int ans = 0, x;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    ans += x;
  }
  printf("%d", ans);
  return 0;
}
