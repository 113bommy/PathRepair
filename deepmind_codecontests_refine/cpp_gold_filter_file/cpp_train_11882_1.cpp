#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
inline int read() {
  int s = 0;
  register bool neg = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) neg |= (c == '-');
  for (; c >= '0' && c <= '9'; s = s * 10 + (c ^ 48), c = getchar())
    ;
  s = (neg ? -s : s);
  return s;
}
int a, s[N + 10], p, ans[N * 2 + 10][2], top;
struct node {
  int val, id;
  bool operator<(const node &o) const { return val < o.val; }
} q[N + 10];
inline bool check(int n) {
  if (!n) return false;
  while (n) {
    if (n % 10 != 4 && n % 10 != 7) return false;
    n /= 10;
  }
  return true;
}
signed main() {
  a = read();
  for (int i = 1; i <= a; i++) {
    s[i] = q[i].val = read();
    q[i].id = i;
    if (check(s[i])) p = i;
  }
  if (!p) {
    for (int i = 2; i <= a; i++)
      if (s[i] < s[i - 1]) {
        puts("-1");
        return 0;
      }
    puts("0");
    return 0;
  }
  sort(q + 1, q + a + 1);
  for (int i = 1; i <= a; i++) s[q[i].id] = i;
  for (int i = 1; i <= a; i++) {
    if (p != i) {
      ans[++top][0] = i;
      ans[top][1] = p;
      q[s[p]].id = i;
      q[s[i]].id = p;
      swap(s[p], s[i]);
      p = i;
    }
    if (p != q[i].id) {
      ans[++top][0] = p;
      ans[top][1] = q[i].id;
      q[s[p]].id = q[i].id;
      int tmp = q[i].id;
      swap(s[p], s[q[i].id]);
      q[i].id = p;
      p = tmp;
    }
  }
  printf("%d\n", top);
  for (int i = 1; i <= top; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}
