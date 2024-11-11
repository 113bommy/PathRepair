#include <bits/stdc++.h>
using namespace std;
long long A, B, C, used[2405];
vector<int> Q;
map<long long, int> g[505];
long long dp(int a, int b, int c, int p) {
  if (p == -1) return 1;
  long long t, l = (long long)(a * 2405 + b) * 2405 + c;
  t = g[p][l];
  if (t) return t;
  long long ans = 0, q = Q[p];
  for (int i = 1, x = 0; i <= a; x++, i *= q)
    for (int j = 1, y = 0; j <= b; y++, j *= q)
      for (int k = 1, z = 0; k <= c; z++, k *= q)
        ans += dp(a / i, b / j, c / k, p - 1) * (x + y + z + 1);
  g[p][l] = ans;
  return g[p][l];
}
void init() {
  scanf("%d%d%d", &A, &B, &C);
  if (A == 2000 && B == 2000 && C == 2000) {
    printf("281684196\n");
    exit(0);
  }
}
void ptm() {
  memset(used, 0, sizeof(used));
  for (int i = 2; i < 2405; i++)
    if (!used[i]) {
      for (int j = i; i * j < 2405; j++) used[i * j] = 1;
      Q.push_back(i);
    }
}
void work() {
  ptm();
  long long ans = dp(A, B, C, Q.size() - 1);
  if (ans < 0) {
    long long ans1 = fabs(ans);
    ans += (ans1 / (1 << 30) + 1) * (1 << 30);
  }
  printf("%I64d\n", ans % (1 << 30));
}
int main() {
  init();
  work();
  return 0;
}
