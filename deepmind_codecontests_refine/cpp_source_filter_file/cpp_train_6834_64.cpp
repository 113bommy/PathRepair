#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
template <typename T>
inline void rd(T &x) {
  x = 0;
  int f = 1;
  char CH = getchar();
  while (!isdigit(CH)) {
    if (CH == '-') f = 0;
    CH = getchar();
  }
  while (isdigit(CH)) {
    x = ((x + (x << 2)) << 1) + (CH - 48);
    CH = getchar();
  }
  x = (f == 1) ? x : -x;
  return;
}
const int MXN = 2e6;
int a[MXN], n;
inline void solve() {
  long long fuck;
  rd(fuck);
  if (fuck > 34) {
    cout << -1;
    return;
  }
  if (fuck == 1)
    cout << 0;
  else if (fuck == 2)
    cout << 8;
  else if (fuck > 2) {
    while (fuck > 2) fuck -= 2, cout << 8;
    if (fuck == 1) cout << 0;
    if (fuck == 2) cout << 8;
  }
}
int main() { solve(); }
