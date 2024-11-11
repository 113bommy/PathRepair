#include <bits/stdc++.h>
using namespace std;
int Ans[1000] = {0};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int k;
      scanf("%d", &k);
      if (k == 1) {
        Ans[i] = 1;
      } else if (k == 2)
        Ans[j] = 1;
      else if (k == 3) {
        Ans[i] = 1;
        Ans[j] = 1;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++)
    if (Ans[i]) sum++;
  sum = n - sum;
  printf("%d\n", sum);
  for (int i = 0; i < n; i++)
    if (!Ans[i]) printf("%d ", i + 1);
  return 0;
}
