#include <bits/stdc++.h>
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
using namespace std;
const double eps = 1e-8;
const int MAXN = 10000 + 10;
const int MOD = 1000007;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt[] = {2, 7, 3, 3, 3, 4, 2, 5, 1, 2};
int main() {
  char a, b;
  a = getchar();
  b = getchar();
  printf("%d\n", cnt[a - '0'] * cnt[b - '0']);
  return 0;
}
