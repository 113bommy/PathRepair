#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 2000 + 10;
const double eps = 1e-9;
const int mod = (int)1e9 + 7;
const double PI = acos(-1.0);
const long long base = 33;
int main() {
  int a[5];
  scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
  printf("%d", min(a[0], min(a[1], min(a[2] / 2, min(a[3] / 7, a[4] / 4)))));
  return 0;
}
