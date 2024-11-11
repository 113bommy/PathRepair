#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  scanf("%lli%lli", &(n), &(m));
  long long int p = 1, u = n;
  while (p <= u) {
    long long int q = 1, v = m;
    for (long long int i = 1; i <= m; i++) {
      printf("%lli %lli\n", p, q);
      if (p != u || (p == u && q < v))
        printf("%lli %lli\n", u, v);
      else
        break;
      q++, v--;
      if (p == u && q >= v) break;
    }
    p++, u--;
  }
  return 0;
}
