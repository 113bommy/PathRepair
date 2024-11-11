#include <bits/stdc++.h>
using namespace std;
const int maxN = 1555;
const long long INF = numeric_limits<long long>::max() / 2;
long long s[maxN], mem[2][maxN];
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      scanf("%I64d", &s[j]);
      if (j) s[j] += s[j - 1];
    }
    int cur = i & 1;
    if (i == 0) {
      for (int j = 0; j < (m); ++j) mem[0][j] = s[j];
    } else if (cur) {
      long long mx = -INF;
      for (int j = (m - 1); j >= (0); --j) {
        mem[cur][j] = s[j] + mx;
        mx = max(mx, mem[cur ^ 1][j]);
      }
    } else {
      long long mx = -INF;
      for (int j = 0; j < (m); ++j) {
        mem[cur][j] = s[j] + mx;
        mx = max(mx, mem[cur ^ 1][j]);
      }
    }
  }
  printf("%I64d\n", *max_element(mem[(n - 1) & 1], mem[(n - 1) & 1] + m));
  return 0;
}
