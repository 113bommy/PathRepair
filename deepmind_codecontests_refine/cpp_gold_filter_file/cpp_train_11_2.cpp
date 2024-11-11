#include <bits/stdc++.h>
using namespace std;
int f[100010], val[100010], sep[100010], cnt, k, h[100010], last[100010], n;
int read() {
  int tmp = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    tmp = tmp * 10 + c - '0';
    c = getchar();
  }
  return tmp;
}
struct block {
  int l, r, tag, xs[320], val[320], diff[320], pre[320], cur, cnt;
  int id[2][320], merge[320];
  void change(int tl, int tr, int c) {
    int sum[2], p[2], now = 0;
    sum[0] = sum[1] = 0;
    p[0] = p[1] = 1;
    for (int i = 1; i <= r - l + 1; i++)
      if (merge[i] >= tl - l + 1 && merge[i] <= tr - l + 1) {
        id[1][++sum[1]] = merge[i];
        xs[merge[i]] += c;
      } else
        id[0][++sum[0]] = merge[i];
    while (p[0] <= sum[0] || p[1] <= sum[1]) {
      int ch;
      if (p[0] > sum[0])
        ch = 1;
      else if (p[1] > sum[1])
        ch = 0;
      else if (xs[id[0][p[0]]] < xs[id[1][p[1]]])
        ch = 0;
      else
        ch = 1;
      merge[++now] = id[ch][p[ch]];
      p[ch]++;
    }
    cnt = 0;
    for (int i = 1; i <= r - l + 1; i++)
      if (i != 1 && xs[merge[i]] == xs[merge[i - 1]])
        pre[cnt] = (pre[cnt] + val[merge[i]]) % 998244353;
      else {
        cnt++;
        diff[cnt] = xs[merge[i]];
        pre[cnt] = val[merge[i]];
      }
    cur = 0;
    for (int i = 1; i <= cnt; i++) {
      if (diff[i] + tag <= k) cur = i;
      pre[i] = (pre[i - 1] + pre[i]) % 998244353;
    }
  }
  void update() {
    if (cur && diff[cur] + tag > k) cur--;
    if (cur != cnt && diff[cur + 1] + tag <= k) cur++;
  }
} B[320];
void modify(int l, int r, int x) {
  if (sep[l] == sep[r]) {
    B[sep[l]].change(l, r, x);
    return;
  }
  for (int i = sep[l] + 1; i <= sep[r] - 1; i++) {
    B[i].tag += x;
    B[i].update();
  }
  B[sep[l]].change(l, B[sep[l]].r, x);
  B[sep[r]].change(B[sep[r]].l, r, x);
}
int main() {
  n = read();
  k = read();
  int S = sqrt(n);
  for (int i = 1; i <= n; i++) val[i] = read();
  for (int cur = 0; cur <= n; cur += S) {
    int nxt = min(cur + S - 1, n);
    cnt++;
    B[cnt].l = cur;
    B[cnt].r = nxt;
    for (int i = cur; i <= nxt; i++) {
      sep[i] = cnt;
      B[cnt].merge[i - cur + 1] = i - cur + 1;
    }
    B[cnt].cnt = B[cnt].cur = 1;
  }
  f[0] = 1;
  B[sep[0]].val[1] = f[0];
  B[1].change(1, 0, 0);
  for (int i = 1; i <= n; i++) {
    last[i] = h[val[i]];
    h[val[i]] = i;
    int tmp = last[i];
    modify(tmp, i - 1, 1);
    if (tmp != 0) modify(last[tmp], tmp - 1, -1);
    for (int j = 1; j <= sep[i] - 1; j++)
      f[i] = (f[i] + B[j].pre[B[j].cur]) % 998244353;
    int c = sep[i];
    for (int j = B[c].l; j <= i - 1; j++)
      if (B[c].tag + B[c].xs[j - B[c].l + 1] <= k)
        f[i] = (f[i] + f[j]) % 998244353;
    B[c].val[i - B[c].l + 1] = f[i];
    B[c].change(i, i, 0);
  }
  printf("%d\n", f[n]);
  return 0;
}
