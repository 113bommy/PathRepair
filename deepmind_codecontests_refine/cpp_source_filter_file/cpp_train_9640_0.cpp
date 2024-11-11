#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int inf = (-1u) >> 1;
struct node {
  int s, i;
};
node p[maxn];
int ans[maxn], n, a, b;
bool comp1(const node& n1, const node& n2) {
  if (n1.s == n2.s) return n1.i < n2.i;
  return n1.s < n2.s;
}
bool comp2(const node& n1, const node& n2) {
  if (n1.s == n2.s) return n1.i < n2.i;
  return n1.s > n2.s;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    scanf("%d%d", &a, &b);
    for (int i = 0; i < (n); ++i) {
      scanf("%d", &p[i].s);
      p[i].i = i;
    }
    if (a == b) {
      for (int i = 0; i < (a); ++i) printf("1 ");
      for (int i = 0; i < (b); ++i) printf("1 ");
      puts("");
      continue;
    }
    if (a > b) {
      sort(p, p + n, comp1);
    } else if (a < b) {
      sort(p, p + n, comp2);
    }
    for (int i = 0; i < (a); ++i) ans[p[i].i] = 1;
    for (int i = (a); i <= (n - 1); ++i) ans[p[i].i] = 2;
    for (int i = 0; i < (n); ++i) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
  return 0;
}
