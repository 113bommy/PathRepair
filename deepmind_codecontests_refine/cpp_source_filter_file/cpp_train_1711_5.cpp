#include <bits/stdc++.h>
using namespace std;
int n, sum, ans[1000000], anss;
bool b[1000000 + 5];
int main() {
  scanf("%d", &n);
  printf("%d\n", n);
  sum = -n;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    b[a] = 1;
  }
  int p = 1;
  for (int i = 1; i <= 1000000; i++)
    if (b[i]) {
      if (b[1000000 + 1 - i]) {
        if (i <= 50000) {
          for (; (b[p] || b[1000000 + 1 - p]); p++)
            ;
          printf("%d %d ", p, 1000000 + 1 - p);
          p++;
        }
      } else
        printf("%d ", 1000000 + 1 - i);
    }
  cout << endl;
  return 0;
}
