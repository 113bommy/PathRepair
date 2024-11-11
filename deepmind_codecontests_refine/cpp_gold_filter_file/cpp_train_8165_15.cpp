#include <bits/stdc++.h>
using namespace std;
using lint = long long;
constexpr int cntmax = 100007;
int main() {
  int n;
  scanf("%d", &n);
  array<int, cntmax> x;
  for (int i = 0; i < n; ++i) {
    int cur;
    scanf("%d", &cur);
    x[cur]++;
  }
  array<array<lint, 2>, cntmax> D;
  for (int i = 0; i < cntmax; ++i) fill(begin(D[i]), end(D[i]), 0ll);
  auto initarr = [&]() {
    for (int i = 1; i < cntmax; ++i)
      if (x[i]) return i;
    return -1;
  };
  int poz = initarr();
  D[poz][1] = static_cast<lint>(poz) * x[poz];
  for (int i = poz + 1; i < cntmax; ++i) {
    D[i][0] = max(D[i - 1][0], D[i - 1][1]);
    D[i][1] = D[i - 1][0] + 1LL * i * x[i];
  }
  printf("%I64d", max(D[cntmax - 1][0], D[cntmax - 1][1]));
  return 0;
}
