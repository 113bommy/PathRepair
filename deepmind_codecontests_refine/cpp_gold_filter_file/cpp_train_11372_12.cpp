#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
pair<int, int> a[N];
int de[N];
int main() {
  long long u, v;
  cin >> u >> v;
  if (u > v || (u + v) & 1) {
    printf("-1\n");
    return 0;
  }
  if (u == v) {
    if (u == 0)
      printf("0\n");
    else
      printf("1\n%lld", u);
    return 0;
  }
  long long x = (v - u) / 2;
  if (u & x)
    printf("3\n%lld %lld %lld", u, x, x);
  else
    printf("2\n%lld %lld", (u + x), x);
  return 0;
}
