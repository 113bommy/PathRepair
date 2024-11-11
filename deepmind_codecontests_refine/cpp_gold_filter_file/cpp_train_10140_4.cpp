#include <bits/stdc++.h>
using namespace std;
struct rec {
  int maxd;
  long long x;
};
struct ans {
  long long ret, x;
};
long long n, base[19];
map<rec, ans> g;
bool operator<(rec a, rec b) {
  return (a.maxd < b.maxd) || ((a.maxd == b.maxd) && (a.x < b.x));
}
long long f(int maxd, int d, long long &x) {
  if (!d) return 0;
  rec now;
  now.maxd = maxd;
  now.x = x;
  map<rec, ans>::iterator it = g.find(now);
  if (it != g.end()) {
    ans a = it->second;
    x = a.x;
    return a.ret;
  }
  if (d == 1) {
    long long ret = 0;
    if (maxd > x)
      ret = 1, x -= maxd;
    else {
      ret = 1;
      x = 0;
      if (maxd) ret++, x = -maxd;
    }
    return ret;
  }
  long long ret = 0;
  int top = 0;
  while (x >= base[d - 1]) x -= base[d - 1], top++;
  while (top >= 0) {
    ret += f(((maxd > top) ? maxd : top), d - 1, x);
    if (top) x += base[d - 1];
    top--;
  }
  ans a;
  a.ret = ret;
  a.x = x;
  g.insert(pair<rec, ans>(now, a));
  return ret;
}
int main() {
  int i;
  scanf("%I64d", &n);
  base[0] = 1;
  for (i = 1; i < 19; i++) base[i] = base[i - 1] * 10;
  int digit = 0;
  long long tmp = n;
  while (tmp) digit++, tmp /= 10;
  g.clear();
  printf("%I64d\n", f(0, digit, n));
  return 0;
}
