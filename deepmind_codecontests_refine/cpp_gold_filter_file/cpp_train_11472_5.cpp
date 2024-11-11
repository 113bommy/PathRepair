#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
long long int dis[int(1 << 21)], l[int(1e5 + 10)], r[int(1e5 + 10)],
    cut = 1e12L, sum0[int(1e5 + 10)] = {0}, sum1[int(1e5 + 10)] = {0},
    lsum0[int(1e5 + 10)] = {0}, lsum1[int(1e5 + 10)] = {0}, n;
int t = 0;
double cc = 1e12L;
bool check(long long int id1, long long int s1, long long int id2,
           long long int s2, long long int Knew) {
  double knew = Knew, id11 = id1, id22 = id2, s11 = s1, s22 = s2;
  knew -= id11 * s11 - sum0[id1] * 1.0 - cc * sum1[id1] * 1.0;
  knew -= lsum0[id2] * 1.0 + cc * lsum1[id2] * 1.0 - (n - id22 + 1) * s22 * 1.0;
  if (knew < 0.0) return false;
  return true;
}
int bnry1(long long int q) {
  int it = 1, f = n, m;
  while (it != f) {
    m = (it + f) / 2;
    if (r[m + 1] <= q)
      it = m + 1;
    else
      f = m;
  }
  if (r[f] > q) return 0;
  return f;
}
int bnry2(long long int q) {
  int it = 1, f = n, m;
  while (it != f) {
    m = (it + f) / 2;
    if (l[m] < q)
      it = m + 1;
    else
      f = m;
  }
  if (l[f] < q) return n + 1;
  return f;
}
int main() {
  long long int mxs = 1e18L;
  long long int k;
  scanf("%d", &n);
  ;
  cin >> k;
  for (int i = int(1); i <= (int)n; i++) {
    scanf("%lld", &l[i]);
    ;
    scanf("%lld", &r[i]);
    ;
    mxs = min(mxs, r[i] - l[i] + 1);
  }
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  for (int i = 1; i <= n; ++i) {
    sum0[i] = sum0[i - 1] + r[i] % cut;
    if (l[i] > cut) {
      long long int tmp = r[i] - (r[i] % cut);
      tmp /= cut;
      sum1[i] = sum1[i - 1] + tmp;
    }
  }
  for (int i = n; i >= 1; i--) {
    lsum0[i] = lsum0[i + 1] + l[i] % cut;
    if (l[i] > cut) {
      long long int tmp = l[i] - (l[i] % cut);
      tmp /= cut;
      lsum1[i] = lsum1[i + 1] + tmp;
    }
  }
  dis[++t] = 4;
  dis[++t] = 7;
  int prv = 1;
  for (int l = 2; l <= 18; ++l) {
    int it = prv, f = t;
    for (int j = it; j <= f; ++j) {
      dis[++t] = dis[j] * 10 + 4;
      dis[++t] = dis[j] * 10 + 7;
    }
    prv = f + 1;
  }
  int p = 1;
  for (int i = 1; i <= t; ++i) {
    while (1) {
      if (p + i - 1 > t) break;
      if (dis[p + i - 1] - dis[i] + 1 > mxs) break;
      long long int id1 = bnry1(dis[i + p - 1]);
      long long int id2 = bnry2(dis[i]);
      if (check(id1, dis[i + p - 1], id2, dis[i], k) == false) {
        break;
      }
      p++;
    }
  }
  p--;
  cout << p << endl;
  return 0;
}
