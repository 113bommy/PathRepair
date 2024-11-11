#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) {
    int x;
    scanf("%d", &x);
    d[x] = 1;
  }
  int t = 0;
  for (int i = 0; i < (int)(1000000); i++) {
    if (d[i + 1] == 1) {
      if (d[1000000 - i] == 1)
        t++;
      else
        d[1000000 - i] = -1;
    }
  }
  for (int i = 0; i < (int)(1000000); i++) {
    if (!t) continue;
    if (!d[i + 1]) {
      d[i + 1] = d[1000000 - i] = -1;
      t -= 2;
    }
  }
  printf("%d\n", n);
  for (int i = 0; i < (int)(1000000); i++) {
    if (d[i + 1] == -1) printf("%d ", i + 1);
  }
  puts("");
  return 0;
}
