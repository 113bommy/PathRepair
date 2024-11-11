#include <bits/stdc++.h>
using namespace std;
inline istream &operator>>(istream &in, pair<long long, long long> &p) {
  return in >> p.first >> p.second;
}
inline pair<long long, long long> operator+(
    const pair<long long, long long> &a, const pair<long long, long long> &b) {
  return pair<long long, long long>(a.first + b.first, a.second + b.second);
}
inline pair<long long, long long> operator-(
    const pair<long long, long long> &a, const pair<long long, long long> &b) {
  return pair<long long, long long>(a.first - b.first, a.second - b.second);
}
inline long long operator*(const pair<long long, long long> &a,
                           const pair<long long, long long> &b) {
  return a.first * b.first + a.second * b.second;
}
inline long long operator/(const pair<long long, long long> &a,
                           const pair<long long, long long> &b) {
  return a.first * b.second - a.second * b.first;
}
const int MAXN = 5e4 + 10;
int n1, n2, n3, n;
pair<long long, long long> p1[MAXN], p2[MAXN], p3[MAXN], tmp[MAXN], e1[MAXN],
    e2[MAXN], e3[MAXN], p[MAXN];
inline bool incov(int n, pair<long long, long long> *p,
                  pair<long long, long long> q) {
  long long res2 = (q - p[1]) / (p[2] - p[1]),
            resn = (p[n] - p[1]) / (q - p[1]);
  if (res2 > 0 || resn > 0) return 0;
  if (res2 == 0) return (q - p[2]) * (p[1] - q) >= 0;
  if (resn == 0) return (q - p[1]) * (p[n] - q) >= 0;
  int pos = lower_bound(p + 2, p + n, q,
                        [&](const pair<long long, long long> &a,
                            const pair<long long, long long> &b) {
                          return (a - p[1]) / (b - p[1]) > 0;
                        }) -
            p - 1;
  long long res = (q - p[pos]) / (p[pos + 1] - q);
  return res ? res < 0 : (p[pos] - q) * (q - p[pos + 1]) >= 0;
}
inline void Andrew(int &n, pair<long long, long long> *p) {
  sort(p + 1, p + 1 + n,
       [](const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
         return a.first != b.first ? a.first < b.first : a.second < b.second;
       });
  int cur = 0;
  tmp[cur = 1] = p[1];
  for (int i = 2, lst = cur; i <= n; tmp[++cur] = p[i++])
    while (cur > lst && (tmp[cur] - tmp[cur - 1]) / (p[i] - tmp[cur]) <= 0)
      --cur;
  for (int i = n - 1, lst = cur; i >= 1; tmp[++cur] = p[i--])
    while (cur > lst && (tmp[cur] - tmp[cur - 1]) / (p[i] - tmp[cur]) <= 0)
      --cur;
  n = cur - 1;
  if ((tmp[2] - tmp[1]) / (tmp[3] - tmp[2]) < 0) reverse(tmp + 2, tmp + 1 + n);
  for (int i = 1; i <= n; ++i) p[i] = tmp[i];
}
inline void Minkowski() {
  int q1 = 1, q2 = 1, q3 = 1, cur = 0;
  n = n1 + n2 + n3;
  p[cur = 1] = p1[1] + p2[1] + p3[1];
  while (q1 <= n1 && q2 <= n2 && q3 <= n3)
    if (e1[q1] / e2[q2] > 0 && e1[q1] / e3[q3] > 0)
      p[cur + 1] = e1[q1++] + p[cur], ++cur;
    else if (e2[q2] / e3[q3] > 0)
      p[cur + 1] = e2[q2++] + p[cur], ++cur;
    else
      p[cur + 1] = e3[q3++] + p[cur], ++cur;
  while (q1 <= n1 && q2 <= n2)
    if (e1[q1] / e2[q2] > 0)
      p[cur + 1] = e1[q1++] + p[cur], ++cur;
    else
      p[cur + 1] = e2[q2++] + p[cur], ++cur;
  while (q1 <= n1 && q3 <= n3)
    if (e1[q1] / e3[q3] > 0)
      p[cur + 1] = e1[q1++] + p[cur], ++cur;
    else
      p[cur + 1] = e3[q3++] + p[cur], ++cur;
  while (q3 <= n3 && q2 <= n2)
    if (e3[q3] / e2[q2] > 0)
      p[cur + 1] = e3[q3++] + p[cur], ++cur;
    else
      p[cur + 1] = e2[q2++] + p[cur], ++cur;
  while (q1 <= n1) p[cur + 1] = e1[q1++] + p[cur], ++cur;
  while (q2 <= n2) p[cur + 1] = e2[q2++] + p[cur], ++cur;
  while (q3 <= n3) p[cur + 1] = e3[q3++] + p[cur], ++cur;
  Andrew(n, p);
}
inline void inputcov(int &n, pair<long long, long long> *p,
                     pair<long long, long long> *e) {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  Andrew(n, p);
  for (int i = 1; i < n; ++i) e[i] = p[i + 1] - p[i];
  e[n] = p[1] - p[n];
}
inline void init() {
  inputcov(n1, p1, e1);
  inputcov(n2, p2, e2);
  inputcov(n3, p3, e3);
  Minkowski();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  int q;
  cin >> q;
  pair<long long, long long> v;
  while (q-- && cin >> v)
    if (incov(n, p, pair<long long, long long>(3 * v.first, 3 * v.second)))
      cout << "YES\n";
    else
      cout << "NO\n";
  cout.flush();
  return 0;
}
