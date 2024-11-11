#include <bits/stdc++.h>
using namespace std;
int const N = 310000000;
int const MID = 20000;
bitset<N / 2> isprime;
int main() {
  isprime.set();
  isprime[0] = false;
  for (int i = 1; i < MID; ++i)
    if (isprime[i]) {
      int step = 2 * i + 1;
      int low = 2 * i * i + 2 * i;
      int k;
      for (k = low; k < MID; k += step) isprime[k] = false;
      if (k % 2 == 1) k += step;
      for (; k < isprime.size(); k += step * 2) isprime[k] = false;
    }
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) {
    int ans = 0;
    for (int i = 0, v = 2 * i + 1; v <= b; i += 2, v += 4) {
      if (a <= v) {
        if (isprime[i]) ans++;
      }
    }
    if (a <= 2 && 2 <= b) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
