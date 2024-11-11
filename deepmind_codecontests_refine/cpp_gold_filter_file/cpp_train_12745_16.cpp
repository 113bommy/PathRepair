#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k;
  scanf("%d%d%d", &n, &p, &k);
  if (p - k > 1) printf("<< ");
  for (int i = p - k; i < p; i++) {
    if (i > 0) printf("%d ", i);
  }
  printf("(%d) ", p);
  for (int i = p + 1; i <= p + k && i <= n; i++) {
    printf("%d ", i);
  }
  if (p + k < n) printf(">>");
  cout << endl;
  return 0;
}
