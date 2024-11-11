#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
long long a, b, c, d;
char u[MAXN], v[MAXN];
int main() {
  scanf("%d", &n);
  scanf("%s", &u);
  scanf("%s", &v);
  for (int i = 0; i < n; i++) {
    if (u[i] == '0') {
      if (v[i] == '0')
        a++;
      else
        b++;
    } else {
      if (v[i] == '1')
        c++;
      else
        d++;
    }
  }
  printf("%lld\n", a * d + c * b + b * d);
  return 0;
}
