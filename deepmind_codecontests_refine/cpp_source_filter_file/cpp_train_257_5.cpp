#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
struct node {
  double x;
  int flag;
} q[350000];
bool cmp(node a, node b) { return a.x > b.x; }
int cnt;
long long cntzero1, cntzero2;
int r[350000], w[350000];
int fir[350000], las[350000];
long long fsum1[350000], fsum2[350000], lsum1[350000], lsum2[350000], ans;
int main() {
  int n, c, d;
  scanf("%d%d%d", &n, &c, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &r[i], &w[i]);
    r[i] -= c, w[i] -= d;
    if (w[i] == 0) {
      r[i] > 0 ? cntzero1++ : cntzero2++;
    } else {
      q[++cnt].x = r[i] * 1.0 / w[i];
      w[i] > 0 ? q[cnt].flag = 1 : q[cnt].flag = -1;
    }
  }
  sort(q + 1, q + cnt + 1, cmp);
  int j;
  for (int i = 1; i <= cnt; i = j + 1) {
    j = i;
    while (j + 1 <= cnt && fabs(q[j + 1].x - q[i].x) < eps) j++;
    for (int k = i; k <= j; k++) {
      fir[k] = i, las[k] = j;
    }
  }
  for (int i = 1; i <= cnt; i++) {
    fsum1[i] = fsum1[i - 1], fsum2[i] = fsum2[i - 1];
    q[i].flag > 0 ? fsum1[i]++ : fsum2[i]++;
  }
  for (int i = cnt; i >= 1; i--) {
    lsum1[i] = lsum1[i + 1], lsum2[i] = lsum2[i + 1];
    q[i].flag > 0 ? lsum1[i]++ : lsum2[i]++;
  }
  for (int i = 1; i <= cnt; i++) {
    (q[i].flag > 0) ? ans += fsum2[fir[i] - 1] * lsum2[las[i] + 1]
                    : ans += fsum1[fir[i] - 1] * lsum1[las[i] + 1];
  }
  long long num1 = 0, num2 = 0;
  for (int i = 1; i <= cnt; i++) {
    if (q[i].flag > 0)
      num1 += fsum2[fir[i] - 1];
    else
      num2 += fsum1[fir[i] - 1];
  }
  ans += cntzero1 * num1 + cntzero2 * num2;
  printf("%lld\n", ans);
  return 0;
}
