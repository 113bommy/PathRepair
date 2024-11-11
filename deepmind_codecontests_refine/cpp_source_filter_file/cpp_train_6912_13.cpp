#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
char a[N];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", a);
  int m = strlen(a);
  if (m < 4) {
    puts("0");
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (i % n == 0) {
      int ok = 1;
      for (int j = 2; j <= 3; j++) {
        int x = (i - j + m) % m;
        if (a[x] != a[(i - 1 + m) % m]) ok = 0;
      }
      if (ok) cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
