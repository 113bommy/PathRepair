#include <bits/stdc++.h>
using namespace std;
struct node {
  double value;
  long long pos;
};
const long long MAXN = 100000;
long long n;
double w;
double x[MAXN + 1], v[MAXN + 1];
node d[MAXN + 1];
long long f[MAXN + 1];
long long ans;
bool cmp(node a, node b) { return a.value < b.value; }
long long Lowbit(long long x) { return x & (-x); }
void Modify(long long pos, long long value) {
  while (pos <= n) {
    f[pos] += value;
    pos += Lowbit(pos);
  }
}
long long Sum(long long x) {
  long long rs = 0;
  while (x > 0) {
    rs += f[x];
    x -= Lowbit(x);
  }
  return rs;
}
int main(int argc, char const *argv[]) {
  scanf("%I64d%lf", &n, &w);
  w += 0.000005;
  for (long long i = 1; i <= n; i++) {
    scanf("%lf%lf", &x[i], &v[i]);
    d[i].value = x[i] / (v[i] - w);
    d[i].pos = i;
  }
  sort(d + 1, d + n + 1, cmp);
  for (long long i = 1; i <= n; i++) {
    d[i].value = x[d[i].pos] / (v[d[i].pos] + w);
    d[i].pos = i;
  }
  sort(d + 1, d + n + 1, cmp);
  for (long long i = 1; i <= n; i++) {
    ans += i - 1 - Sum(d[i].pos);
    Modify(d[i].pos, 1);
  }
  printf("%I64d\n", ans);
  return 0;
}
