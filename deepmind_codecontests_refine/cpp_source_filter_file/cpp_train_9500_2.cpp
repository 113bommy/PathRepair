#include <bits/stdc++.h>
using namespace std;
pair<int, int> pts[8];
int cross(pair<int, int> a, pair<int, int> b) {
  return a.first * b.second - a.second * b.first;
}
int dot(pair<int, int> a, pair<int, int> b) {
  return a.first * b.first + a.second * b.second;
}
inline int sqr(const int& a) { return a * a; }
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return pair<int, int>(b.first - a.first, b.second - a.second);
}
int geoType(int* perm) {
  pair<int, int>&a = pts[perm[0]], b = pts[perm[1]], c = pts[perm[2]],
            d = pts[perm[3]];
  if (cross(b - a, d - c) == 0 && cross(d - a, b - c) == 0 &&
      dot(b - a, c - a) == 0) {
    if (sqr(a.first - b.first) + sqr(a.second - b.second) ==
        sqr(b.first - c.first) + sqr(b.second - c.second)) {
      return 2;
    }
    return 1;
  }
  return 0;
}
int main() {
  int perm[8] = {0, 1, 2, 3, 4, 5, 6, 7}, i;
  for (i = 0; i < 8; ++i) {
    scanf("%d%d", &pts[i].first, &pts[i].second);
  }
  do {
    if (geoType(perm) == 2 && geoType(perm + 4) >= 1) {
      puts("YES");
      for (i = 0; i < 8;) {
        printf("%d", perm[i] + 1);
        putchar(++i % 4 == 0 ? '\n' : ' ');
      }
      return 0;
    }
  } while (next_permutation(perm, perm + 8));
  puts("NO");
  return 0;
}
