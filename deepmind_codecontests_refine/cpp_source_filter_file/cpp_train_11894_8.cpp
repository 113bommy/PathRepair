#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int Max = 8e3 + 100;
int a[Max], b[Max];
bitset<Max> c, d;
void solve() {
  int n;
  scanf("%d", &n);
  ;
  if (n == 2 || n == 3) {
    printf("-1\n");
    return;
  }
  int beg = 1;
  while (n >= 8) {
    printf("%d %d %d %d ", beg + 1, beg + 3, beg, beg + 2);
    beg += 4;
    n -= 4;
  }
  if (n == 4) {
    printf("%d %d %d %d \n", beg + 1, beg + 3, beg, beg + 2);
    return;
  } else if (n == 5) {
    printf("%d %d %d %d %d\n", beg, beg + 2, beg + 4, beg + 1, beg + 3);
  } else if (n == 6) {
    printf("%d %d %d %d %d %d\n", beg, beg + 2, beg + 5, beg + 3, beg + 1,
           beg + 4);
  } else {
    printf("%d %d %d %d %d %d %d\n", beg, beg + 2, beg + 4, beg + 6, beg + 3,
           beg + 5, beg + 2);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  ;
  while (t--) {
    solve();
  }
}
