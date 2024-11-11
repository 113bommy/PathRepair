#include <bits/stdc++.h>
using namespace std;
char* ssg = new char[3];
struct type {
  long x, y, c, n;
};
bool myc(type p1, type p2) { return p1.c < p2.c; }
long i, j, k, l, m, n, d, a, b;
type p[100001];
int main() {
  scanf("%ld", &n);
  scanf("%ld", &d);
  scanf("%ld", &a);
  scanf("%ld", &b);
  for (long i = 0; i < n; i++) {
    scanf("%ld%ld", &p[i].x, &p[i].y);
    p[i].c = p[i].x * a + p[i].y * b;
    p[i].n = i + 1;
  }
  sort(p, p + n, myc);
  vector<long> ans;
  long bs = 0;
  for (long i = 0; i < n; i++) {
    bs += p[i].c;
    if (bs <= d) ans.push_back(p[i].n);
  }
  printf("%ld\n", ans.size());
  for (long i = 0; i < ans.size(); i++) printf("%ld ", ans[i]);
  return 0;
}
