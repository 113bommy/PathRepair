#include <bits/stdc++.h>
const int maxn = 0x3f3f3f3f;
const double EI =
    2.71828182845904523536028747135266249775724709369995957496696762772407663035354594571382178525166427;
const double PI = 3.141592653589793238462643383279;
using namespace std;
vector<int> ve[200010];
int dep[200010], aans;
inline void f(int pos, int pre, int zz) {
  int si = ve[pos].size(), i;
  for (i = 0; i < si; i++) {
    if (ve[pos][i] != pre) {
      f(ve[pos][i], pos, zz + 1);
    }
  }
  dep[pos] = zz;
}
inline void ff(int pos, int pre, int zz) {
  int si = ve[pos].size(), i;
  if (zz >= dep[pos]) {
    return;
  }
  aans = max(aans, dep[pos] * 2);
  for (i = 0; i < si; i++) {
    if (ve[pos][i] != pre) {
      ff(ve[pos][i], pos, zz + 1);
    }
  }
}
int main(void) {
  int n, x, i, z1, z2;
  while (~scanf("%d %d", &n, &x)) {
    for (i = 0; i <= n; i++) {
      ve[i].clear();
    }
    for (i = 0; i < n - 1; i++) {
      scanf("%d %d", &z1, &z2);
      ve[z1].push_back(z2);
      ve[z2].push_back(z1);
    }
    f(1, -1, 0);
    aans = 0;
    ff(1, -1, 0);
    printf("%d\n", aans);
  }
  return 0;
}
