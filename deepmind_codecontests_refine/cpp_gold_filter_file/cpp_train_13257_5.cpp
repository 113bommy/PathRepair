#include <bits/stdc++.h>
using namespace std;
const int N = 5100, OP = 200000;
int n, M = 0, Q = 0;
int k[N], a[N], x[N], y[N], m[N];
struct PR {
  int a, b;
} e[210000], A[210000];
bool cmp(const PR& A, const PR& B) { return A.a < B.a; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d%d%d", &k[i], &a[i], &x[i], &y[i], &m[i]), M += k[i];
  int P = n, ans = -1;
  while (P > 0) {
    int cp = 0;
    for (int i = 1; i <= n; ++i)
      if (k[i] > 0) {
        for (int now = -123456789; k[i] > 0 && a[i] >= now; --k[i]) {
          if (M <= OP) e[++cp].a = a[i], e[cp].b = i;
          now = a[i], a[i] = ((long long)a[i] * x[i] + y[i]) % m[i];
        }
        if (k[i] <= 0) --P;
      }
    ++ans;
    if (M <= OP) {
      sort(e + 1, e + 1 + cp, cmp);
      for (int i = 1; i <= cp; ++i) A[++Q] = e[i];
    }
  }
  cout << ans << endl;
  if (M <= OP)
    for (int i = 1; i <= M; ++i) printf("%d %d\n", A[i].a, A[i].b);
  return 0;
}
