#include <bits/stdc++.h>
using namespace std;
struct Node {
  int a, b;
} p[200005];
Node s[200005];
int tail = 0;
int n, mina[200005], ans;
bool cmp(Node nxt, Node pre) {
  if (nxt.b != pre.b) return nxt.b < pre.b;
  return nxt.a > pre.a;
}
void calc(int &x, int y, int cf, int flag) {
  int num = 0;
  while (tail > 0) {
    Node t = s[tail];
    if (t.b < x) break;
    if (t.b <= y) num++;
    x = min(x, t.a);
    tail--;
  }
  if (cf) ans = max(ans, num - flag);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ans = -99999999;
    tail = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].a, &p[i].b);
    sort(p + 1, p + 1 + n, cmp);
    mina[n] = 999999999;
    for (int i = n - 1; i >= 1; i--) mina[i] = min(p[i + 1].a, mina[i + 1]);
    s[++tail] = p[1];
    for (int i = 2; i <= n; i++) {
      calc(p[i].a, min(p[i].b, mina[i] - 1), mina[i] > p[i].a,
           mina[i] > p[i].b);
      s[++tail] = p[i];
    }
    ans = ans + tail;
    printf("%d\n", ans);
  }
  return 0;
}
