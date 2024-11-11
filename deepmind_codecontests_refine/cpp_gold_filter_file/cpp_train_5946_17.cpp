#include <bits/stdc++.h>
const int N = 300010;
const int inf = 0x3f3f3f3f;
using namespace std;
struct data {
  int a, b, id;
  data() {}
  data(int _a, int _b) : a(_a), b(_b) {}
  bool operator<(const data &r) const {
    if (b != r.b) return b < r.b;
    return a < r.a;
  }
} x[N];
long long w[N];
long long dp[N], sum[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &w[i]);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++)
    scanf("%d%d", &x[i].a, &x[i].b), x[i].a--, x[i].id = i;
  sort(x, x + q);
  long long b = -1;
  for (int i = 0; i < q; i++) {
    if (x[i].b >= 150) {
      long long ret = 0;
      for (int j = x[i].a; j < n; j += x[i].b) ret += w[j];
      sum[x[i].id] = ret;
      continue;
    }
    if (x[i].b != b) {
      b = x[i].b;
      for (int j = n - 1; j >= 0; j--)
        if (j + b >= n)
          dp[j] = w[j];
        else
          dp[j] = dp[j + b] + w[j];
    }
    sum[x[i].id] = dp[x[i].a];
  }
  for (int i = 0; i < q; i++) printf("%I64d\n", sum[i]);
  return 0;
}
