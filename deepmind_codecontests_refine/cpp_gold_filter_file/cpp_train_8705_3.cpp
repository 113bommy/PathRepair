#include <bits/stdc++.h>
const int MaxN = 1 << 20;
using namespace std;
int n, m, num[40];
long long a[MaxN + 5], b[MaxN + 5];
int tot_a, tot_b;
long long Get(int s, int add) {
  long long res = 0;
  int now = 1;
  while (s != 0) {
    if (s & 1) res += num[now + add];
    now++;
    s /= 2;
  }
  return res;
}
void Init() {
  tot_a = tot_b = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  int one = (n + 1) / 2, two = n - one;
  for (int i = 0; i <= (1 << one) - 1; i++) {
    long long x = Get(i, 0);
    a[++tot_a] = x % m;
  }
  for (int i = 0; i <= (1 << two) - 1; i++) {
    long long x = Get(i, one);
    b[++tot_b] = x % m;
  }
  sort(a + 1, a + tot_a + 1);
  sort(b + 1, b + tot_b + 1);
}
void Solve() {
  int now = tot_b;
  long long ans = 0;
  for (int i = 1; i <= tot_a; i++) {
    while (now > 1 && a[i] + b[now] >= m) now--;
    ans = max(ans, max((a[i] + b[now]) % m, (a[i] + b[tot_b]) % m));
  }
  printf("%I64d\n", ans);
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    Init();
    Solve();
  }
}
