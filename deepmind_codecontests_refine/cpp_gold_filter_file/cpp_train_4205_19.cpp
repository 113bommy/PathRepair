#include <bits/stdc++.h>
using namespace std;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
struct pt {
  int x, y;
  pt(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  inline pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
  inline long long operator^(const pt &p) const {
    return (long long)x * p.y - (long long)y * p.x;
  }
  inline long long operator*(const pt &p) const {
    return (long long)x * p.x + (long long)y * p.y;
  }
  inline bool operator==(const pt &p) const { return x == p.x && y == p.y; }
  inline double abs() const {
    return sqrt((long long)x * x + (long long)y * y + 0.0);
  }
};
const int maxn = 1000;
pt ps[maxn];
void check(pt *qs) {
  for (int i = 0; i < 5; i++)
    for (int j = i + 1; j < 5; j++)
      if (qs[i] == qs[j]) return;
  double alf = 0;
  for (int i = 0; i < 5; i++) {
    if (((qs[i + 1] - qs[i]) ^ (qs[i + 2] - qs[i + 1])) < 0) return;
    double cosa = (double)((qs[i + 1] - qs[i]) * (qs[i + 2] - qs[i + 1])) /
                  (qs[i + 2] - qs[i + 1]).abs() / (qs[i + 1] - qs[i]).abs();
    assert(cosa >= -1 - (1e-9) && cosa <= 1 + (1e-9));
    cosa = min(cosa, 1.0);
    cosa = max(cosa, -1.0);
    alf += acos(cosa);
  }
  if (fabs(alf - M_PI * (5 - 3)) > M_PI / 2) return;
  for (int i = 0; i < 5; i++) fprintf(stderr, "(%d,%d)\n", qs[i].x, qs[i].y);
  assert(0);
}
int main() {
  srand(rdtsc());
  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    fprintf(stderr, "%d %d\n", n, m);
    if (m == 3) {
      if (n >= 5) {
        printf("-1\n");
      } else {
        printf("0 0\n");
        printf("1000 0\n");
        printf("0 1000\n");
        if (n == 4) printf("1 1\n");
      }
      continue;
    }
    if (m == 4) {
      ps[0] = pt(-2, (int)1e8 - 4);
      ps[1] = pt(2, (int)3);
      ps[2] = pt(-(int)5e7 + 4, (int)5e7);
      ps[3] = pt((int)5e7 - 4, (int)5e7);
      if (n >= 5) ps[4] = pt(3, (int)5e7 - 3);
      if (n >= 6) ps[5] = pt(0, (int)1e8);
      if (n >= 7) ps[6] = pt((int)-1e8, 0);
      if (n >= 8) ps[7] = pt((int)1e8, 0);
    } else {
      double r = 1e7;
      for (int i = 0; i < m; i++) {
        double alf = 2 * M_PI * i / m;
        ps[i] = pt((int)(r * cos(alf)), (int)(r * sin(alf)));
      }
      for (int i = m; i < n; i++) {
        double alf = 2 * M_PI * i / m + 0.0001;
        double rt = r * (1.0 + cos(2 * M_PI / m)) / 2.0;
        ps[i] = pt((int)(rt * cos(alf)), (int)(rt * sin(alf)));
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int y = j + 1; y < n; y++) {
          assert(((ps[i] - ps[j]) ^ (ps[i] - ps[y])));
        }
    if (n <= 20 && m <= 4) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int y = 0; y < n; y++) {
            for (int k = 0; k < n; k++) {
              for (int t = 0; t < n; t++) {
                pt qs[7] = {ps[i], ps[j], ps[y], ps[k], ps[t]};
                qs[5] = qs[0];
                qs[6] = qs[1];
                check(qs);
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) printf("%d %d\n", ps[i].x, ps[i].y);
  }
  return 0;
}
