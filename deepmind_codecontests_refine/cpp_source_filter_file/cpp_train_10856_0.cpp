#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
  return (f == 1) ? x : -x;
}
const int maxn = 100005;
int n, sta[maxn], top;
struct Query {
  int op, x;
} q[maxn];
set<int> s;
int main() {
  scanf("%d", &n);
  char op;
  for (int i = 1; i <= 2 * n; i++) {
    do op = getchar();
    while (op != '+' && op != '-');
    if (op == '+')
      q[i].op = 1, sta[++top] = i;
    else {
      q[i].op = 2, scanf("%d", &q[i].x);
      if (!top)
        return puts("NO"), 0;
      else
        q[sta[top]].x = q[i].x, top--;
    }
  }
  for (int i = 1; i <= 2 * n; i++)
    if (q[i].op == 1)
      s.insert(q[i].x);
    else {
      if (*s.begin() != q[i].x) return puts("NO"), 0;
      s.erase(*s.begin());
    }
  puts("YES");
  for (int i = 1; i <= 2 * n; i++)
    if (q[i].op == 1) printf("%d ", q[i].x);
  putchar('\n');
  return 0;
}
