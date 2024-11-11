#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  n = n * sqrt(2.);
  printf("%d", max(1, 4 * n));
  return 0;
}
