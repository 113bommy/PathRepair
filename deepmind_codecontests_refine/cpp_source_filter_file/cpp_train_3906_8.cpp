#include <bits/stdc++.h>
using namespace std;
int fl[105];
int main() {
  int n, s, f, t;
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &f, &t);
    fl[f] = max(fl[f], t);
  }
  t = 0;
  for (int i = s; i > 0; --i, ++t) {
    if (t < fl[i]) t += fl[i] - t;
  }
  printf("%d\n", t);
  return 0;
}
