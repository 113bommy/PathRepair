#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
inline pair<int, int> operator-(const pair<int, int> &a,
                                const pair<int, int> &b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
inline int vec(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first * b.second - b.first * a.second;
}
int a, b, c, d, n, m, k;
pair<int, int> mas[3005], tmp[3005], res[3005], hull[3005];
inline int dist(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
inline bool cool(pair<int, int> *mas, int n, long double xx) {
  if (n < 2) return 0;
  int k = 0;
  for (int _n((2) - 1), iter(0); iter <= _n; iter++) {
    int h = 0;
    for (int _n((n)-1), i(0); i <= _n; i++) {
      while (h >= 2 &&
             vec(mas[i] - hull[h - 1], hull[h - 1] - hull[h - 2]) <= 0)
        --h;
      hull[h++] = mas[i];
    }
    --h;
    for (int _n((h)-1), i(0); i <= _n; i++) res[k++] = hull[i];
    reverse(mas, mas + n);
  }
  if (k == 2) {
    if (dist(res[0], res[1]) >= xx)
      return 1;
    else
      return 0;
  }
  int a = 0;
  for (int _n((k)-1), i(0); i <= _n; i++) {
    if (a == i) {
      a = i + 1;
      if (a == k) a = 0;
    }
    while (1) {
      int t = a + 1;
      if (t >= k) t = 0;
      if (t == i) break;
      int s1 = dist(res[i], res[a]);
      int s2 = dist(res[i], res[t]);
      if (s2 >= s1)
        a = t;
      else
        break;
    }
    if (dist(res[i], res[a]) >= xx) return 1;
  }
  return 0;
}
inline bool check(long double xx) {
  for (int _n((n)-1), v(0); v <= _n; v++) {
    int k = 0;
    for (int _n(n - 1), i(v + 1); i <= _n; i++) {
      int s = (mas[v].first - mas[i].first) * (mas[v].first - mas[i].first) +
              (mas[v].second - mas[i].second) * (mas[v].second - mas[i].second);
      if (s >= xx) {
        tmp[k++] = mas[i];
      }
    }
    if (cool(tmp, k, xx)) return 1;
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int _n((n)-1), i(0); i <= _n; i++) {
    scanf("%d%d", &mas[i].first, &mas[i].second);
  }
  sort(mas, mas + n);
  long double l = 0.0, r = 29000;
  for (int _n((35) - 1), hhod(0); hhod <= _n; hhod++) {
    long double xx = (r + l) / 2.0;
    if (check(xx * xx * 4))
      l = xx;
    else
      r = xx;
  }
  printf("%.12lf\n", (double)((l + r) / 2));
}
