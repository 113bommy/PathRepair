#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
struct P {
  double x, y;
  int id;
} p[200010], a[200010];
vector<int> v[200010], ans;
bool cmp1(P a, P b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
bool dcmp(double x) { return fabs(x) < 1e-9; }
int s[200010], top;
double slope(P a, P b) { return (a.y - b.y) / (a.x - b.x); }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    p[i].x = 1.0 / (double)x;
    p[i].y = 1.0 / (double)y;
    p[i].id = i;
  }
  sort(p + 1, p + n + 1, cmp1);
  a[1] = p[1];
  m = 1;
  v[1].push_back(p[1].id);
  for (int i = 2; i <= n; i++) {
    if (fabs(p[i].x - a[m].x) > 1e-9) a[++m] = p[i];
    if (dcmp(p[i].x - a[m].x) && dcmp(p[i].y - a[m].y)) v[m].push_back(p[i].id);
  }
  s[++top] = 1;
  for (int i = 2; i <= m; i++) {
    while (top > 1 &&
           slope(a[i], a[s[top - 1]]) < slope(a[s[top]], a[s[top - 1]]))
      top--;
    s[++top] = i;
  }
  for (int j = 0; j < v[s[1]].size(); j++) ans.push_back(v[s[1]][j]);
  for (int i = 2; i <= top; i++) {
    if (slope(a[s[i]], a[s[i - 1]]) < 0) {
      for (int j = 0; j < v[s[i]].size(); j++) ans.push_back(v[s[i]][j]);
    } else
      break;
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
