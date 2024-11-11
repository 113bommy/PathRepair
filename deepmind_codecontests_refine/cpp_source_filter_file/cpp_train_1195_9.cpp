#include <bits/stdc++.h>
using namespace std;
int64_t gcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int64_t x1, y1;
  int64_t d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
bool find_any_solution(int64_t a, int64_t b, int64_t c, int64_t& x0,
                       int64_t& y0, int64_t& g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g != 0) return false;
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 *= -1;
  if (b < 0) y0 *= -1;
  return true;
}
void shift_solution(int64_t& x, int64_t& y, int64_t a, int64_t b, int64_t cnt) {
  x += cnt * b;
  y -= cnt * a;
}
int64_t find_all_solutions(int64_t a, int64_t b, int64_t c, int64_t minx,
                           int64_t maxx, int64_t miny, int64_t maxy) {
  int64_t x, y, g;
  if (!find_any_solution(a, b, c, x, y, g)) return 0;
  a /= g;
  b /= g;
  int64_t sign_a = a > 0 ? +1 : -1;
  int64_t sign_b = b > 0 ? +1 : -1;
  shift_solution(x, y, a, b, (minx - x) / b);
  if (x < minx) shift_solution(x, y, a, b, sign_b);
  if (x > maxx) return 0;
  int64_t lx1 = x;
  shift_solution(x, y, a, b, (maxx - x) / b);
  if (x > maxx) shift_solution(x, y, a, b, -sign_b);
  int64_t rx1 = x;
  shift_solution(x, y, a, b, -(miny - y) / a);
  if (y < miny) shift_solution(x, y, a, b, -sign_a);
  if (y > maxy) return 0;
  int64_t lx2 = x;
  shift_solution(x, y, a, b, -(maxy - y) / a);
  if (y > maxy) shift_solution(x, y, a, b, sign_a);
  int64_t rx2 = x;
  if (lx2 > rx2) swap(lx2, rx2);
  int64_t lx = max(lx1, lx2);
  int64_t rx = min(rx1, rx2);
  return (rx - lx) / abs(b) + 1;
}
int main(int, char**) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  int64_t m;
  cin >> m;
  int64_t h1, a1;
  cin >> h1 >> a1;
  int64_t x1, y1;
  cin >> x1 >> y1;
  int64_t h2, a2;
  cin >> h2 >> a2;
  int64_t x2, y2;
  cin >> x2 >> y2;
  int64_t c1, c2;
  int64_t steps;
  int64_t* d1 = new int64_t[m * 2];
  memset(d1, 0, m * 2 * sizeof(int64_t));
  steps = 0;
  while (true) {
    steps += 1;
    h1 = (x1 * h1 + y1) % m;
    int64_t level = 0;
    level += d1[h1 + level * m] > 0;
    level += d1[h1 + level * m] > 0;
    if (level == 2) break;
    d1[h1 + m * level] = steps;
  }
  int64_t* d2 = new int64_t[m * 2];
  memset(d2, 0, m * 2 * sizeof(int64_t));
  steps = 0;
  while (true) {
    steps += 1;
    h2 = (x2 * h2 + y2) % m;
    int64_t level = 0;
    level += d2[h2 + level * m] > 0;
    level += d2[h2 + level * m] > 0;
    if (level == 2) break;
    d2[h2 + level * m] = steps;
  }
  cerr << "a1=" << a1 << ", "
       << "a2=" << a2 << ", "
       << "d1[a1]=" << d1[a1] << ", "
       << "d1[a1+m]=" << d1[a1 + m] << ", "
       << "d2[a2]=" << d2[a2] << ", "
       << "d2[a2+m]=" << d2[a2 + m] << ", " << endl;
  if (d1[a1] == 0 || d2[a2] == 0) {
    cout << -1 << endl;
    return 0;
  }
  if (d1[a1 + m] == 0 && d2[a2 + m] == 0 && d1[a1] != d2[a2]) {
    cout << -1 << endl;
    return 0;
  }
  if (d1[a1] == d2[a2]) {
    cout << d1[a1] << endl;
    return 0;
  }
  if (d1[a1] == d2[a2 + m]) {
    cout << d1[a1] << endl;
    return 0;
  }
  if (d1[a1 + m] == d2[a2]) {
    cout << d1[a1 + m] << endl;
    return 0;
  }
  if (d1[a1 + m] == d2[a2 + m]) {
    cout << d1[a1 + m] << endl;
    return 0;
  }
  if (d1[a1 + m] != 0 && d2[a2 + m] != 0) {
    int64_t c1 = d1[a1 + m] - d1[a1];
    int64_t c2 = d2[a2 + m] - d2[a2];
    cerr << "c1=" << c1 << ", "
         << "c2=" << c2 << ", " << endl;
    int64_t q1, q2, g;
    if (find_any_solution(c1, -c2, d2[a2] - d1[a1], q1, q2, g)) {
      set<int64_t> best;
      double k1 = (q1 - d2[a2]) * g / double(c2);
      double k2 = (q2 - d1[a1]) * g / double(c1);
      int64_t kk = min(k1, k2);
      for (int64_t k = kk - 10; k < kk + 10; ++k) {
        int64_t w1 = (q1 + k * (-c2) / g);
        int64_t w2 = (q2 - k * (c1) / g);
        int64_t p1 = c1 * w1 + d1[a1];
        int64_t p2 = c2 * w2 + d2[a2];
        cerr << "k1=" << k1 << ", "
             << "k2=" << k2 << ", "
             << "k=" << k << ", "
             << "g=" << g << ", "
             << "q1=" << q1 << ", "
             << "q2=" << q2 << ", "
             << "w1=" << w1 << ", "
             << "w2=" << w2 << ", "
             << "p1=" << p1 << ", "
             << "p2=" << p2 << ", " << endl;
        if (p1 >= d1[a1] && p2 >= d2[a2]) best.insert(p1);
      }
      cout << *best.begin() << endl;
    } else
      cout << -1 << endl;
  } else {
    if (d1[a1 + m] > 0) {
      int64_t c1 = d1[a1 + m] - d1[a1];
      if (d2[a2] > d1[a1] && (d2[a2] - d1[a1] % c1 == 0)) {
        cout << d2[a2] << endl;
      } else {
        cout << -1 << endl;
      }
    } else if (d2[a2 + m] > 0) {
      int64_t c2 = d2[a2 + m] - d2[a2];
      if (d1[a1] > d2[a2] && (d1[a1] - d2[a2] % c2 == 0)) {
        cout << d1[a1] << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
