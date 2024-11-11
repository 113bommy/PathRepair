#include <bits/stdc++.h>
using namespace std;
bool t[113];
int main() {
  long long n, m;
  long long x, y, a = 0;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    if (!t[x] && x != 0) {
      a++;
      t[x] = true;
    }
  }
  printf("%lld", a);
  return 0;
}
