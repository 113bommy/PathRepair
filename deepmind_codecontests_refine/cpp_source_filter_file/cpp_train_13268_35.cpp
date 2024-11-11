#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, p, q, total;
  scanf("%d", &n);
  for (i = 0, total = 0; i < n; i++) {
    scanf("%d%d", &p, &q);
    if (p < q) total++;
  }
  printf("%hd", total);
}
