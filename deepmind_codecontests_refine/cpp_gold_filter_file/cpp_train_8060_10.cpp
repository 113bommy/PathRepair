#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int MOD = 100000007;
const int MAXN = 110;
const double PI = acos(-1.0);
const int MAXV = 1100;
int ipt[MAXN];
int cmp(int a, int b) { return a > b; }
int main() {
  int n, k;
  while (~scanf("%d%d", &n, &k)) {
    for (int i = 0; i < (n); ++i) scanf("%d", &ipt[i]);
    sort(ipt, ipt + n, cmp);
    printf("%d\n", ipt[k - 1]);
  }
  return 0;
}
