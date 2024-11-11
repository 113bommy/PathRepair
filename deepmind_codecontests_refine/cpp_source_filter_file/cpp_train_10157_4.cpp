#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void upmax(T &first, T second) {
  first < second ? first = second : 0;
}
template <typename T>
inline void upmin(T &first, T second) {
  first > second ? first = second : 0;
}
const int inf = 0x3f3f3f3f;
const int N = 105;
int n, v[N * 2], id[N * 2], rk[N * 2];
inline bool cmp(int a, int b) {
  return v[a] > v[b] or (v[a] == v[b] and a % n < b % n);
}
int main() {
  scanf("%d", &n);
  for (int i = (0), _ = (n); i < _; ++i)
    scanf("%d%d", &v[i], &v[i + n]), v[i + n] += v[i];
  for (int i = (0), _ = (n + n); i < _; ++i) id[i] = i;
  sort(id, id + n * 2, cmp);
  for (int i = (0), _ = (n + n); i < _; ++i) rk[id[i]] = i;
  int ans = 0;
  for (int i = (0), _ = (n); i < _; ++i)
    for (int j = (0), _ = (i); j < _; ++j) {
      int l = rk[i], r = rk[i + n];
      int first = rk[j], second = rk[j + n];
      if (l > r) swap(l, r);
      if (first > second) swap(first, second);
      if (r < first or second < l) continue;
      ans++;
      if (((l < first) ^ (second < r))) {
        if (!((l == rk[i]) ^ (first == rk[j + n]))) {
          ans++;
        }
      }
    }
  printf("%d\n", ans);
  return 0;
}
