#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, arr[101][101], c2 = 0, c1 = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n / k; ++i)
    for (int j = 0; j < k; ++j) scanf("%d", &arr[i][j]);
  int t = 0;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n / k; ++j) {
      if (arr[i][j] == 1)
        c1++;
      else
        c2++;
    }
    t += min(c1, c2);
    c1 = 0;
    c2 = 0;
  }
  printf("%d", t);
  return 0;
}
