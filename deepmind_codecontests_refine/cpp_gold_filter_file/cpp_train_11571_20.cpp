#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  scanf("%d%d", &n, &v);
  printf("%d\n", v >= n - 1 ? n - 1 : (1 + n - v) * (n - v) / 2 + v - 1);
  return 0;
}
