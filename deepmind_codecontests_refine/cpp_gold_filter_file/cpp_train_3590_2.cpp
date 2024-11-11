#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, q, an;
int a[200010], ma[200010][2], zhi[500][500], tma[500], ge[200010], id[200010],
    cov[500], L[200010], R[200010], fu[500][500], yi[500][500];
inline bool cc1(const int &A, const int &B) { return a[A] < a[B]; }
inline int get(int x) { return x / 500; }
inline int xia(int x) { return (x / 500 + 1) * 500 - 1; }
inline int qian(int x) { return x / 500 * 500; }
inline void pre() {
  for (i = 0; i <= n; i++) id[i] = i;
  sort(id, id + n + 1, cc1);
  for (i = 0; i <= n; i++) {
    int A = id[i];
    int wei = get(i);
    if (i % 500 == 0) {
      for (j = 0; j <= 500 - 1; j++) {
        zhi[wei][j] = tma[j];
        fu[wei][j] = cov[j];
        yi[wei][j] = ge[j * 500] + cov[j];
      }
    }
    L[i] = R[i] = -1;
    for (j = max(0, A - m + 1); j <= A;) {
      int _ = get(j);
      if (j % 500 == 0 && j + 500 - 1 <= A) {
        cov[_]++;
        if (L[i] < 0) L[i] = _;
        R[i] = _;
        j += 500;
      } else {
        int f = _ == get(A) ? 1 : 0;
        ge[j]++;
        tma[_] = max(tma[_], ge[j]);
        ma[i][f] = max(ma[i][f], ge[j]);
        j++;
      }
    }
  }
}
inline int find(int x) {
  int l = 0, r = n, mid;
  for (; l <= r;) {
    mid = (l + r) / 2;
    if (a[id[mid]] <= x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l - 1;
}
inline void work(int l, int r, int x) {
  int shu = find(x), i, j;
  int wei = get(shu);
  int zuo = get(l) + 1, you = get(r) - 1;
  an = 0;
  for (i = 0; i <= 500 - 1; i++) tma[i] = 0;
  for (i = qian(shu); i <= shu; i++) {
    if (L[i] < 0) continue;
    tma[L[i]]++, tma[R[i] + 1]--;
  }
  for (i = 1; i <= 500 - 1; i++) tma[i] += tma[i - 1];
  for (i = 0; i <= 500 - 1; i++) tma[i] += fu[wei][i];
  for (i = qian(shu); i <= shu; i++) {
    int A = id[i];
    int le = max(0, A - m + 1), ri = A;
    if (get(le) >= zuo && get(le) <= you) an = max(an, ma[i][0] + tma[get(le)]);
    if (get(ri) >= zuo && get(ri) <= you) an = max(an, ma[i][1] + tma[get(ri)]);
  }
  for (i = zuo; i <= you; i++) an = max(an, tma[i] + zhi[wei][i]);
  {
    int s;
    j = qian(l);
    s = yi[wei][get(j)];
    for (i = qian(shu); i <= shu; i++) {
      int A = id[i];
      int le = max(0, A - m + 1), ri = A;
      if (le <= j && j <= ri) s++;
    }
    j += m;
    for (i = qian(l); i <= xia(l); i++) {
      for (; j <= n && i + m - 1 >= j; j++) s += a[j] <= x;
      if (i >= l && i <= r) an = max(an, s);
      s -= a[i] <= x;
    }
  }
  {
    int s;
    j = qian(r);
    s = yi[wei][get(j)];
    for (i = qian(shu); i <= shu; i++) {
      int A = id[i];
      int le = max(0, A - m + 1), ri = A;
      if (le <= j && j <= ri) s++;
    }
    j += m;
    for (i = qian(r); i <= xia(r); i++) {
      for (; j <= n && i + m - 1 >= j; j++) s += a[j] <= x;
      if (i >= l && i <= r) an = max(an, s);
      s -= a[i] <= x;
    }
  }
  an = m - an;
  printf("%d\n", an);
}
int main() {
  scanf("%d%d", &n, &m);
  n--;
  for (i = 0; i <= n; i++) scanf("%d", &a[i]), a[i] *= -1;
  pre();
  scanf("%d", &q);
  for (i = 1; i <= q; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    x ^= an;
    l--, r--;
    work(l, r, -x);
  }
  return 0;
}
