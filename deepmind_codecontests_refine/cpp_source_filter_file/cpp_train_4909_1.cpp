#include <bits/stdc++.h>
using namespace std;
bitset<300000001> gao;
int l, r;
int main() {
  gao.set();
  gao[1] = 0;
  scanf("%d%d", &l, &r);
  for (int i = 3; i * i <= r; i += 2)
    if (gao[i]) {
      int t = i << 1;
      for (int j = i * i; j <= r; j += t) gao[j] = false;
    }
  int ans = r <= 4 && r > 1;
  for (int i = 1 + ((l - 1) / 4 + ((l - 1) % 4 != 0)) * 4; i <= r; i += 4)
    ans += gao[i];
  printf("%d\n", ans);
}
