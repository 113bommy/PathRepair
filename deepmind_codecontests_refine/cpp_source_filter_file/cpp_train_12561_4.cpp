#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000007LL;
const double EPS = 1e-10;
const long long inf_ll = (long long)1e18;
const long long maxn = 200005LL;
const long long mod = 810872LL;
int n;
long long A, B;
long long a[maxn], b[maxn], order[maxn], mark[maxn];
int choose;
long long res, sum;
int cmp(int x, int y) { return b[x] - a[x] > b[y] - a[y]; }
int main() {
  scanf("%d%I64d%I64d", &n, &A, &B);
  for (register int(i) = (1); (i) <= (n); ++i)
    scanf("%I64d%I64d", b + i, a + i), order[i] = i, sum += a[i];
  sort(order + 1, order + n + 1, cmp);
  if (!B) {
    printf("%I64d\n", sum);
    return 0;
  }
  res = 0;
  int flag = 0;
  for (register int(i) = (1); (i) <= (B); ++i) {
    int u = order[i];
    if (b[u] > a[u])
      res += b[u] - a[u], mark[u] = 1;
    else {
      flag = 1;
      break;
    }
  }
  long long ans = 0;
  for (register int(i) = (1); (i) <= (n); ++i) {
    long long tmp = ((b[i]) << (A)) - a[i];
    if (!mark[i]) {
      if (flag)
        ans = ((ans) > (sum + res + tmp) ? (ans) : (sum + res + tmp));
      else
        ans = ((ans) > (sum + res + tmp - (b[order[B]] - a[order[B]]))
                   ? (ans)
                   : (sum + res + tmp - (b[order[B]] - a[order[B]])));
    } else
      ans = ((ans) > (sum + res + tmp - (b[i] - a[i]))
                 ? (ans)
                 : (sum + res + tmp - (b[i] - a[i])));
  }
  printf("%I64d\n", ans);
  return 0;
}
