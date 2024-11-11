#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
int main() {
  int x, y, z, t1, t2, t3;
  scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
  int stairs = abs(x - y) * t1;
  int elevator = abs(z - x) * t2 + t3 + abs(x - y) * t2 + t3;
  if (elevator <= stairs)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
