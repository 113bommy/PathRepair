#include <bits/stdc++.h>
const int N = 800054, MAX = 100000;
struct vec2 {
  int x, y;
  vec2(int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
  vec2 *read() {
    scanf("%d%d", &x, &y);
    return this;
  }
  inline vec2 operator-(const vec2 &B) const { return vec2(x - B.x, y - B.y); }
  inline long long operator^(const vec2 &B) const {
    return (long long)x * B.y - (long long)y * B.x;
  }
  inline long long norm2() const { return (long long)x * x + (long long)y * y; }
  inline bool operator<(const vec2 &B) const {
    return x < B.x || (x == B.x && y < B.y);
  }
};
inline int min(const int x, const int y) { return x < y ? x : y; }
inline int max(const int x, const int y) { return x < y ? y : x; }
int graham(int n, vec2 *p, vec2 *dest) {
  int i;
  vec2 *ret = dest;
  std::iter_swap(p, std::min_element(p, p + n));
  std::sort(p + 1, p + n, [p](const vec2 A, const vec2 B) {
    long long r = (((A) - (*p)) ^ ((B) - (*p)));
    return r > 0 || (r == 0 && (A - *p).norm2() < (B - *p).norm2());
  });
  for (i = 0; i < n; *ret++ = p[i++])
    for (; ret > dest + 1 &&
           (((p[i]) - (ret[-2])) ^ ((ret[-1]) - (ret[-2]))) >= 0;
         --ret)
      ;
  return *ret = *p, ret - dest;
}
inline long double Radius2(const vec2 A, const vec2 B, const vec2 C) {
  long long S = 2 * (((B) - (A)) ^ ((C) - (A)));
  return S ? ((long double)(A - B).norm2() * (B - C).norm2() *
              (C - A).norm2()) /
                 ((long double)S * S)
           : -INFINITY;
}
int n, CH, cnt = 0;
vec2 p[N], ch[N];
int main() {
  int i, x, y, v, d;
  long double best = 0., cur;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &v);
    x >= v ? p[cnt++] = vec2(x - v, y)
           : (d = v - x, p[cnt++] = vec2(0, max(0, y - d)),
              p[cnt++] = vec2(0, min(MAX, y + d)));
    y >= v ? p[cnt++] = vec2(x, y - v)
           : (d = v - y, p[cnt++] = vec2(max(0, x - d), 0),
              p[cnt++] = vec2(min(MAX, y + d), 0));
    x <= MAX - v ? p[cnt++] = vec2(x + v, y)
                 : (d = x + v - MAX, p[cnt++] = vec2(MAX, max(0, y - d)),
                    p[cnt++] = vec2(MAX, min(MAX, y + d)));
    y <= MAX - v ? p[cnt++] = vec2(x, y + v)
                 : (d = y + v - MAX, p[cnt++] = vec2(max(0, x - d), MAX),
                    p[cnt++] = vec2(min(MAX, x + d), MAX));
  }
  CH = graham(cnt, p, ch), assert(CH >= 3);
  std::copy(ch, ch + 3, ch + CH);
  for (d = -1, i = 0; i < CH; ++i)
    if ((cur = Radius2(ch[i], ch[i + 1], ch[i + 2])) > best) d = i, best = cur;
  assert(~d);
  printf("%d %d\n%d %d\n%d %d\n", ch[d].x, ch[d].y, ch[d + 1].x, ch[d + 1].y,
         ch[d + 2].x, ch[d + 2].y);
  return 0;
}
