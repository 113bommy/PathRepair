#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n = 0;
  scanf("%d%d", &a, &b);
  for (int i = 1e5; i >= 1; --i) {
    long long x = (1ll * i * (i + 1)) >> 1;
    if (x <= a + b) {
      n = i;
      break;
    }
  }
  vector<int> an, bn;
  int sm = 0;
  for (int i = n; i >= 1; --i) {
    if (sm + i <= a)
      an.push_back(i), sm += i;
    else
      bn.push_back(i);
  }
  printf("%d\n", an.size());
  for (auto i : an) printf("%d ", i);
  printf("\n%d\n", bn.size());
  for (auto i : bn) printf("%d ", i);
}
