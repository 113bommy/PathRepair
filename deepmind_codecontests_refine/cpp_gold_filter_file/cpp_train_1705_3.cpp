#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e+9 + 9;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const int MAXN = 200500;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  int mmin = min(n, m);
  printf("%d\n", mmin + 1);
  for (int i = 0; i <= mmin; ++i) printf("%d %d\n", i, mmin - i);
  return 0;
}
