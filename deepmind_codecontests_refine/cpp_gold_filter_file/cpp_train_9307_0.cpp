#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
pair<int, int> p[310000][2];
pair<int, int> c[1600];
int r[1600];
int m;
pair<pair<int, int>, pair<int, int> > mem[1600 * 1600];
double dist(pair<int, int> a, pair<int, int> b) {
  return hypot(a.first - b.first, a.second - b.second);
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int N, M, i, j;
  int first, second, d, xx, yy;
  pair<int, int> q;
  long long ans;
  scanf("%d%d", &N, &M);
  for (i = 0; i < N; i++) {
    scanf("%d%d", &first, &second);
    p[i][0] = pair<int, int>(first * 2, second * 2);
    scanf("%d%d", &first, &second);
    p[i][1] = pair<int, int>(first * 2, second * 2);
  }
  for (i = 0; i < M; i++) {
    scanf("%d%d%d", &first, &second, &r[i]);
    c[i] = pair<int, int>(first * 2, second * 2);
    r[i] *= 2;
  }
  m = 0;
  for (i = 0; i < M; i++)
    for (j = i + 1; j < M; j++) {
      if (dist(c[i], c[j]) < r[i] + r[j] + 1e-9) continue;
      if (r[i] != r[j]) continue;
      q = pair<int, int>((c[i].first + c[j].first) / 2,
                         (c[i].second + c[j].second) / 2);
      first = c[i].second - c[j].second;
      second = c[j].first - c[i].first;
      d = gcd(first, second);
      first /= d;
      second /= d;
      if (first < 0) first = -first, second = -second;
      xx = q.first * second - q.second * first;
      yy = q.first * first + q.second * second;
      mem[m++] = pair<pair<int, int>, pair<int, int> >(
          pair<int, int>(first, second), pair<int, int>(xx, yy));
    }
  sort(mem, mem + m);
  ans = 0;
  for (i = 0; i < N; i++) {
    first = p[i][0].first - p[i][1].first;
    second = p[i][0].second - p[i][1].second;
    d = gcd(first, second);
    first /= d;
    second /= d;
    if (first < 0) first = -first, second = -second;
    p[i][0] = pair<int, int>(p[i][0].first * second - p[i][0].second * first,
                             p[i][0].first * first + p[i][0].second * second);
    p[i][1] = pair<int, int>(p[i][1].first * second - p[i][1].second * first,
                             p[i][1].first * first + p[i][1].second * second);
    if (p[i][0] > p[i][1]) swap(p[i][0], p[i][1]);
    ans += upper_bound(mem, mem + m,
                       pair<pair<int, int>, pair<int, int> >(
                           pair<int, int>(first, second), p[i][1])) -
           lower_bound(mem, mem + m,
                       pair<pair<int, int>, pair<int, int> >(
                           pair<int, int>(first, second), p[i][0]));
  }
  printf("%I64d\n", ans);
  return 0;
}
