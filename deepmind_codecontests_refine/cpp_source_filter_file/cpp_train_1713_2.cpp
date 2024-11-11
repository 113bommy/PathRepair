#include <bits/stdc++.h>
using namespace std;
int read() {
  int sum = 0, f = 1;
  char st = getchar();
  while (st < '0' || st > '9') {
    if (st == '-') f = -1;
    st = getchar();
  }
  while ('0' <= st && st <= '9') {
    sum = (sum << 3) + (sum << 1) + st - '0';
    st = getchar();
  }
  return sum * f;
}
int n, m, top, z[100010], an[100010];
double a[100010], sum[100010];
vector<pair<int, int> > b[100010];
double xl(int x, int y) {
  return (sum[x] - x * a[x] - sum[y] + y * a[y]) / (a[x] - a[y]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    sum[i] = sum[i - 1] + a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    b[y].push_back(make_pair(x, i));
  }
  for (int i = 1; i <= n; i++) {
    while (top >= 1 && a[z[top]] > a[i]) top--;
    while (top > 1 && xl(z[top], i) > xl(z[top - 1], i)) top--;
    z[++top] = i;
    for (int j = 0; j < b[i].size(); j++) {
      int x = b[i][j].first, id = b[i][j].second;
      int mi = 1, ma = top, mid, ans;
      while (mi <= ma) {
        mid = (mi + ma) >> 1;
        if (z[mid] >= i - x + 1)
          ma = mid - 1, ans = mid;
        else
          mi = mid + 1;
      }
      mi = ans, ma = top, ans = top;
      while (mi <= ma) {
        mid = (mi + ma) >> 1;
        if (xl(z[mid], z[mid + 1]) < x - i)
          ma = mid - 1, ans = mid;
        else
          mi = mid + 1;
      }
      an[id] = sum[i] - sum[z[ans]] + (x - i + z[ans]) * a[z[ans]];
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", an[i]);
  }
  return 0;
}
