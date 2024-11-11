#include <bits/stdc++.h>
using namespace std;
long long K, r[50050];
int n, v[50050], s[50050], m, P, id[50050];
pair<pair<int, int>, pair<int, int> > f[61][50050];
bool cmp(int i, int j) { return r[i] < r[j]; }
pair<pair<int, int>, pair<int, int> > multi(
    pair<pair<int, int>, pair<int, int> > a,
    pair<pair<int, int>, pair<int, int> > b) {
  int x = (1LL * a.first.first * b.first.first +
           1LL * a.second.first * b.first.second) %
          P;
  int y = (1LL * a.first.second * b.first.first +
           1LL * a.second.second * b.first.second) %
          P;
  int xx = (1LL * a.first.first * b.second.first +
            1LL * a.second.first * b.second.second) %
           P;
  int yy = (1LL * a.first.second * b.second.first +
            1LL * a.second.second * b.second.second) %
           P;
  return pair<pair<int, int>, pair<int, int> >(pair<int, int>(x, y),
                                               pair<int, int>(xx, yy));
}
void init() {
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    f[0][i] = pair<pair<int, int>, pair<int, int> >(
        pair<int, int>(0, 1 % P), pair<int, int>(s[i] % P, s[j] % P));
  }
  pair<pair<int, int>, pair<int, int> > tp, tt;
  for (int k = 1; k < 61; k++) {
    long long de = (1LL << (k - 1));
    for (int i = 0; i < n; i++) {
      tp = f[k - 1][i];
      int j = (de + i) % n;
      tt = f[k - 1][j];
      f[k][i] = multi(tp, tt);
    }
  }
}
pair<pair<int, int>, pair<int, int> > ok(int i, int r) {
  pair<pair<int, int>, pair<int, int> > rt =
      pair<pair<int, int>, pair<int, int> >(pair<int, int>(1, 0),
                                            pair<int, int>(0, 1));
  int j = 61 - 1;
  while (j >= 0) {
    if ((1LL << j) <= r) {
      rt = multi(rt, f[j][i]);
      r -= (1LL << j);
      i = (i + (1LL << j)) % n;
    }
    j--;
  }
  return rt;
}
void run() {
  long long cur = 0;
  int x = 0, y = 1 % P, xx, yy, al = -1, kk, vv;
  if (K == 0 || P == 1) {
    puts("0");
    return;
  }
  pair<pair<int, int>, pair<int, int> > o;
  for (int i = 0; i < m; i++) {
    int j = id[i];
    long long t = r[j];
    if (t >= K) t = K;
    if (r[j] > K)
      vv = s[t % n];
    else
      vv = v[j];
    if (cur + 2 <= t) {
      o = ok(cur % n, t - 1 - cur);
      cur = t - 1;
      xx = (1LL * x * o.first.first + 1LL * y * o.first.second) % P;
      yy = (1LL * x * o.second.first + 1LL * y * o.second.second) % P;
      x = xx;
      y = yy;
    }
    kk = (al < 0) ? s[cur % n] : al;
    yy = (1LL * x * kk + 1LL * y * vv) % P;
    x = y;
    y = yy;
    if (r[j] < K && min(K, r[id[i + 1]]) == t + 1) {
      cur = t;
      al = vv;
      continue;
    }
    if (t == K) break;
    cur = t + 1;
    yy = (1LL * x * vv + 1LL * y * s[cur % n]) % P;
    x = y;
    y = yy;
    al = -1;
  }
  printf("%d\n", x);
}
int main() {
  scanf("%I64d %d", &K, &P);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", s + i);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%I64d%d", &r[i], &v[i]), id[i] = i;
  id[m] = m;
  r[m++] = 1100000000000000000LL;
  sort(id, id + m, cmp);
  init();
  run();
  return 0;
}
