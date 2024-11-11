#include <bits/stdc++.h>
using std::pair;
using db = long double;
using i64 = long long;
const int N = 100007;
struct vec {
  i64 x, y, z;
} a[2][N], p[2], x;
vec operator-(const vec& a, const vec& b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}
vec operator*(const vec& a, const vec& b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
i64 operator^(const vec& a, const vec& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
int n[2], o[N], s, t;
std::vector<pair<db, pair<int, int>>> vec;
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int sgn(i64 x) { return x < 0 ? -1 : x ? 1 : 0; }
int main() {
  for (int t = 0; t < 2; ++t) {
    n[t] = read();
    for (int i = 0; i < n[t]; ++i) a[t][i] = {read(), read(), read()};
    a[t][n[t]] = a[t][0], p[t] = (a[t][1] - a[t][0]) * (a[t][2] - a[t][0]);
  }
  if (x = p[0] * p[1], !(x ^ x)) return !puts("NO");
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i <= n[t]; ++i)
      o[i] = sgn((a[t][i] - a[t ^ 1][0]) ^ p[t ^ 1]);
    for (int i = 0; i < n[t]; ++i)
      if (o[i] ^ o[i + 1])
        vec.push_back(
            {(a[t][i] ^ x) + ((a[t][i + 1] - a[t][i]) ^ x) *
                                 (db)(p[t ^ 1] ^ (a[t][i] - a[t ^ 1][0])) /
                                 (p[t ^ 1] ^ (a[t][i] - a[t][i + 1])),
             {t, o[i] - o[i + 1]}});
  }
  std::sort(vec.begin(), vec.end());
  for (auto x : vec)
    x.second.first ? s += t* x.second.second : t += x.second.second;
  puts(s ? "YES" : "NO");
}
