#include <bits/stdc++.h>
using namespace std;
int qnt[2002000];
long long x[2002000];
long long y[2002000];
long long t[2002000];
char ans[2002000];
int wx[2002000];
int wy[2002000];
int main() {
  int n, l;
  scanf("%d%d", &n, &l);
  int fixo = 0;
  long long fx, fy;
  int c33 = 0;
  vector<pair<long long, pair<long long, long long> > > v;
  for (int i = 0; i <= n; i++) {
    long long a, b, c;
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    if (l == 2000000 && i == 1 && a == 10011) c33 = 1;
    if (i == n) a = b = c = 0;
    v.push_back(pair<long long, pair<long long, long long> >(
        a, pair<long long, long long>(b, c)));
    if ((a ^ b ^ c) & 1) {
      printf("NO\n");
      return 0;
    }
    if (qnt[a % l]) {
      fixo = 1;
      long long dx = b - x[a % l];
      long long dy = c - y[a % l];
      long long dt = a / l - t[a % l];
      ;
      if (dx % dt || dy % dt) {
        printf("NO\n");
        return 0;
      }
      fx = dx / dt;
      fy = dy / dt;
      continue;
    }
    qnt[a % l]++;
    t[a % l] = a / l;
    x[a % l] = b;
    y[a % l] = c;
  }
  long double x1, x2, y1, y2;
  int f = 1;
  int last = 0;
  long long sdx = 0, sdy = 0, st = 0;
  if (fixo)
    ;
  for (int i = 1; i <= l && !fixo; i++)
    if (qnt[i] || i == l) {
      long long dx, dy, T;
      long long len = i - last;
      if (i != l) {
        dx = x[i] - x[last];
        dy = y[i] - y[last];
        T = t[i] - t[last];
        sdx += dx;
        sdy += dy;
        st += T;
      } else {
        T = st + 1;
        dx = sdx;
        dy = sdy;
      };
      last = i;
      if (0) {
        fixo = 1;
        long long t1 = dx / T;
        if (abs(t1 * T - dx) > abs((t1 + 1) * T - dx)) t1++;
        if (abs(t1 * T - dx) > abs((t1 - 1) * T - dx)) t1--;
        fx = t1;
        t1 = dy / T;
        if (abs(t1 * T - dy) > abs((t1 + 1) * T - dy)) t1++;
        if (abs(t1 * T - dy) > abs((t1 - 1) * T - dy)) t1--;
        fy = t1;
        continue;
      }
      if (T == 0) continue;
      long double xa = (long double)dx / T;
      long double xb = xa;
      long double ya = (long double)dy / T - (long double)len / abs(T);
      long double yb = (long double)dy / T + (long double)len / abs(T);
      ;
      long double xar = (xa + ya) / 2;
      long double yar = (ya - xa) / 2;
      long double xbr = (xb + yb) / 2;
      long double ybr = (yb - xb) / 2;
      if (f) {
        f = 0;
        x1 = xar;
        y1 = yar;
        x2 = xbr;
        y2 = ybr;
        continue;
      }
      x1 = max(x1, xar);
      y1 = max(y1, yar);
      x2 = min(x2, xbr);
      y2 = min(y2, ybr);
    };
  if (!fixo) {
    if (l & 1) x1 += .5, x2 += .5, y1 += .5, y2 += .5;
    if (x1 > x2 + 1e-8 || y1 > y2 + 1e-8) {
      if (c33) printf("no sol0\n");
      printf("NO\n");
      return 0;
    }
    int r = (int)floor((x2 + 1e-8));
    if (x1 - 1e-8 > r) {
      if (c33) printf("no sol\n");
      printf("NO\n");
      return 0;
    }
    int s = (int)floor((y2 + 1e-8));
    if (y1 - 1e-8 > s) {
      if (c33) printf("no sol\n");
      printf("NO\n");
      return 0;
    };
    fx = r - s;
    fy = r + s;
    if (l & 1) fy--;
  };
  if (c33)
    ;
  last = 0;
  int ax = fx, ay = fy;
  ;
  for (int i = 1; i < l; i++)
    if (qnt[i]) {
      long long T = t[i] - t[last];
      long long dx = x[i] - x[last] - T * fx;
      long long dy = y[i] - y[last] - T * fy;
      long long len = i - last;
      ;
      if (abs(dx) + abs(dy) > len) {
        ;
        assert(fixo);
        printf("NO\n");
        return 0;
      };
      for (int j = last; j < i; j++) {
        if (dx < 0)
          ans[j] = 'L', dx++, ax++;
        else if (dx > 0)
          ans[j] = 'R', dx--, ax--;
        else if (dy < 0)
          ans[j] = 'D', dy++, ay++;
        else if (dy > 0)
          ans[j] = 'U', dy--, ay--;
        else
          ans[j] = 'U', dy--, ay--;
      };
      assert((dx | dy) == 0);
      last = i;
    };
  for (int i = last; i < l; i++) {
    if (ax < 0)
      ans[i] = 'L', ax++;
    else if (ax > 0)
      ans[i] = 'R', ax--;
    else if (ay < 0)
      ans[i] = 'D', ay++;
    else if (ay > 0)
      ans[i] = 'U', ay--;
    else
      ans[i] = 'U', ay--;
  }
  wx[0] = wy[0] = 0;
  for (int i = 1; i < l; i++) {
    wx[i] = wx[i - 1];
    wy[i] = wy[i - 1];
    if (ans[i - 1] == 'U') wy[i]++;
    if (ans[i - 1] == 'D') wy[i]--;
    if (ans[i - 1] == 'R') wx[i]++;
    if (ans[i - 1] == 'L') wx[i]--;
  }
  for (int i = 0; i < v.size(); i++) {
    long long u = v[i].first;
    long long X = fx * (u / l) + wx[u % l];
    long long Y = fy * (u / l) + wy[u % l];
    if (X != v[i].second.first || Y != v[i].second.second) {
      ;
      assert(fixo);
      printf("NO\n");
      return 0;
    }
  }
  for (int i = 0; i < l; i++) printf("%c", ans[i]);
  printf("\n");
}
