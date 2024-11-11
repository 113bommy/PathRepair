#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[55], num[2];
int main() {
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    memset(num, 0, sizeof num);
    int n, ans = 0, k = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      char s[55];
      scanf("%s", s);
      a[i] = strlen(s);
      for (int j = 0; j < a[i]; j++) num[s[j] - '0']++;
      if (a[i] % 2) k++;
    }
    if (k % 2 == 0 && num[0] % 2 && num[1] % 2)
      printf("%d\n", n - 1);
    else
      printf("%d\n", n);
  }
}
