#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n - k; ++i) printf("%d ", i);
  for (int j = n; j >= n - k; --j) printf("%d ", j);
  return 0;
}
