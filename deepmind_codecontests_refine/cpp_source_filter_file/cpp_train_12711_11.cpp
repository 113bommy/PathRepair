#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21;
int d[N];
unsigned long long f[N], g[N];
char a[N], b[N];
inline void FMT(unsigned long long *a, int n, int f) {
  for (int i = 1; i < n; i <<= 1)
    for (int j = 0; j < n; j++)
      if (i & j) a[j] += f * a[i ^ j];
}
int main() {
  int n;
  cin >> n, n = 1 << n;
  for (int i = 1; i < n; i++) d[i] = d[i - (i & -i)] + 2;
  scanf("%s%s", a, b);
  for (int i = 0; i < n; i++)
    f[i] = 1LL * a[i] - '0' << d[i], g[i] = 1LL * b[i] - '0' << d[i];
  FMT(f, n, 1), FMT(g, n, 1);
  for (int i = 0; i < n; i++) f[i] *= g[i];
  FMT(f, n, -1);
  for (int i = 0; i < n; i++) putchar((f[i] >> d[i] & 3) + '0');
  return 0;
}
