#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int sp = 3, x, flag = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x == sp) {
      flag = 1;
    }
    sp = 6 - (x + sp);
  }
  printf("%s", flag == 0 ? "NO\n" : "YES\n");
  return 0;
}
