#include <bits/stdc++.h>
const int maxn = 100010;
using namespace std;
map<pair<int, int>, pair<int, int> > edge;
int n, ans, r1, r2, a, b, c;
void upd1(int a, int b, int c, int i) {
  if (min(edge[make_pair(a, b)].first + c, min(a, b)) > ans) {
    ans = min(edge[make_pair(a, b)].first + c, min(a, b));
    r1 = edge[make_pair(a, b)].second;
    r2 = i;
  }
}
void upd2(int a, int b, int c, int i) {
  if (edge[make_pair(a, b)].first < c) edge[make_pair(a, b)] = make_pair(c, i);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    upd1(a, b, c, i);
    upd2(a, b, c, i);
  }
  if (r1 != 0 && r2 != 0) {
    printf("2\n%d %d\n", r1, r2);
  } else {
    printf("1\n%d\n", r2);
  }
  return 0;
}
