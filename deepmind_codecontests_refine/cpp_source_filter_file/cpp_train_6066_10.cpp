#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T &a) {
  return (int)a.size();
}
template <class T>
T sqr(const T &a) {
  return a * a;
}
struct SPoint {
  long long x, y;
  void scan() { cin >> x >> y; }
  bool operator==(const SPoint &p) const { return x == p.x && y == p.y; }
  void operator-=(SPoint p) {
    x -= p.x;
    y -= p.y;
  }
  long long operator&(const SPoint &p) const { return x * p.x + y * p.y; }
  long long dist2(const SPoint &p) const { return sqr(p.x - x) + sqr(y - p.y); }
};
struct SSeg {
  SPoint p1, p2;
  void scan() {
    p1.scan();
    p2.scan();
  }
  bool prov(const SPoint &p) {
    long long a = p2.y, b = -p2.x, c = 0;
    if (a * p.x + b * p.y + c != 0) return false;
    if (-p.x * (p2.x - p1.x) - p.y * (p2.y - p1.y) >= 0) return false;
    long long d1 = p1.dist2(p), d2 = p2.dist2(p);
    if (d1 > d2) swap(d1, d2);
    d2 = (d2 + 15) / 16;
    return d2 <= d1;
  }
} s[3];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 3; i++) {
      s[i].scan();
    }
    bool g = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        bool com = 0;
        if (s[i].p1 == s[j].p1) {
          com = 1;
        } else if (s[i].p1 == s[j].p2) {
          com = 1;
          swap(s[j].p1, s[j].p2);
        } else if (s[i].p2 == s[j].p1) {
          com = 1;
          swap(s[i].p1, s[i].p2);
        } else if (s[i].p2 == s[j].p2) {
          com = 1;
          swap(s[j].p1, s[j].p2);
          swap(s[i].p1, s[i].p2);
        }
        if (com) {
          swap(s[i], s[0]);
          swap(s[j], s[1]);
        } else {
          continue;
        }
        s[2].p1 -= s[0].p1;
        s[2].p2 -= s[0].p1;
        s[1].p2 -= s[1].p1;
        s[1].p1 -= s[1].p1;
        s[0].p2 -= s[0].p1;
        s[0].p1 -= s[0].p1;
        if ((s[0].p2 & s[1].p2) < 0) {
          continue;
        }
        if ((s[0].prov(s[2].p1) || s[0].prov(s[2].p2)) &&
            (s[1].prov(s[2].p1) || s[1].prov(s[2].p2))) {
          g = 1;
        }
      }
    }
    if (g) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
