#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
long long a, b, c, d;
int now, i, cnt, dp[100005], tree[100005], ans, MAX, n, len, A, B, j, k;
char s[10005];
struct node {
  double x;
  double y;
} t[100005], p[100005];
struct Node {
  int x;
  double y;
} st[100005];
struct NODE {
  int x, y;
} q[100005];
int bit(int k) { return k & -k; }
int cmp(Node i, Node j) { return i.y < j.y; }
int CMP(NODE i, NODE j) { return i.x < j.x || i.x == j.x && i.y < j.y; }
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  len = strlen(s);
  for (i = 0; i < len; i++)
    if (s[i] == '/') {
      a = now;
      now = 0;
    } else
      now = now * 10 + s[i] - '0';
  b = now;
  now = 0;
  scanf("%s", s);
  len = strlen(s);
  for (i = 0; i < len; i++)
    if (s[i] == '/') {
      c = now;
      now = 0;
    } else
      now = now * 10 + s[i] - '0';
  d = now;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &A, &B);
    t[i].x = -(A * a - B * b) / (sqrt(a * a + b * b));
    t[i].y = (A * c - B * d) / (sqrt(c * c + d * d));
    if (t[i].x > eps && t[i].y > eps) {
      p[++cnt].x = t[i].x;
      p[cnt].y = t[i].y;
    }
  }
  for (i = 1; i <= cnt; i++) {
    st[i].x = i;
    st[i].y = p[i].x;
  }
  sort(st + 1, st + cnt + 1, cmp);
  q[st[1].x].x = 1;
  now = 1;
  for (i = 2; i <= cnt; i++) {
    if (st[i].y - eps > st[i - 1].y) now++;
    q[st[i].x].x = now;
  }
  for (i = 1; i <= cnt; i++) {
    st[i].x = i;
    st[i].y = p[i].y;
  }
  sort(st + 1, st + cnt + 1, cmp);
  q[st[1].x].y = 1;
  now = 1;
  for (i = 2; i <= cnt; i++) {
    if (st[i].y - eps > st[i - 1].y) now++;
    q[st[i].x].y = now;
  }
  sort(q + 1, q + cnt + 1, CMP);
  for (j = 1, i = 1; i <= cnt; i++) {
    if (q[i].x != q[i - 1].x)
      while (j < i) {
        for (k = q[j].y; k <= now; k += bit(k)) tree[k] = max(tree[k], dp[j]);
        j++;
      }
    MAX = 0;
    for (k = q[i].y - 1; k; k -= bit(k)) MAX = max(MAX, tree[k]);
    dp[i] = MAX + 1;
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}
