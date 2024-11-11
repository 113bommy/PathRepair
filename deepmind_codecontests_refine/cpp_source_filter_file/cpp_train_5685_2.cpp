#include <bits/stdc++.h>
using namespace std;
int N, len, step;
class rec {
 public:
  int len, t;
  int a[4];
  void getdata(int x, int y, int z, int tt) {
    t = tt;
    a[0] = x;
    a[1] = y;
    a[2] = z;
    a[3] = 0;
    len = 3;
  }
  void getdata(int x, int y, int z, int w, int tt) {
    t = tt;
    a[0] = x;
    a[1] = y;
    a[2] = z;
    a[3] = w;
    len = 4;
  }
  void priln() {
    printf("%d", len);
    for (int i = 0; i < len; i++) printf(" %d", a[i]);
    printf("\n");
  }
} q[300010], p, pp;
bool cmpt(const rec &A, const rec &B) {
  if (!A.t && !B.t) return 0;
  if (!A.t && B.t) return 0;
  if (A.t && !B.t) return 1;
  return A.t < B.t;
}
int main() {
  scanf("%d", &N);
  if (N & 1) {
    len = 0;
    p.getdata(2, 3, 1, 1);
    q[++len] = p;
    p.getdata(3, 2, 1, 0);
    q[++len] = p;
    step = 3;
  } else {
    len = 0;
    p.getdata(1, 2, 3, 1);
    q[++len] = p;
    p.getdata(3, 4, 1, 2);
    q[++len] = p;
    p.getdata(2, 4, 3, 0);
    q[++len] = p;
    p.getdata(1, 4, 2, 0);
    q[++len] = p;
    step = 4;
  }
  for (step += 2; step <= N; step += 2) {
    int j = 1;
    int a = step - 1;
    int b = step;
    for (int i = 3 + (N & 1); i <= N; i += 2) {
      p = q[j];
      pp.getdata(p.a[0], a, p.a[1], p.a[2], 0);
      q[++len] = pp;
      pp.getdata(p.a[0], p.a[1], b, p.t);
      q[++len] = pp;
      if ((N & 1) || (i > (3 + (N & 1)))) {
        pp.getdata(p.a[0], b, p.a[1], a, 0);
        q[++len] = pp;
      } else {
        pp.getdata(a, b, p.a[1], b / 2);
        q[++len] = pp;
        pp.getdata(b, a, p.a[0], 0);
        q[++len] = pp;
      }
      j++;
    }
    if (N & 1) {
      pp.getdata(a, b, 1, b / 2);
      q[++len] = pp;
      pp.getdata(b, a, 1, b / 2);
      q[++len] = pp;
    }
    for (int k = j; k <= len; k++) q[k - j + 1] = q[k];
    len -= j - 1;
    sort(q + 1, q + len + 1, cmpt);
  }
  printf("%d\n", len);
  for (int i = 1; i <= len; i++) q[i].priln();
}
