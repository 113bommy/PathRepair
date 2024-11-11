#include <bits/stdc++.h>
using namespace std;
long long fg[200005];
int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) scanf("%lld", &fg[i]);
  long long now = 0;
  for (long long i = 1; i <= m; i++) {
    int op;
    long long x;
    scanf("%d%lld", &op, &x);
    if (op == 1) {
      long long y;
      scanf("%lld", &y);
      fg[x] = y - now;
    }
    if (op == 2) {
      now += x;
    }
    if (op == 3) {
      printf("%lld\n", fg[x] + now);
    }
  }
  return 0;
}
