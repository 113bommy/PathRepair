#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int N = 200000;
struct N {
  int val, L, R;
} pre[MAXN * 20], suf[MAXN * 20];
int prer[MAXN], sufr[MAXN];
int num[MAXN];
int preV[MAXN], sufV[MAXN];
int preTop = 0;
int sufTop = 0;
int M[MAXN * 10];
int sumNum = 0;
void Init(struct N *st, int &root, int &Top, int L, int R) {
  root = Top++;
  st[root].val = 0;
  st[root].L = -1;
  st[root].R = -1;
  if (L == R) {
    if (L == M[0]) st[root].val = 1;
    return;
  }
  int mid = (L + R) >> 1;
  Init(st, st[root].L, Top, L, mid);
  Init(st, st[root].R, Top, mid + 1, R);
}
void Update(struct N *st, int pr, int &root, int &Top, int val, int L, int R) {
  if (root == -1) root = Top++, st[root].L = -1, st[root].R = -1;
  st[root].val = st[pr].val + 1;
  if (L == R) return;
  int mid = (L + R) >> 1;
  if (val <= mid) {
    st[root].R = st[pr].R;
    Update(st, st[pr].L, st[root].L, Top, val, L, mid);
  } else {
    st[root].L = st[pr].L;
    Update(st, st[pr].R, st[root].R, Top, val, mid + 1, R);
  }
}
int Query(struct N *st, int root, int val, int L, int R) {
  if (L == R) return st[root].val;
  int mid = (L + R) >> 1;
  if (val <= mid) return Query(st, st[root].L, val, L, mid);
  return Query(st, st[root].R, val, mid + 1, R);
}
struct Q {
  int l, r, id;
  long long anw;
} que[MAXN / 2];
const int MAGIC = sqrt(MAXN);
bool cmp(Q q1, Q q2) {
  if (q1.l / MAGIC != q2.l / MAGIC) return q1.l / MAGIC < q2.l / MAGIC;
  return q1.r < q2.r;
}
bool cmpid(Q q1, Q q2) { return q1.id < q2.id; }
template <class T>
inline T &RD(T &x) {
  char c;
  while (!isdigit((c = getchar())))
    ;
  x = c - '0';
  while (isdigit((c = getchar()))) x = x * 10 + c - '0';
  return x;
}
template <class T>
inline T &RDD(T &x) {
  char c;
  while ((c = getchar()), c != '-' && !isdigit(c))
    ;
  if (c == '-') {
    x = '0' - (c = getchar());
    while (isdigit((c = getchar()))) x = x * 10 + '0' - c;
  } else {
    x = c - '0';
    while (isdigit((c = getchar()))) x = x * 10 + c - '0';
  }
  return x;
}
inline double &RF(double &x) {
  char c;
  while ((c = getchar()), c != '-' && c != '.' && !isdigit(c))
    ;
  if (c == '-')
    if ((c = getchar()) == '.') {
      x = 0;
      double l = 1;
      while (isdigit((c = getchar()))) l /= 10, x = x * 10 + '0' - c;
      x *= l;
    } else {
      x = '0' - c;
      while (isdigit((c = getchar()))) x = x * 10 + '0' - c;
      if (c == '.') {
        double l = 1;
        while (isdigit((c = getchar()))) l /= 10, x = x * 10 + '0' - c;
        x *= l;
      }
    }
  else if (c == '.') {
    x = 0;
    double l = 1;
    while (isdigit((c = getchar()))) l /= 10, x = x * 10 + c - '0';
    x *= l;
  } else {
    x = c - '0';
    while (isdigit((c = getchar()))) x = x * 10 + c - '0';
    if (c == '.') {
      double l = 1;
      while (isdigit((c = getchar()))) l /= 10, x = x * 10 + c - '0';
      x *= l;
    }
  }
  return x;
}
void print(int L, int R, int ans) {}
int main() {
  int n, m, i, j, k;
  RD(n);
  RD(m);
  RD(k);
  for (i = 1; i <= n; ++i) {
    RD(num[i]);
  }
  memset(M, -1, sizeof(M));
  M[0] = sumNum++;
  for (preV[0] = 0, i = 1; i <= n; ++i) {
    preV[i] = preV[i - 1] ^ num[i];
    if (M[preV[i]] == -1) M[preV[i]] = sumNum++;
  }
  for (sufV[n + 1] = 0, i = n; i >= 1; --i) {
    sufV[i] = sufV[i + 1] ^ num[i];
    if (M[sufV[i]] == -1) M[preV[i]] = sumNum++;
  }
  N = sumNum;
  memset(prer, -1, sizeof(prer));
  Init(pre, prer[0], preTop, 0, N);
  for (i = 1; i <= n; ++i) {
    Update(pre, prer[i - 1], prer[i], preTop, M[preV[i]], 0, N);
  }
  memset(sufr, -1, sizeof(sufr));
  Init(suf, sufr[n + 1], sufTop, 0, N);
  for (i = n; i >= 1; --i)
    Update(suf, sufr[i + 1], sufr[i], sufTop, M[sufV[i]], 0, N);
  for (i = 0; i < m; ++i) {
    RD(que[i].l);
    RD(que[i].r);
  }
  for (i = 0; i < m; ++i) que[i].id = i;
  sort(que, que + m, cmp);
  long long ans = 0;
  int L = que[0].l, R = que[0].l - 1;
  for (i = 0; i < m; ++i) {
    while (R < que[i].r) {
      R++;
      if (M[preV[R] ^ k] == -1) continue;
      int id = M[preV[R] ^ k];
      ans += Query(pre, prer[R - 1], id, 0, N) -
             (L - 2 >= 0 ? Query(pre, prer[L - 2], id, 0, N) : 0);
      print(L, R, ans);
    }
    while (que[i].r < R) {
      if (M[preV[R] ^ k] == -1) {
        R--;
        continue;
      }
      int id = M[preV[R] ^ k];
      ans -= Query(pre, prer[R - 1], id, 0, N) -
             (L - 2 >= 0 ? Query(pre, prer[L - 2], id, 0, N) : 0);
      R--;
      print(L, R, ans);
    }
    while (L > que[i].l) {
      L--;
      if (M[sufV[L] ^ k] == -1) continue;
      int id = M[sufV[L] ^ k];
      ans += Query(suf, sufr[L + 1], id, 0, N) -
             (R + 2 <= n + 1 ? Query(suf, sufr[R + 2], id, 0, N) : 0);
      print(L, R, ans);
    }
    while (L < que[i].l) {
      if (M[sufV[L] ^ k] == -1) {
        L++;
        continue;
      }
      int id = M[sufV[L] ^ k];
      ans -= Query(suf, sufr[L + 1], id, 0, N) -
             (R + 2 <= n + 1 ? Query(suf, sufr[R + 2], id, 0, N) : 0);
      L++;
      print(L, R, ans);
    }
    que[i].anw = ans;
  }
  sort(que, que + m, cmpid);
  for (i = 0; i < m; ++i) {
    printf("%I64d\n", que[i].anw);
  }
  return 0;
}
