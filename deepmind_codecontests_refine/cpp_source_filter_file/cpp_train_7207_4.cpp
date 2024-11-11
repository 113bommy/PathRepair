#include <bits/stdc++.h>
using namespace std;
int const N = 100;
int n, an[N + 1], fr[N + 1];
vector<int> q;
struct P {
  int a, b;
  P() {}
  P(int x, int y) : a(x), b(y) {}
  void sc() { scanf("%d%d", &a, &b); }
  P operator-(P const &o) const { return P(a - o.a, b - o.b); }
} a, b;
P ask(int v) {
  ++fr[v];
  printf("+ %d\n", v);
  fflush(stdout);
  a = b;
  b.sc();
  return b - a;
}
int sq(int x) { return lower_bound(q.begin(), q.end(), x) - q.begin() + 1; }
int s(int v) { return an[v] + fr[v]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (int)(n + 1); ++i) q.push_back(i * (i - 1) >> 1);
  b.sc();
  P a = ask(3), b = ask(1), c = ask(2), d = ask(1);
  an[1] = sq(d.a) - 1;
  an[2] = b.b ? sq(c.a) : 0;
  if (a.a)
    an[3] = sq(a.a);
  else
    an[3] = d.b / (an[2] + 1);
  an[4] = (c.b - (an[1] + 1) * (an[3] + 1)) / (an[3] + 1);
  int i = 5;
  while (i <= n) {
    if (an[i - 1]) {
      P t = ask(i - 2);
      an[i] = (t.b - s(i - 4) * s(i - 3) - s(i - 3) * s(i - 1)) / s(i - 1);
      ++i;
    } else {
      P a = ask(i - 1);
      if (a.b - s(i - 3) * s(i - 2) == 0) {
        an[i] = 0;
        ++i;
        continue;
      }
      if (i == n) {
        an[i] = (a.b - s(i - 3) * s(i - 2)) / s(i - 2);
        break;
      }
      P b = ask(i - 2);
      an[i] = (b.b - s(i - 4) * s(i - 3) - s(i - 3) * s(i - 1)) / s(i - 1);
      an[i + 1] =
          (a.b - s(i - 3) * (s(i - 2) - 1) - (s(i - 2) - 1) * s(i)) / s(i);
      i += 2;
    }
  }
  printf("!");
  for (int i = 1; i < (int)(n + 1); ++i) printf(" %d", an[i]);
  printf("\n");
}
