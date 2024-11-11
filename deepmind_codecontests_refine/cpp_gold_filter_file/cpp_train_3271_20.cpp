#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, temp;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  for (__typeof(0) i = (0); i < (n); i++)
    for (__typeof(0) j = (0); j < (m); j++) scanf("%d", &temp);
  cout << (m * (m - 1)) / 2 << endl;
  if (k) {
    for (__typeof(1) i = (1); i < (m); i++)
      for (__typeof(i + 1) j = (i + 1); j < (m + 1); j++)
        printf("%d %d\n", j, i);
  } else {
    for (__typeof(1) i = (1); i < (m); i++)
      for (__typeof(i + 1) j = (i + 1); j < (m + 1); j++)
        printf("%d %d\n", i, j);
  }
  return 0;
}
