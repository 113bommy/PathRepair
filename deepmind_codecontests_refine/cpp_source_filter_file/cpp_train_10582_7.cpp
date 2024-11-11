#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
int block;
int n, m, numQ, numC, op;
int sum[MAXN], cnt[MAXN], ans[MAXN], a[MAXN];
int temp[MAXN], tempNum;
struct Node {
  int l, r;
  int time;
  int id;
} q[MAXN];
bool cmp(Node a, Node b) {
  return (a.l / block) ^ (b.l / block)
             ? a.l < b.l
             : ((a.r / block) ^ (b.r / block) ? a.r < b.r : a.time < b.time);
}
struct Change {
  int pos, col;
} c[MAXN];
void add(int x) {
  sum[cnt[x]]--;
  cnt[x]++;
  sum[cnt[x]]++;
}
void del(int x) {
  sum[cnt[x]]--;
  cnt[x]--;
  sum[cnt[x]]++;
}
void change(int i, int t) {
  if (c[t].pos >= q[i].l && c[t].pos <= q[i].r) {
    del(a[c[t].pos]);
    add(c[t].col);
  }
  swap(a[c[t].pos], c[t].col);
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    tempNum = 0;
    numQ = numC = 0;
    memset(cnt, 0, sizeof cnt);
    memset(sum, 0, sizeof sum);
    block = pow(n, 0.666666);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      temp[++tempNum] = a[i];
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &op);
      if (op == 1) {
        ++numQ;
        scanf("%d%d", &q[numQ].l, &q[numQ].r);
        q[numQ].time = numC;
        q[numQ].id = numQ;
      } else {
        ++numC;
        scanf("%d%d", &c[numC].pos, &c[numC].col);
        temp[++tempNum] = c[numC].col;
      }
    }
    sort(temp + 1, temp + 1 + tempNum);
    tempNum = unique(temp + 1, temp + 1 + tempNum) - (temp);
    for (int i = 1; i <= n; i++)
      a[i] = lower_bound(temp + 1, temp + 1 + tempNum, a[i]) - (temp + 0);
    for (int i = 1; i <= numC; i++)
      c[i].col =
          lower_bound(temp + 1, temp + 1 + tempNum, c[i].col) - (temp + 0);
    sort(q + 1, q + 1 + numQ, cmp);
    int l = 1, r = 0, time = 0;
    for (int i = 1; i <= numQ; i++) {
      int ql = q[i].l, qr = q[i].r, qtime = q[i].time;
      while (l < ql) del(a[l++]);
      while (l > ql) add(a[--l]);
      while (r < qr) add(a[++r]);
      while (r > qr) del(a[r--]);
      while (qtime > time) change(i, ++time);
      while (qtime < time) change(i, time--);
      ans[q[i].id] = 1;
      while (sum[ans[q[i].id]] > 0) {
        ans[q[i].id]++;
      }
    }
    for (int i = 1; i <= numQ; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
