#include <bits/stdc++.h>
using namespace std;
struct bulb {
  long long x;
  long long y;
  long long val;
};
struct QUERY {
  long long x1, y1, x2, y2;
  long long swi;
} q[1000008];
vector<bulb> vb[3008];
long long tree[3008][3008];
long long n, m, gs;
long long lowbit(long long x) { return x & (-x); }
void upd(long long x, long long y, long long val) {
  for (long long i = x; i <= n; i += lowbit(i))
    for (long long j = y; j <= m; j += lowbit(j)) tree[i][j] += val;
}
long long ask(long long x, long long y) {
  long long sum = 0;
  for (long long i = x; i; i -= lowbit(i))
    for (long long j = y; j; j -= lowbit(j)) sum += tree[i][j];
  return sum;
}
long long devote[3008][3008];
long long light[3008];
long long refer[1000008];
char buf[489];
long long Q;
int main() {
  cin >> n >> m >> gs;
  for (long long i = 1; i <= gs; i++) {
    long long len;
    scanf("%lld", &len);
    while (len--) {
      long long x, y, v;
      scanf("%lld%lld%lld", &x, &y, &v);
      bulb b;
      b.x = x, b.y = y, b.val = v;
      vb[i].push_back(b);
    }
  }
  cin >> Q;
  vector<long long> needs;
  for (long long i = 1; i <= Q; i++) {
    scanf("%s", buf);
    if (buf[0] == 'S') {
      q[i].x1 = q[i].y1 = q[i].x2 = q[i].y2 = 0;
      scanf("%lld", &q[i].swi);
    } else {
      q[i].swi = 0;
      needs.push_back(i);
      refer[i] = needs.size() - 1;
      scanf("%lld %lld %lld %lld", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
    }
  }
  for (long long i = 1; i <= gs; i++) {
    for (long long j = 0; j < vb[i].size(); j++) {
      bulb b = vb[i][j];
      upd(b.x, b.y, b.val);
    }
    for (long long j = 0; j < needs.size(); j++) {
      QUERY op = q[needs[j]];
      devote[i][j] = ask(op.x2, op.y2) + ask(op.x1 - 1, op.y1 - 1) -
                     ask(op.x2, op.y1 - 1) - ask(op.x1 - 1, op.y2);
    }
    for (long long j = 0; j < vb[i].size(); j++) {
      bulb b = vb[i][j];
      upd(b.x, b.y, -b.val);
    }
  }
  for (long long i = 1; i <= gs; i++) light[i] = 1;
  for (long long i = 1; i <= Q; i++) {
    QUERY op = q[i];
    if (op.swi)
      light[op.swi] ^= 1;
    else {
      long long ans = 0;
      for (long long j = 1; j <= gs; j++)
        if (light[j]) ans += devote[j][refer[i]];
      printf("%lld\n", ans);
    }
  }
  return 0;
}
