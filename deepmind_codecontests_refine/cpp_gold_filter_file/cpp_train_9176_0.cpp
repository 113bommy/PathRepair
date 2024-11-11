#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
struct node {
  int id, v;
  inline bool operator<(node b) const {
    if (v == b.v) return id < b.id;
    return v > b.v;
  }
} a[500001];
int p[500001], ans[500001];
int main() {
  int t = read();
  while (t--) {
    int n = read();
    stack<int> s;
    s.push(n + 1);
    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
      p[i] = read();
      while (s.top() <= i) s.pop();
      if (!flag && p[i] > s.top()) flag = 1;
      s.push(p[i]);
      while (s.top() <= i) s.pop();
      a[i] = (node){i, p[i]};
    }
    if (flag)
      puts("-1");
    else {
      for (int i = 1; i <= n; ++i)
        if (~p[i] && !(~p[p[i]])) a[p[i]].v = p[i] + 1;
      sort(a + 1, a + n + 1);
      for (int i = 1; i <= n; ++i) ans[a[i].id] = n - i + 1;
      for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
      putchar('\n');
    }
  }
  return 0;
}
