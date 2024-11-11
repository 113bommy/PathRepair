#include <bits/stdc++.h>
using namespace std;
const int dell[8][2] = {{1, 2},  {1, -2},  {2, 1},  {2, -1},
                        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
long long mod = 998244353;
const long long inf = (1LL << 31) - 1;
const int maxn = 1e5 + 7;
const int maxm = 1e6 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int csize = 22;
int n, k, m, ar[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * 2 / 3; i++) printf("0 %d\n", i);
  for (int i = 1; i <= n - n * 2 / 3; i++) printf("3 %d\n", i * 2);
  return 0;
}
