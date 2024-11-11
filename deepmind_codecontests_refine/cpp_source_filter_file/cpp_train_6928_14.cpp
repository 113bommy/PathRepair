#include <bits/stdc++.h>
constexpr long double EPS(1e-6l);
long double ox, oy;
struct vector {
  int x, y;
  constexpr vector() : x(), y() {}
  constexpr vector(const int &x, const int &y) : x(x), y(y) {}
  friend constexpr long long operator*(const vector &x, const vector &y) {
    return 1ll * x.x * y.y - 1ll * x.y * y.x;
  }
};
struct point {
  int x, y;
  long double a;
  constexpr point() : x(), y(), a() {}
  inline point(const int &x, const int &y)
      : x(x), y(y), a(atan2(y - oy, x - ox)) {}
  friend constexpr vector operator-(const point &x, const point &y) {
    return vector(x.x - y.x, x.y - y.y);
  }
  friend constexpr bool operator<(const point &x, const point &y) {
    return (x.a < y.a - EPS) || ((x.a < y.a + EPS) && (x.x < y.x));
  }
};
using set = std::set<point>;
using iterator = set::const_iterator;
set st;
iterator low, up, cur;
inline int read() {
  static int ch, x, f;
  f = 1;
  while (!isdigit(ch = getchar())) f = ch ^ 45;
  x = ch ^ 48;
  while (isdigit(ch = getchar())) x = (((x << 2) + x) << 1) + (ch ^ 48);
  return f ? x : -x;
}
int main() {
  int n = read() - 3;
  const int x_1((read(), read())), y_1(read()), x_2((read(), read())),
      y_2(read()), x_3((read(), read())), y_3(read());
  ox = (x_1 + x_2 + x_3) / 3.l;
  oy = (y_1 + y_2 + y_3) / 3.l;
  st.insert(point(x_1, y_1));
  st.insert(point(x_2, y_2));
  st.insert(point(x_3, y_3));
  while (n--) {
    const int opt(read()), x(read()), y(read());
    const point p(x, y);
    up = st.lower_bound(p);
    if (up == st.cend()) up = st.cbegin();
    low = up;
    if (low == st.cbegin()) low = st.cend();
    --low;
    if (opt == 1) {
      if ((p - *low) * (*up - p) > 0) {
        st.insert(p);
        cur = st.find(p);
        up = cur;
        if (up == st.cbegin()) up = st.cend();
        --up;
        low = up;
        if (low == st.cbegin()) low = st.cend();
        --low;
        while ((*cur - *low) * (*up - *low) >= 0) {
          st.erase(up);
          up = low;
          if (low == st.cbegin()) low = st.cend();
          --low;
        }
        low = cur;
        if (++low == st.cend()) low = st.cbegin();
        up = low;
        if (++up == st.cend()) up = st.cbegin();
        while ((*cur - *up) * (*low - *up) <= 0) {
          st.erase(low);
          low = up;
          if (++up == st.cend()) up = st.cbegin();
        }
      }
    } else {
      puts(((p - *low) * (*up - p) <= 0) ? "YES" : "NO");
    }
  }
  return 0;
}
