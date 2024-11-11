#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
int n;
double w, h, ans;
struct Dn {
  double x, y;
} dn[1010];
inline double dis(Dn u, Dn v) {
  return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}
inline double calc(Dn u) {
  int i, j;
  double mn = 0x3f3f3f3f, m2 = 0x3f3f3f3f, tmp;
  for (i = 1; i <= n; i++) {
    tmp = dis(dn[i], u);
    if (tmp < mn) {
      m2 = mn;
      mn = tmp;
    } else
      m2 = min(m2, tmp);
  }
  return m2;
}
inline double th() {
  Dn now, tmp;
  double jd, t, l, res;
  now.x = (double)(rand() % 1000) / 1000.0 * w;
  now.y = (double)(rand() % 1000) / 1000.0 * h;
  res = calc(now);
  for (l = sqrt(w * w + h * h); l > 1e-15; l *= 0.998) {
    jd = (double)(rand() % 100) / 100.0 * 2.0 * 3.1415926535897932;
    tmp.x = now.x + cos(jd) * l;
    tmp.y = now.y + sin(jd) * l;
    if (tmp.x < 0 || tmp.x > w || tmp.y < 0 || tmp.y > h) continue;
    t = calc(tmp);
    if (t > res) {
      res = t;
      now = tmp;
    }
  }
  return res;
}
int main() {
  srand(517);
  int i, j;
  cin >> w >> h >> n;
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf", &dn[i].x, &dn[i].y);
  }
  for (i = 1; i <= 10; i++) ans = max(ans, th());
  printf("%.15f", ans);
}
