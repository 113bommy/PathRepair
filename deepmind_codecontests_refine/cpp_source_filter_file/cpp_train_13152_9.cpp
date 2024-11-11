#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 100000 + 100;
const int inf = 0x7fffffff;
int n, a, b, c;
int f[N];
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &c);
  f[a] = 1;
  f[b] = 1;
  f[c] = 1;
  for (int i = min(a, min(b, c)); i <= n; i++) {
    if (f[i]) {
      f[i + a] = max(f[i + a], f[i] + 1);
      f[i + b] = max(f[i + b], f[i] + 1);
      f[i + c] = max(f[i + b], f[i] + 1);
    }
  }
  printf("%d\n", f[n]);
  return 0;
}
