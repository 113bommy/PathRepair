#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:33554432")
using namespace std;
int n, k;
char s[1 << 17];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  vector<int> pos;
  for (int i = 0; i < n; ++i)
    if (s[i] == '0') pos.push_back(i);
  int res = (int)1e9;
  for (int i = 0; i <= (int)pos.size() - (k + 1); ++i) {
    int L = i, R = i + k + 1;
    while (R - L > 1) {
      int M = (L + R) / 2;
      if (2 * (pos[M] - pos[i]) <= pos[i + k] - pos[i])
        L = M;
      else
        R = M;
    }
    for (int d = -5; d <= 5; ++d) {
      if (L + d < i || L + d > i + k) continue;
      res = min(res, max(pos[L + d] - pos[i], pos[i + k] - pos[L + d]));
    }
  }
  printf("%d\n", res);
  return 0;
}
