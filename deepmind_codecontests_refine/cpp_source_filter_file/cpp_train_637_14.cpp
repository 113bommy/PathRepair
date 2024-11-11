#include <bits/stdc++.h>
using namespace std;
int n, m, tab0, tab1, chest[100007], ile, x;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x % 2 == 0)
      tab0++;
    else
      tab1++;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    if (x % 2 == 0) {
      if (tab1 > 0) {
        ile++;
        tab1--;
      }
    } else {
      if (tab0 > 0) {
        ile++;
        tab0++;
      }
    }
  }
  printf("%d", ile);
  return 0;
}
