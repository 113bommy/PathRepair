#include <bits/stdc++.h>
using namespace std;
bool debug;
const int inf = 1e9 + 5;
const int nax = 1e3 + 5;
int t[nax];
int n, najm;
int h[nax], w[nax];
int main(int argc, char* argv[]) {
  debug = argc > 1;
  scanf("%d", &n);
  int najm = 0;
  for (int i = 0; i <= (n)-1; ++i) {
    scanf("%d%d", &h[i], &w[i]);
    najm = max(najm, min(h[i], w[i]));
  }
  int res = inf;
  for (int i = 1000; i >= najm; --i) {
    int ile_juz = 0;
    int szer = 0;
    int ile = 0;
    for (int j = 0; j <= (n)-1; ++j)
      if (h[j] > i) {
        ++ile_juz;
        szer += h[j];
      } else {
        if (w[j] <= i && w[j] > h[j]) t[ile++] = h[j] - w[j];
        szer += w[j];
      }
    sort(t, t + ile);
    for (int j = 0; j <= (min(n / 2 - ile_juz, ile)) - 1; ++j) szer += t[i];
    if (ile_juz <= n / 2) res = min(res, i * szer);
  }
  printf("%d\n", res);
  return 0;
}
