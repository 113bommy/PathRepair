#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
const int LIM = 2e6;
const long long oo = 1LL << 60;
int N;
long long prec[MAXN], prepos[MAXN], x, y, ans = oo;
namespace solution {
void Prepare() {
  scanf("%d%lld%lld", &N, &x, &y);
  for (int i = 1; i <= N; i++) {
    long long a;
    scanf("%lld", &a);
    prec[a]++;
    prepos[a] += a;
  }
  for (int i = 1; i <= LIM; i++) {
    prec[i] += prec[i - 1];
    prepos[i] += prepos[i - 1];
  }
}
void Solve() {
  int key = x / y;
  for (int i = 2; i <= LIM; i++) {
    long long sum = 0, j;
    for (j = i; j <= LIM; j += i) {
      long long le = j - i + 1, ri = j, mi = ri - key;
      mi = max(mi, le);
      sum +=
          (ri * (prec[ri] - prec[mi - 1]) - (prepos[ri] - prepos[mi - 1])) * y;
      sum += (prec[mi - 1] - prec[le - 1]) * x;
      if (sum > ans) break;
    }
    ans = min(ans, sum);
  }
  printf("%lld\n", ans);
}
}  // namespace solution
int main() {
  using namespace solution;
  Prepare();
  Solve();
  return 0;
}
