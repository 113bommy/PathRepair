#include <bits/stdc++.h>
using namespace std;
struct Height {
  int h, x, tm;
  bool operator<(const Height &B) const { return h > B.h; }
} H[20];
struct Pos {
  int h, x;
  bool operator<(const Pos &B) const { return x < B.x; }
} P[20];
int hc, pc, mf1[222000 << 2], mg2[222000 << 2], sz[222000 << 2], ht[222000];
int query1(int i, int l, int r, int L, int R) {
  if (L <= l && r <= R) return mf1[i];
  int mid = l + r >> 1;
  if (R <= mid)
    return query1(i << 1, l, mid, L, R);
  else if (L > mid)
    return query1(i << 1 | 1, mid + 1, r, L, R);
  else
    return max(query1(i << 1, l, mid, L, mid),
               query1(i << 1 | 1, mid + 1, r, mid + 1, R));
}
int queryx(int i, int l, int r, int k) {
  if (l == r) return l;
  int mid = l + r >> 1;
  if (k > sz[i << 1])
    return queryx(i << 1 | 1, mid + 1, r, k - sz[i << 1]);
  else
    return queryx(i << 1, l, mid, k);
}
void modify1(int i, int l, int r, int pos, int p) {
  if (l == r) {
    mf1[i] = p;
    sz[i] = p ? 1 : 0;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    modify1(i << 1, l, mid, pos, p);
  else
    modify1(i << 1 | 1, mid + 1, r, pos, p);
  mf1[i] = max(mf1[i << 1], mf1[i << 1 | 1]);
  sz[i] = sz[i << 1] + sz[i << 1 | 1];
}
int query2(int i, int l, int r, int L, int R) {
  if (L <= l && r <= R) return mg2[i];
  int mid = l + r >> 1;
  if (R <= mid)
    return query2(i << 1, l, mid, L, R);
  else if (L > mid)
    return query2(i << 1 | 1, mid + 1, r, L, R);
  else
    return max(query2(i << 1, l, mid, L, mid),
               query2(i << 1 | 1, mid + 1, r, mid + 1, R));
}
void modify2(int i, int l, int r, int pos, int k) {
  if (l == r) {
    mg2[i] = k;
    return;
  }
  int mid = l + r >> 1;
  if (pos <= mid)
    modify2(i << 1, l, mid, pos, k);
  else
    modify2(i << 1 | 1, mid + 1, r, pos, k);
  mg2[i] = max(mg2[i << 1], mg2[i << 1 | 1]);
}
inline int read() {
  int n = 0;
  char a;
  bool z = false;
  while (a = getchar()) {
    if (a > '9' || a < '0')
      if (z)
        break;
      else
        continue;
    if (!z) z = true;
    n = (n << 1) + (n << 3) + (a ^ 48);
  }
  return n;
}
int main() {
  int n = read(), Q = read(), x, h, V, s, all = 0, mh = Q + 10;
  while (Q--) {
    if (read() == 1) {
      ++all;
      x = read();
      h = read() + Q;
      ht[x] = h;
      H[++hc] = (Height){h, x, h - Q};
      sort(H + 1, H + 1 + hc);
      s = pc + 1;
      for (int i = 1; i <= pc; ++i)
        if (x < P[i].x) {
          s = i;
          break;
        }
      if (pc < 10) ++pc;
      for (int i = pc - 1; i >= s; --i) P[i + 1] = P[i];
      if (s <= pc) P[s] = (Pos){h, x};
      for (int i = 1; i <= hc; ++i) modify1(1, 1, n, H[i].x, 0);
      for (int i = 1; i <= hc; ++i) {
        modify1(1, 1, n, H[i].x,
                V = query1(1, 1, n, min(H[i].x + 1, n), n) + 1);
        modify2(1, 1, mh, H[i].h, V);
      }
      printf("%d\n", mf1[1]);
    } else {
      x = read();
      --all;
      modify1(1, 1, n, P[x].x, 0);
      modify2(1, 1, mh, P[x].h, 0);
      ht[P[x].x] = 0;
      for (int i = 1; i <= hc; ++i)
        if (H[i].x == P[x].x) {
          for (int j = i; j < hc; ++j) H[j] = H[j + 1];
          --hc;
          break;
        }
      for (int i = x; i < pc; ++i) P[i] = P[i + 1];
      --pc;
      if (all >= 10) {
        x = queryx(1, 1, n, 10);
        P[++pc] = (Pos){ht[x], x};
      }
      for (int i = 1; i <= pc; ++i) modify2(1, 1, mh, P[i].h, 0);
      for (int i = pc; i; --i) {
        modify2(1, 1, mh, P[i].h,
                V = query2(1, 1, mh, min(mh, P[i].h + 1), mh) + 1);
        modify1(1, 1, n, P[i].x, V);
      }
      printf("%d\n", mg2[1]);
    }
    if (hc >= 1 && H[1].tm == 10) {
      for (int i = 1; i < hc; ++i) H[i] = H[i + 1];
      --hc;
    }
    for (int i = 1; i <= hc; ++i) ++H[i].tm;
  }
  return 0;
}
