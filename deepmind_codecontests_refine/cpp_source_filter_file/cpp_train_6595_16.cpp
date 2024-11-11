#include <bits/stdc++.h>
using namespace std;
pair<int, pair<int, int> > gcd(int a, int b, bool fn = false) {
  if (b == 0) {
    if (fn) printf("T");
    return make_pair(a == 1 ? 1 : -1e9, make_pair(0, false));
  }
  pair<int, pair<int, int> > an = gcd(b, a % b, fn);
  int t = a / b;
  if (b == 1) --t;
  if (fn)
    for (int i = 0; i < t; ++i) printf("%c", an.second.second ? 'T' : 'B');
  an.first += t;
  an.second.first += t - 1;
  an.second.second = !an.second.second;
  return an;
}
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  pair<int, int> an = make_pair(1e9, 0);
  for (int i = 1; i < r + 1; ++i) {
    pair<int, pair<int, int> > t = gcd(r, i);
    if (t.first == n && t.second.first < an.first)
      an = make_pair(t.second.first, i);
  }
  if (an.first == 1e9) printf("IMPOSSIBLE\n"), exit(0);
  printf("%d\n", an.first);
  gcd(r, an.second, true);
  printf("\n");
}
