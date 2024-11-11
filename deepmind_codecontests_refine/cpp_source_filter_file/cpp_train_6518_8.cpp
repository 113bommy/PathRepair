#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
struct PT {
  int a, b, c, d, e, id;
};
bool check(PT p1, PT p2, PT p3) {
  int x1 = (p2.a - p1.a) * (p3.a - p1.a);
  int x2 = (p2.b - p1.b) * (p3.b - p1.b);
  int x3 = (p2.c - p1.c) * (p3.c - p1.c);
  int x4 = (p2.d - p1.d) * (p3.d - p1.d);
  int x5 = (p2.e - p1.e) * (p3.e - p1.e);
  int x = x1 + x2 + x3 + x4 + x5;
  return x <= 0;
}
int main() {
  int n;
  scanf("%d", &n);
  PT p[n + 5];
  for (int i = 1; i <= n; i++) {
    int a, b, c, d, e;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    scanf("%d", &e);
    p[i].a = a;
    p[i].b = b;
    p[i].c = c;
    p[i].d = d;
    p[i].e = e;
    p[i].id = i;
  }
  if (n == 1)
    printf("1\n1\n");
  else if (n == 2)
    printf("2\n1 2\n");
  else {
    int taken[n + 5];
    memset(taken, 0, sizeof(taken));
    for (int i = 1; i <= n; i++) {
      if (!taken[i]) {
        for (int j = 1; j <= n; j++) {
          for (int k = 1; k <= n; k++) {
            if (i != j && i != k && j != k) {
              if (check(p[i], p[j], p[k])) taken[i] = 1;
              if (check(p[j], p[i], p[k])) taken[j] = 1;
              if (check(p[k], p[j], p[i])) taken[k] = 1;
            }
          }
        }
      }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
      if (taken[i]) ans.push_back(i);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i]);
    if ((int)ans.size()) printf("\n");
  }
  return 0;
}
