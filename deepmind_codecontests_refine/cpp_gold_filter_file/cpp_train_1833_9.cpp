#include <bits/stdc++.h>
using namespace std;
struct item {
  double px, py;
  int id;
} A[100005], B[100005];
bool cmp1(item &f, item &t) { return f.px < t.px; }
bool cmp2(item &f, item &t) { return f.py < t.py; }
int n, m, d, cl, ct, cr, cb, cnt, t1, t2, cntt, tmp[100005];
int main() {
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1, a, b, c, dd; i <= d; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &dd);
    B[i] = A[i] = (item){(a + c) / 2.0, (b + dd) / 2.0, i};
  }
  sort(A + 1, A + d + 1, cmp1);
  sort(B + 1, B + d + 1, cmp2);
  scanf("%d%d%d%d", &cl, &cr, &ct, &cb);
  cl++;
  ct++;
  t1 = (A[cl].px > int(A[cl].px)) ? 1 : -1;
  t2 = (B[ct].py > int(B[ct].py)) ? 1 : -1;
  if (A[cl].px == int(A[cl].px))
    for (int i = cl; i <= d && A[i].px == A[cl].px; i++) ++tmp[A[i].id], --cnt;
  else
    for (int i = cl; i > 0 && A[i].px == A[cl].px; i--) ++tmp[A[i].id], ++cnt;
  if (B[ct].py == int(B[ct].py))
    for (int i = ct; i <= d && B[i].py == B[ct].py; i++) ++tmp[B[i].id], --cntt;
  else
    for (int i = ct; i > 0 && B[i].py == B[ct].py; i--) ++tmp[B[i].id], ++cntt;
  if (A[cl + t1].px == A[cl].px || B[ct + t2].py == B[ct].py ||
      cr + cl - cnt + t1 != d || cb + ct - cntt + t2 != d)
    printf("-1");
  else {
    for (int i = 1; i <= d; i++)
      if (tmp[i] == 2) {
        printf("%d", i);
        return 0;
      }
    printf("-1");
  }
  return 0;
}
