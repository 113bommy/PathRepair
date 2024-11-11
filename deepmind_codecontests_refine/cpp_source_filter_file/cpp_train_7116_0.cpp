#include <bits/stdc++.h>
using namespace std;
int Last_n, tot, q, t1, t2;
int Ws[200010], Wv[200010], sa[200010], Rank[200010], f[200010][30];
int Use_a[200010], Use_b[200010], r[200010], height[200010], go[200010];
char S[200010];
struct Node {
  int value, id;
  bool operator<(const Node &a) const { return value < a.value; }
} A[200010 * 2];
struct Bjzy {
  int L, R;
  int sum;
} t[200010 * 25];
int root[200010];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void Updata(int &i, int l, int r, int pos) {
  t[++tot] = t[i];
  i = tot;
  t[i].sum++;
  if (l == r) return;
  int mid = (l + r) / 2;
  if (pos <= mid)
    Updata(t[i].L, l, mid, pos);
  else
    Updata(t[i].R, mid + 1, r, pos);
}
int Query(int i, int j, int l, int r, int left, int right) {
  if (l >= left && r <= right) {
    return t[i].sum - t[j].sum;
  }
  int mid = (l + r) / 2;
  if (right <= mid)
    return Query(t[i].L, t[j].L, l, mid, left, right);
  else if (left > mid)
    return Query(t[i].R, t[j].R, mid + 1, r, left, right);
  else {
    return Query(t[i].L, t[j].L, l, mid, left, mid) +
           Query(t[i].R, t[j].R, mid + 1, r, mid + 1, right);
  }
}
bool Cmp(int *r, int a, int b, int len) {
  return r[a] == r[b] && r[a + len] == r[b + len];
}
void Suf_work(int n, int m) {
  int *x = Use_a, *y = Use_b, *t;
  for (int i = 0; i < m; i++) Ws[i] = 0;
  for (int i = 0; i < n; i++) Ws[x[i] = r[i]]++;
  for (int i = 1; i < m; i++) Ws[i] += Ws[i - 1];
  for (int i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
  for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
    p = 0;
    for (int i = n - j; i < n; i++) y[p++] = i;
    for (int i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (int i = 0; i < n; i++) Wv[i] = x[y[i]];
    for (int i = 0; i < m; i++) Ws[i] = 0;
    for (int i = 0; i < n; i++) Ws[Wv[i]]++;
    for (int i = 1; i < m; i++) Ws[i] += Ws[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--Ws[Wv[i]]] = y[i];
    t = x;
    x = y;
    y = t;
    p = 1;
    x[sa[0]] = 0;
    for (int i = 1; i < n; i++)
      x[sa[i]] = Cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
}
void Calheight(int n) {
  int k = 0, j;
  for (int i = 1; i <= n; i++) Rank[sa[i]] = i;
  for (int i = 0; i < n; height[Rank[i++]] = k)
    for (k ? k-- : 0, j = sa[Rank[i] - 1]; r[i + k] == r[j + k]; k++)
      ;
}
void RMQ() {
  for (int i = 1; i <= Last_n; i++) f[i][0] = height[i];
  for (int j = 1; j <= 25; j++)
    for (int i = 1; i <= Last_n; i++) {
      if (i + (1 << j) - 1 <= Last_n)
        f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
}
int Get_min(int a, int b) {
  int x1 = Rank[a], x2 = Rank[b];
  int l = min(x1, x2), r = max(x1, x2);
  l++;
  int qwer = (int)(log(r - l + 1.0) / log(2.0));
  return min(f[l][qwer], f[r - (1 << qwer) + 1][qwer]);
}
void Find(int k, int len) {
  int l, r;
  if (k == 1 || Get_min(sa[k - 1], sa[k]) < len)
    t1 = k;
  else {
    l = 1;
    r = k - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (Get_min(sa[mid], sa[k]) >= len)
        r = mid;
      else
        l = mid + 1;
    }
    t1 = r;
  }
  if (k == Last_n || Get_min(sa[k], sa[k + 1]) < len)
    t2 = k;
  else {
    l = k + 1;
    r = Last_n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (Get_min(sa[k], sa[mid]) >= len) {
        if (l == mid) break;
        l = mid;
      } else
        r = mid;
    }
    t2 = l;
  }
}
int main() {
  Last_n = read();
  int last = read();
  Last_n--;
  for (int i = 1; i <= Last_n; i++) {
    int x = read();
    r[i - 1] = x - last;
    last = x;
    A[++tot].value = r[i - 1];
    A[tot].id = tot;
    A[++tot].value = -r[i - 1];
    A[tot].id = tot;
  }
  sort(A + 1, A + tot + 1);
  A[0].value = -0x7fffffff;
  int qwer = 0;
  for (int i = 1; i <= tot; i++) {
    if (A[i].value != A[i - 1].value) {
      go[A[i].id] = ++qwer;
    } else
      go[A[i].id] = qwer;
  }
  int qqq = Last_n;
  for (int i = 1; i <= qqq; i++) r[i - 1] = go[2 * (i - 1) + 1];
  r[Last_n++] = 0;
  for (int i = 1; i <= qqq; i++) r[Last_n++] = go[2 * i];
  Last_n--;
  Suf_work(Last_n + 1, qwer + 10);
  Calheight(Last_n);
  RMQ();
  tot = 0;
  for (int i = qqq + 1; i <= Last_n; i++) {
    int now = i - qqq;
    root[now] = root[now - 1];
    Updata(root[now], 1, Last_n, Rank[i]);
  }
  q = read();
  for (int i = 1; i <= q; i++) {
    int l = read(), r = read();
    if (l == r)
      printf("%d\n", qqq);
    else {
      int Ans = 0;
      int len = r - l;
      Find(Rank[l - 1], r - l);
      if (l - len - 1 >= 1)
        Ans += Query(root[l - len - 1], root[0], 1, Last_n, t1, t2);
      if (r + 1 <= qqq) Ans += Query(root[qqq], root[r], 1, Last_n, t1, t2);
      printf("%d\n", Ans);
    }
  }
  return 0;
}
