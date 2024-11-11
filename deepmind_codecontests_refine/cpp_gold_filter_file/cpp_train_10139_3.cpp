#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  int bagi = (n / m);
  if (bagi * m == n) {
    for (int i = 0; i < m; i++) {
      printf("%d ", bagi);
    }
  } else {
    int sisa = (n - (m * bagi));
    for (int i = 0; i < m; i++) {
      int now = 0;
      if (sisa > 0) {
        now = bagi + 1;
        sisa--;
      } else {
        now = bagi;
      }
      printf("%d ", now);
    }
  }
  return 0;
}
