#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    cin >> n;
    if (n < 4) {
      puts("-1");
      continue;
    }
    if (n % 2 == 1) {
      for (int i = n; i >= 1; i -= 2) printf("%d ", i);
      printf("4 2 ");
      for (int i = 2; i < n; i += 2) printf("%d ", i);
      puts("");
    } else {
      for (int i = n - 1; i >= 1; i -= 2) printf("%d ", i);
      printf("4 2 ");
      for (int i = 2; i <= n; i += 2) printf("%d ", i);
      puts("");
    }
  }
  return 0;
}
