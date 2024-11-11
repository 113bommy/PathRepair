#include <bits/stdc++.h>
using namespace std;
const int N = 512345, LG = 21, mod = 1000000007, M = N;
const double eps = 1e-3, pi = acos(-1.0);
const long long INF = 1123456789123456789LL;
int r[N], d[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &r[i + 1]), scanf("%d", &d[i]);
  }
  bool inf = true;
  for (int i = 0; i < n; ++i) {
    if (d[i] == 2) inf = false;
  }
  if (inf) {
    printf("Infinity");
    return 0;
  }
  int c = 0;
  int m[3] = {0, mod, -mod};
  for (int i = 0; i < n; ++i) {
    c += r[i];
    if (d[i] == 2)
      m[2] = max(m[2], c);
    else
      m[1] = min(m[1], c);
  }
  if (m[2] > m[1]) {
    printf("Impossible\n");
    return 0;
  }
  int initial = mod;
  for (int i = 0; i <= n; ++i) {
    c += r[i];
    if (d[i] == 2) {
      initial = min(initial, 1899 - c);
    }
  }
  printf("%d\n", initial + c);
  return 0;
}
