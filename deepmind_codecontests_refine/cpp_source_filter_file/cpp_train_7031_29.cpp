#include <bits/stdc++.h>
using namespace std;
int p[4], a, b;
int main() {
  for (int i = 0; i < 4; i++) scanf("%d", &p[i]);
  scanf("%d%d", &a, &b);
  int ans = 0;
  for (int i = a; i <= b; i++) {
    int perm[4];
    int cnt = 0;
    for (int j = 0; j < 4; j++) perm[j] = p[j];
    do {
      int calc = ((((i % perm[0]) % perm[1]) % perm[2]) % perm[3]);
      if (calc == i) cnt++;
    } while (next_permutation(perm, perm + 4));
    if (cnt >= 7) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
