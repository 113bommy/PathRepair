#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:536870912")
using namespace std;
class Solver {
 public:
  void init() {}
  int n;
  pair<int, int> a[1000];
  int ans[1000];
  bool u[1000], u1[1000], u2[1000];
  int solve() {
    scanf("%d", &n);
    int ti;
    for (int i = 0; i < 2 * n; i++) {
      scanf("%d", &ti);
      a[i] = make_pair(ti, i);
    }
    sort(a, a + 2 * n);
    int d1 = 0, d2 = 0;
    for (int i = 0; i < 2 * n; i++) {
      for (int j = 0; j < 2 * n; j++) {
        if (u[j]) continue;
        if ((!u1[a[j].first] && u2[a[j].first] && d1 != n) ||
            (!u1[a[j].first] && !u2[a[j].first] && d1 != n && d2 != n &&
             (d1 + 1) * d2 >= d1 * (d2 + 1))) {
          ans[a[j].second] = 1;
          d1++;
          u1[a[j].first] = 1;
          u[j] = 1;
        } else if (!u2[a[j].first] && d2 != n) {
          ans[a[j].second] = 2;
          d2++;
          u2[a[j].first] = 1;
          u[j] = 1;
        }
      }
    }
    printf("%d\n", d1 * d2);
    for (int i = 0; i < 2 * n; i++) {
      if (ans[i] == 0) {
        if (d1 != n) {
          d1++;
          printf("1 ");
        } else {
          printf("2 ");
        }
      } else
        printf("%d ", ans[i]);
    }
    return 0;
  }
  void finalize() {}
};
Solver solver;
class Tester {
 public:
  void randinit() {}
  void solve_slow() {}
  void stresstest() {}
};
int main() {
  solver.init();
  solver.solve();
  solver.finalize();
  return 0;
}
