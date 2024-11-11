#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  scanf("%d", &n);
  if (n < 31)
    puts("NO");
  else {
    puts("YES");
    m = n - 30;
    if (m == 6)
      puts("5 6 10 15");
    else if (m == 10)
      puts("6 10 15 9");
    else if (m == 14)
      puts("6 10 13 15");
    else
      printf("6 10 14 %d\n", m);
  }
}
int main() {
  int _T;
  scanf("%d", &_T);
  while (_T--) solve();
  return 0;
}
