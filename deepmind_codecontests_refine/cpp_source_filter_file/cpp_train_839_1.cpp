#include <bits/stdc++.h>
using namespace std;
struct node {
  long long f, s;
} a[20010];
bool mmp(node x, node y) {
  if (x.f != y.f) return x.f < y.f;
  return x.s > y.s;
}
int main() {
  int t;
  scanf("%d", &t);
  long long l, r;
  for (int i = 1; i <= 2 * t; i += 2) {
    a[i].s = 1;
    a[i + 1].s = 0;
    scanf("%lld%lld", &a[i].f, &a[i + 1].f);
    a[i].f--;
    a[i + 1].f;
  }
  long long ans = 0;
  long long b[40000] = {0};
  sort(a + 1, a + t * 2 + 1, mmp);
  for (int i = 1; i < 2 * t; i++) {
    if (a[i].s) {
      ans++;
    } else {
      ans--;
    }
    b[ans] += (a[i + 1].f - a[i].f);
  }
  printf("%d", b[1]);
  for (int i = 2; i <= t; i++) {
    printf(" %d", b[i]);
  }
  printf("\n");
  return 0;
}
