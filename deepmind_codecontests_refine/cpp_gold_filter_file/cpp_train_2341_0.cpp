#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int ans1[N], ans2[N];
int n, L;
struct node {
  long long x, y, v;
  bool operator<(const node &a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
};
void GG() {
  puts("NO");
  exit(0);
}
struct solver {
  int top;
  node q[N / 9];
  void insert(long long T, long long v) { q[++top] = (node){T % L, T / L, v}; }
  void getans(int *ans) {
    q[++top] = (node){0, 0, 0};
    sort(q + 1, q + top + 1);
    long long vl = -L, vr = L;
    for (int i = (int)(1); i <= (int)(top); i++) {
      node x = q[i], y = q[(i == top ? 1 : i + 1)];
      if (x.x == y.x) {
        long long dif = y.v - x.v, difT = y.y - x.y;
        if (dif % difT) GG();
        vl = max(vl, dif / difT);
        vr = min(vr, dif / difT);
        for (; (vl + L) % 2; ++vl)
          ;
        for (; (vr + L) % 2; --vr)
          ;
      } else {
        long long dif = (y.x - x.x + L) % L;
        long long difT = ((y.y - x.y) * L + y.x - x.x - dif) / L;
        for (; vl <= vr; vl++) {
          long long D = y.v - x.v - 1ll * vl * difT;
          if (abs(D) <= dif && abs(vl - D) <= L - dif && (vl + L) % 2 == 0)
            break;
        }
        for (; vl <= vr; vr--) {
          long long D = y.v - x.v - 1ll * vr * difT;
          if (abs(D) <= dif && abs(vr - D) <= L - dif && (vr + L) % 2 == 0)
            break;
        }
      }
    }
    if ((vl + L) % 2) ++vl;
    if ((vr + L) % 2) --vr;
    if (vl > vr) GG();
    q[++top] = (node){L, 0, vl};
    int p1 = 0, p2 = 0;
    for (int i = (int)(1); i <= (int)(top); i++) {
      long long q1 = q[i].x, q2 = q[i].v - q[i].y * vl;
      for (; p1 < q1;) {
        ++p1;
        if (p2 < q2)
          ans[p1] = 1, ++p2;
        else
          ans[p1] = -1, --p2;
      }
      if (p2 != q2) {
        puts("ANSGG");
        exit(0);
      }
    }
  }
} T1, T2;
int main() {
  scanf("%d%d", &n, &L);
  for (int i = (int)(1); i <= (int)(n); i++) {
    long long T, x, y;
    scanf("%lld%lld%lld", &T, &x, &y);
    T1.insert(T, x + y);
    T2.insert(T, x - y);
  }
  T1.getans(ans1);
  T2.getans(ans2);
  for (int i = (int)(1); i <= (int)(L); i++) {
    if (ans1[i] == ans2[i])
      putchar(ans1[i] == 1 ? 'R' : 'L');
    else
      putchar(ans1[i] == 1 ? 'U' : 'D');
  }
}
