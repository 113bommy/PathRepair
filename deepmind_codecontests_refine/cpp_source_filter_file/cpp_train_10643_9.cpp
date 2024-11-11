#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100000];
  int i;
  while (cin >> a) {
    int i, j;
    int first = 0;
    for (i = 0; a[i]; ++i) {
      int ans = 0;
      for (j = 0; j <= 7; ++j) {
        ans = ans * 2 + ((a[i] & (1 << j)) ? 1 : 0);
      }
      printf("%d\n", (first - ans + 256) % 256);
      first = ans;
    }
  }
  return 0;
}
