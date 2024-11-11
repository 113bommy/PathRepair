#include <bits/stdc++.h>
using namespace std;
using namespace rel_ops;
const double PI = acos((double)-1);
int ts, ts2, ts3, ts4;
int n, m;
long long gcd(long long x, long long y) {
  long long t;
  for (; y != 0;) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
double sqr(double x) { return x * x; }
int a[100005], b[7][100005][7], c[15], f[15], g[15], ha[100005], tmp[100005];
void fenjie() {
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  for (i = 1; i <= n; i++)
    if (!ha[i]) {
      for (t1 = a[i], j = 1;; j++, t1 = a[t1]) {
        tmp[j] = t1;
        ha[t1] = 1;
        if (t1 == i) break;
      }
      tmp[0] = tmp[j];
      for (k = j; k >= 1; k--) tmp[k] = tmp[k - 1], tmp[k - 1] = 0;
      if (j > 5) {
        for (k = j;;) {
          t2 = 0;
          for (l = 1; l <= 5 && k - l + 1 >= 1; l++) {
            t2++;
          }
          if (k <= 5) break;
          k -= 4;
        }
      } else {
        t2 = j;
      }
    }
  (memset((ha), 0, sizeof((ha))));
  for (i = 1; i <= n; i++)
    if (!ha[i]) {
      if (a[i] == i) continue;
      if (i == 6) ts = 0;
      t2 = 0;
      tmp[++t2] = i;
      for (t1 = a[i], j = 1;; j++, t1 = a[t1]) {
        if (t1 == i) {
          j--;
          break;
        }
        tmp[++t2] = t1;
        ha[t1] = 1;
        if (t1 == i || t2 == 5) break;
      }
      j = t2;
      if (t1 != i) ha[i] = 0, a[i] = a[t1];
      c[j]++;
      for (k = 1; k <= j; k++) b[j][c[j]][k] = tmp[k];
      if (t1 != i) {
        i--;
      }
    }
  for (i = 1; i <= c[5] / 2; i++) {
    for (j = 1; j <= 5; j++) swap(b[5][i][j], b[5][c[5] - i + 1][j]);
  }
}
void work() {
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  for (;;) {
    t1 = c[3] - 1;
    t2 = c[2] + 2;
    if (t1 >= t2) {
      c[2]++;
      b[2][c[2]][1] = b[3][c[3]][2];
      b[2][c[2]][2] = b[3][c[3]][3];
      c[2]++;
      b[2][c[2]][1] = b[3][c[3]][1];
      b[2][c[2]][2] = b[3][c[3]][2];
      c[3]--;
    } else
      break;
  }
  if ((c[2] - c[3]) % 2 == 0)
    t1 = (c[2] - c[3]) / 2;
  else
    t1 = (c[2] - c[3]) / 2 + 1;
  if (c[2] < c[3]) t1 = 0;
  t1 = max(t1, 0) + c[3] + c[4] + c[5];
  cout << t1 << endl;
}
int f_, g_;
void ins(int p, int q) {
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  for (i = 1; i <= p; i++) f[++f_] = b[p][q][i];
  for (i = 2; i <= p; i++) g[++g_] = b[p][q][i];
  g[++g_] = b[p][q][1];
}
void output() {
  cout << f_ << endl;
  for (int i = 1; i <= f_; i++) printf("%d ", f[i]);
  cout << endl;
  for (int i = 1; i <= f_; i++) printf("%d ", g[i]);
  cout << endl;
}
void out() {
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  for (; c[5];) {
    f_ = g_ = 0;
    ins(5, c[5]--);
    output();
  }
  for (; c[4];) {
    f_ = g_ = 0;
    ins(4, c[4]--);
    output();
  }
  for (; c[3];) {
    f_ = g_ = 0;
    if (c[2]) ins(2, c[2]--);
    ins(3, c[3]--);
    output();
  }
  for (; c[2];) {
    f_ = g_ = 0;
    ins(2, c[2]--);
    if (c[2]) ins(2, c[2]--);
    output();
  }
}
int main() {
  int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8, t9, t, nw;
  int tt1, tt2, tt3, tt4;
  double u1, u2, u3, u4, u5, u6, u7, u8, u9;
  char c1, c2, c3;
  srand((unsigned)time(0));
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  fenjie();
  work();
  out();
  return 0;
}
