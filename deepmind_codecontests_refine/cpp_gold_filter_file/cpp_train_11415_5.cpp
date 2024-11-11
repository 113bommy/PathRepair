#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int ans = 0;
  map<long long, char> M;
  int l, r;
  scanf("%d%d", &l, &r);
  for (int i = 0; i < 35; ++i) {
    for (int j = 0; j < 35; ++j) {
      long long cur = pow(2, i) * pow(3, j);
      if (!M[cur] && cur >= l && cur <= r) ++ans, M[cur] = 1;
    }
  }
  printf("%d", ans);
  return 0;
}
