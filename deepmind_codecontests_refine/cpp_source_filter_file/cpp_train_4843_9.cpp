#include <bits/stdc++.h>
using namespace std;
struct node {
  long long v;
  long long id;
  long long Ans;
};
node p[100010];
long long A, n, cf, cm, m, Ans = -1, k, minx, sum[100010], pre[100010];
bool comp(const node& x, const node& y) { return x.v > y.v; }
bool back(const node& x, const node& y) { return x.id < y.id; }
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (long long i = 1; i <= n; i++)
    cin >> p[i].v, p[i].id = i, p[i].Ans = p[i].v;
  sort(p + 1, p + n + 1, comp);
  for (long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + A - p[i].v;
  for (long long i = 2; i <= n; i++)
    pre[i] = pre[i + 1] + (p[i - 1].v - p[i].v) * (n - i + 1);
  for (long long i = 0; i <= n; i++) {
    long long x = m, ret = 0;
    if (i == n) {
      if (x >= sum[n]) {
        ret = cf * n;
        ret += cm * A;
      }
      if (ret > Ans) {
        Ans = ret;
        k = i;
        minx = A;
      }
      break;
    }
    if (x < sum[i]) break;
    x -= sum[i];
    ret += cf * i;
    long long head = max(2ll, i + 1), tail = n + 1;
    while (head != tail) {
      long long Mid = (head + tail) >> 1;
      if (pre[Mid] <= x)
        tail = Mid;
      else
        head = Mid + 1;
    }
    long long len = n - head + 1;
    x -= pre[head];
    if (head - 1 > i) len++;
    ret += min(A, p[head - 1].v + (x / len)) * cm;
    if (ret > Ans) {
      Ans = ret;
      k = i;
      minx = min(A, p[head - 1].v + x / len);
    }
  }
  if (Ans != -1) {
    for (long long i = 1; i <= k; i++) p[i].Ans = A;
    for (long long i = k + 1; i <= n; i++) p[i].Ans = max(p[i].Ans, minx);
  } else
    Ans = 0;
  sort(p + 1, p + n + 1, back);
  cout << Ans << endl;
  for (long long i = 1; i <= n; i++) cout << p[i].Ans << ' ';
  return 0;
}
