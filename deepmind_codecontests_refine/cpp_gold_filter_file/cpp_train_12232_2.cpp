#include <bits/stdc++.h>
using namespace std;
bool debug;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
struct P {
  long long x, y;
  int i;
  P(long long a, long long b, int c) {
    x = a;
    y = b;
    i = c;
  }
  long long operator*(const P &b) const {
    return (long long)x * b.y - (long long)y * b.x;
  }
  P operator-(const P &b) const { return P(x - b.x, y - b.y, -1); }
  bool operator==(const P &b) const { return x == b.x && y == b.y; }
};
const int zly = 0;
void zluj(int &a) { a = zly; }
vector<P> hull(vector<P> w) {
  sort(w.begin(), w.end(), [](const P &a, const P &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });
  vector<P> razem;
  for (int _ = 0; _ <= (2) - 1; ++_) {
    vector<P> h;
    for (auto &C : w) {
      if (!h.empty() && h.back() == C) {
        if (h.back().i != C.i) zluj(h.back().i);
        continue;
      }
      while ((int)h.size() >= 2) {
        P A = h[(int)h.size() - 2];
        P B = h[(int)h.size() - 1];
        if ((B - A) * (C - A) <= 0) break;
        h.pop_back();
      }
      h.push_back(C);
    }
    for (int i = 0; i <= ((int)h.size() - 1) - 1; ++i) razem.push_back(h[i]);
    reverse(w.begin(), w.end());
  }
  return razem;
}
int main(int argc, char *argv[]) {
  debug = argc > 1;
  int n[2];
  for (int i = 0; i <= (2) - 1; ++i) scanf("%d", &n[i]);
  int rr, rrr;
  scanf("%d%d", &rr, &rrr);
  vector<P> w;
  long long maxx = 0, maxy = 0;
  for (int r = 0; r <= (2) - 1; ++r)
    for (int i = 0; i <= (n[r]) - 1; ++i) {
      long long x, y;
      scanf("%lld%lld", &x, &y);
      maxx = max(maxx, x);
      maxy = max(maxy, y);
      w.push_back(P(x, y, r));
    }
  w.push_back(P(0LL, 0LL, 2));
  w.push_back(P(maxx, 0LL, 2));
  w.push_back(P(0LL, maxy, 2));
  w = hull(w);
  for (P p : w)
    if (p.i == zly) {
      puts("Max");
      return 0;
    }
  puts("Min");
  return 0;
}
