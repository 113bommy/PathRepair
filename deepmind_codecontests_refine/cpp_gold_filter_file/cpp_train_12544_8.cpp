#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
struct point {
  int x, y, kk, id;
  bool operator<(const point &a) const {
    return kk == a.kk ? y < a.y : kk < a.kk;
  }
} pp[maxn];
bool cmp1(point a, point b) { return a.x < b.x; }
bool cmp2(point a, point b) { return a.kk == b.kk ? a.y < b.y : a.kk < b.kk; }
int n, ku;
int main() {
  cin >> n;
  ku = sqrt(n + 0.0) + 10;
  for (int i = (1); i <= (n); i++) {
    scanf("%d%d", &pp[i].x, &pp[i].y);
    pp[i].id = i;
  }
  sort(pp + 1, pp + 1 + n, cmp1);
  for (int i = (1); i <= (n); i++) {
    pp[i].kk = i / ku;
  }
  sort(pp + 1, pp + 1 + n, cmp2);
  printf("%d", pp[1].id);
  for (int i = (2); i <= (n); i++) printf(" %d", pp[i].id);
  return 0;
}
