#include <bits/stdc++.h>
using namespace std;
const long maxn = 3005;
const long long inf = 1000000000000000000;
struct elem {
  long long x;
  long long c;
};
bool operator<(elem first, elem second) { return (first.x < second.x); }
long long a[maxn][maxn];
elem mas[maxn];
long n, i, q, k;
long long h[maxn];
int main() {
  scanf("%ld", &n);
  for (q = 1; q <= n; q++) cin >> mas[q].x >> mas[q].c;
  sort(mas + 1, mas + n + 1);
  for (q = 1; q <= n; q++)
    for (k = 1; k <= n; k++) a[q][k] = inf;
  a[1][1] = mas[1].c;
  h[1] = mas[1].c;
  for (i = 2; i <= n; i++) {
    a[i][i] = h[i - 1] + mas[i].c;
    h[i] = inf;
    for (k = 1; k <= i - 1; k++) {
      a[i][k] = a[i - 1][k] + mas[i].x - mas[k].x;
      h[i] = min(h[i], a[i][k]);
    }
  }
  long long best = inf;
  for (i = 1; i <= n; i++) best = min(best, a[n][i]);
  cout << best;
}
