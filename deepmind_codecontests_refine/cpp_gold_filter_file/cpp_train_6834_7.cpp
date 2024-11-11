#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  scanf("%d", &k);
  if (k > 36) return !printf("-1\n");
  for (int i = (1); i <= (k / 2); i++) printf("8");
  if (k & 1) printf("4");
  printf("\n");
  return 0;
}
