#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long INF = 2e18;
int n;
long long a[N], s[N << 2], flag[N << 2], f[N];
void pushUp(int rt) {
  s[rt] = min(s[rt << 1], s[rt << 1 | 1]);
  flag[rt] = min(flag[rt << 1], flag[rt << 1 | 1]);
}
long long get(int p) {
  long long sum = 0;
  for (; p; p -= p & -p) sum += f[p];
  return sum;
}
void add(int p, long long x) {
  for (; p < N; p += p & -p) f[p] += x;
}
void change(int l, int rt) {
  if (l == 1) {
    long long s1 = get(l) + a[l], s2 = get(l + 1) + a[l + 1];
    if (s1 >= s2)
      s[rt] = 0;
    else
      s[rt] = s2 - s1;
    flag[rt] = l;
  } else if (l == n) {
    long long s1 = get(l) + a[l], s2 = get(l - 1) + a[l - 1];
    if (s1 >= s2)
      s[rt] = 0;
    else
      s[rt] = s2 - s1;
    flag[rt] = l;
  } else {
    long long s1 = get(l) + a[l], s2 = get(l + 1) + a[l + 1],
              s3 = get(l - 1) + a[l - 1];
    if (s1 >= s3 && s1 >= s2)
      s[rt] = 0;
    else if (s1 >= s2)
      s[rt] = s3 - s1;
    else if (s1 >= s3)
      s[rt] = s2 - s1;
    else
      s[rt] = INF;
    if (s1 < s2 && s1 < s3)
      flag[rt] = -l;
    else
      flag[rt] = l;
  }
}
void build(int l, int r, int rt) {
  if (l == r) {
    change(l, rt);
  } else {
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushUp(rt);
  }
}
void update(int p, int l, int r, int rt) {
  if (l == r) {
    change(l, rt);
  } else {
    int m = l + r >> 1;
    if (p <= m)
      update(p, l, m, rt << 1);
    else
      update(p, m + 1, r, rt << 1 | 1);
    pushUp(rt);
  }
}
pair<long long, long long> query(int L, int R, int l, int r, int rt) {
  if (l >= L && r <= R) {
    return pair<long long, long long>(flag[rt], s[rt]);
  } else {
    int m = l + r >> 1;
    pair<long long, long long> tmp = pair<long long, long long>(INF, INF),
                               tmp2 = pair<long long, long long>(INF, INF);
    if (L <= m) tmp = query(L, R, l, m, rt << 1);
    if (R > m) tmp2 = query(L, R, m + 1, r, rt << 1 | 1);
    tmp = pair<long long, long long>(min(tmp.first, tmp2.first),
                                     min(tmp.second, tmp2.second));
    pushUp(rt);
    return tmp;
  }
}
int main() {
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (i > 1) {
      res += abs(a[i] - a[i - 1]);
    }
  }
  build(1, n, 1);
  int q;
  cin >> q;
  while (q--) {
    int t, l, r, x;
    scanf("%d%d%d%d", &t, &l, &r, &x);
    if (t == 1) {
      pair<long long, long long> p = query(l, r, 1, n, 1);
      if (p.second == 0) {
        printf("%I64d\n", res + 2LL * x);
      } else {
        long long tmp = -INF;
        if (!(p.first < 0 && l == r)) {
          if (p.second <= x)
            tmp = 2LL * (x - p.second);
          else
            tmp = 0;
        }
        if (p.first < 0) {
          p.first = -p.first;
          long long px = 0;
          long long g1 = get(p.first), g2 = get(p.first + 1),
                    g3 = get(p.first - 1);
          if (p.first != n) {
            px += abs(g1 + a[p.first] + x - a[p.first + 1] - g2) -
                  abs(g1 + a[p.first] - a[p.first + 1] - g2);
          }
          if (p.first != 1) {
            px += abs(g1 + x + a[p.first] - a[p.first - 1] - g3) -
                  abs(g1 + a[p.first] - a[p.first - 1] - g3);
          }
          tmp = max(tmp, px);
        }
        printf("%I64d\n", res + tmp);
      }
    } else {
      if (l > 1) res -= abs(a[l - 1] + get(l - 1) - a[l] - get(l));
      if (r < n) res -= abs(a[r] + get(r) - a[r + 1] - get(r + 1));
      add(l, x);
      add(r + 1, -x);
      if (l > 1) {
        update(l - 1, 1, n, 1);
        res += abs(a[l - 1] + get(l - 1) - a[l] - get(l));
      }
      update(l, 1, n, 1);
      if (l != r) update(r, 1, n, 1);
      if (r < n) {
        update(r + 1, 1, n, 1);
        res += abs(a[r] + get(r) - a[r + 1] - get(r + 1));
      }
    }
  }
  return 0;
}
