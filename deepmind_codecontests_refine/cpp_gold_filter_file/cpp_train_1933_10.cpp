#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, ans[1000010];
long long a, t[1000010], sum[1000010];
struct node {
  long long val, id;
} b[1000010];
inline bool cmp(node x, node y) { return x.val < y.val; }
priority_queue<int, vector<int>, less<int> > q;
inline long long read() {
  long long num = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + ch - '0';
    ch = getchar();
  }
  return num * f;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) t[i] = read();
  for (int i = n; i >= 1; --i) {
    a = t[i];
    if (a < 0) {
      q.push(a);
    } else if (a > 0) {
      while (!q.empty() && a > 0) {
        a += q.top();
        q.pop();
      }
      if (a < 0) q.push(a);
    }
  }
  while (!q.empty()) {
    sum[++cnt] = -q.top();
    q.pop();
  }
  for (int i = 1; i <= cnt; ++i) sum[i] += sum[i - 1];
  for (int i = 1; i <= m; ++i) b[i].val = read(), b[i].id = i;
  sort(b + 1, b + 1 + m, cmp);
  int h = 0;
  for (int i = 1; i <= m; ++i) {
    while (b[i].val >= sum[h + 1] && h < cnt) ++h;
    ans[b[i].id] = cnt - h;
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
