#include <bits/stdc++.h>
using namespace std;
bool SR(int &_x) { return scanf("%d", &_x) == 1; }
bool SR(long long &_x) { return scanf("%lld", &_x) == 1; }
bool SR(double &_x) { return scanf("%lf", &_x) == 1; }
bool SR(char *_s) { return scanf("%s", _s) == 1; }
bool RI() { return true; }
template <typename I, typename... T>
bool RI(I &_x, T &..._tail) {
  return SR(_x) && RI(_tail...);
}
void SP(const int _x) { printf("%d", _x); }
void SP(const long long _x) { printf("%lld", _x); }
void SP(const double _x) { printf("%.16lf", _x); }
void SP(const char *s) { printf("%s", s); }
void PL() { puts(""); }
template <typename I, typename... T>
void PL(const I _x, const T... _tail) {
  SP(_x);
  if (sizeof...(_tail)) putchar(' ');
  PL(_tail...);
}
const int maxn = 5e3 + 3;
int n;
long long s;
long long x[maxn], y[maxn];
void read() {
  RI(n, s);
  for (int i = (1); i <= int(n); i++) RI(x[i], y[i]);
}
long long area(int i, int j, int k) {
  long long dx[] = {x[i] - x[j], x[i] - x[k]};
  long long dy[] = {y[i] - y[j], y[i] - y[k]};
  long long ans = dx[0] * dy[1] - dx[1] * dy[0];
  return abs(ans);
}
int doo(int i, int j) {
  int k = i;
  for (int xx = (1); xx <= int(n); xx++)
    if (area(i, j, k) < area(i, j, xx)) k = xx;
  return k;
}
int a, b, c;
void build() {
  srand(time(0));
  a = rand() % n + 1;
  b = a;
  while (b == a) b = rand() % n + 1;
  c = a;
  while (c == a || c == b) c = rand() % n + 1;
  while (1) {
    int da = doo(b, c);
    int db = doo(c, a);
    int dc = doo(a, b);
    long long opt[] = {area(a, b, c), area(da, b, c), area(a, db, c),
                       area(a, b, dc)};
    long long hi = *max_element(opt, opt + 4);
    if (hi == opt[0])
      break;
    else if (hi == opt[1])
      a = da;
    else if (hi == opt[2])
      b = db;
    else
      c = dc;
  }
}
void sol() {
  ;
  printf("%lld %lld\n", +x[a] + x[b] - x[c], +y[a] + y[b] - y[c]);
  printf("%lld %lld\n", +x[a] - x[b] + x[c], +y[a] - y[b] + y[c]);
  printf("%lld %lld\n", -x[a] + x[b] + x[c], -y[a] + y[b] + y[c]);
}
int main() {
  read();
  build();
  sol();
  return 0;
}
