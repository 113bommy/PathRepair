#include <bits/stdc++.h>
const int N = 1e5 + 10;
int k, n, m, a[N], f1[N], f[N];
inline int read() {
  int x = 0, k = 1;
  char c = getchar();
  for (; c < 48 || c > 57; c = getchar()) k ^= (c == '-');
  for (; c >= 48 && c <= 57; c = getchar()) x = x * 10 + (c ^ 48);
  return k ? x : -x;
}
inline long long read1() {
  long long x = 0, k = 1;
  char c = getchar();
  for (; c < 48 || c > 57; c = getchar()) k ^= (c == '-');
  for (; c >= 48 && c <= 57; c = getchar()) x = x * 10 + (c ^ 48);
  return k ? x : -x;
}
struct LD {
  long long b, op, numerator, denominator;
} b[N];
std::vector<LD> V[N];
inline bool cmp1(LD x, LD y) { return x.b < y.b; }
inline bool cmp(LD x, LD y) {
  return x.numerator * y.denominator > y.numerator * x.denominator;
}
inline bool cmpv(LD x, LD y) { return x.numerator > y.numerator; }
int main() {
  k = read(), n = read(), m = read();
  for (int i = 1; i <= k; i++) a[i] = read();
  int SUM = 0;
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read(), z = read();
    if (x == 1) {
      if (f[y] < z) {
        f[y] = z;
        f1[y] = i;
      }
    } else if (x == 2) {
      V[y].push_back((LD){i, 2, z, 0});
    } else if (x == 3) {
      b[++SUM].numerator = z - 1;
      b[SUM].denominator = 1;
      b[SUM].b = i;
      b[SUM].op = 3;
    }
  }
  for (int i = 1; i <= k; i++)
    if (f[i] > a[i]) V[i].push_back((LD){f1[i], 1, f[i] - a[i], 0});
  for (int i = 1; i <= n; ++i)
    if (V[i].size()) {
      std::sort(V[i].begin(), V[i].end(), cmpv);
      long long sum = a[i];
      b[++SUM] = (LD){V[i][0].b, V[i][0].op, V[i][0].numerator, sum};
      for (int j = 1; j < V[i].size(); ++j) {
        sum += V[i][j - 1].numerator,
            b[++SUM] = (LD){V[i][j].b, V[i][j].op, V[i][j].numerator, sum};
      }
    }
  std::sort(b + 1, b + SUM + 1, cmp);
  int sum = std::min(SUM, m);
  printf("%d\n", sum);
  for (int i = 1; i <= sum; i++)
    if (b[i].op == 1) printf("%d ", b[i].b);
  for (int i = 1; i <= sum; i++)
    if (b[i].op == 2) printf("%d ", b[i].b);
  for (int i = 1; i <= sum; i++)
    if (b[i].op == 3) printf("%d ", b[i].b);
  puts("");
  return 0;
}
