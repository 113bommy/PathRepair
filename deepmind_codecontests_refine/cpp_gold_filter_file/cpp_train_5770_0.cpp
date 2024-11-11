#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l, r, st, sk;
  scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &st, &sk);
  int q = sk / k;
  int rm = sk % k;
  for (int i = 0; i < rm; i++) printf("%d ", q + 1);
  for (int i = rm; i < k; i++) printf("%d ", q);
  if (n - k) {
    st = st - sk;
    int q = st / (n - k);
    int rm = st % (n - k);
    for (int i = 0; i < rm; i++) printf("%d ", q + 1);
    for (int i = rm; i < (n - k); i++) printf("%d ", q);
  }
  printf("\n");
  return 0;
}
