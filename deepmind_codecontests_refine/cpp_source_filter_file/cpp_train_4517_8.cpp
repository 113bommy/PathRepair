#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf(" %d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    if (i < k)
      printf("%d ", k - i);
    else
      printf("%d ", i + 1);
  }
  printf("\n");
}
