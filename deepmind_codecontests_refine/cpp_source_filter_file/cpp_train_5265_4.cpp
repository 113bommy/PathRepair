#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int x[N][N];
int y[N][N];
void query(vector<int> v) {
  int sz = v.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i) printf(" ");
    printf("%d", v[i]);
  }
  puts("");
  fflush(stdout);
}
int main() {
  vector<int> a, b;
  int n;
  scanf("%d", &n);
  for (int j = 0; (1 << j) < n; j++) {
    a.clear();
    b.clear();
    for (int i = 0; i < n; i++) {
      if (i & (1 << j))
        a.push_back(i);
      else
        b.push_back(i);
    }
    query(a);
    for (int i = 0; i < n; i++) scanf("%d", &x[i][j]);
    query(b);
    for (int i = 0; i < n; i++) scanf("%d", &y[i][j]);
  }
  printf("-1\n");
  for (int i = 0; i < n; i++) {
    int ans = (int)2e9;
    for (int j = 0; (1 << j) < n; j++) {
      if (i & (1 << j))
        ans = min(ans, y[i][j]);
      else
        ans = min(ans, x[i][j]);
    }
    if (i) printf(" ");
    printf("%d", ans);
  }
  puts("");
  fflush(stdout);
  return 0;
}
