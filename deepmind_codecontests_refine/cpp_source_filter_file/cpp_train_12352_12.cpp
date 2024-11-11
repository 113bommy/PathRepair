#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r, mid;
  long long lnum, rnum;
} tre[400005];
long long l[100005], r[100005], num[100005];
int bit[100005], n;
bool ok[100005];
int lowb(int x) { return -x & x; }
void add(int x, int y) {
  while (x <= n) {
    bit[x] += y;
    x += lowb(x);
  }
}
int ask(int x) {
  int ans = 0;
  while (x) {
    ans += bit[x];
    x -= lowb(x);
  }
  return ans;
}
long long wtf(int x, int y) {
  long long temp = 0;
  if (l[x] >= 0)
    temp += y;
  else {
    if (l[x] < -y)
      temp += -x;
    else
      temp += l[x] * 2 + x;
  }
  if (r[x] >= 0)
    temp += y;
  else {
    if (r[x] < -y)
      temp += -x;
    else
      temp += r[x] * 2 + x;
  }
  return temp;
}
void gg(int x) {
  if (ok[x] && (l[x] < 0 || r[x] < 0)) {
    ok[x] = 0;
    add(x, -1);
  }
  if (!ok[x] && l[x] >= 0 && r[x] >= 0) {
    ok[x] = 1;
    add(x, 1);
  }
}
void build(int x, int ll, int rr) {
  tre[x].l = ll;
  tre[x].r = rr;
  tre[x].mid = (ll + rr) / 2;
  if (ll == rr) {
    tre[x].lnum = l[ll];
    tre[x].rnum = r[rr];
    return;
  }
  build(x * 2, tre[x].l, tre[x].mid);
  build(x * 2 + 1, tre[x].mid + 1, tre[x].r);
  tre[x].lnum = max(tre[x * 2].lnum, tre[x * 2 + 1].lnum);
  tre[x].rnum = max(tre[x * 2].rnum, tre[x * 2 + 1].rnum);
  return;
}
long long askt(int x, int ll, int rr, bool f) {
  if (tre[x].l == ll && tre[x].r == rr) {
    if (f)
      return tre[x].rnum;
    else
      return tre[x].lnum;
  } else {
    if (ll <= tre[x].mid && rr > tre[x].mid)
      return max(askt(x * 2, ll, tre[x].mid, f),
                 askt(x * 2 + 1, tre[x].mid + 1, rr, f));
    else {
      if (rr <= tre[x].mid)
        return askt(x * 2, ll, rr, f);
      else
        return askt(x * 2 + 1, ll, rr, f);
    }
  }
}
void change(int x, int y) {
  if (tre[x].l == tre[x].r) {
    tre[x].lnum = l[y];
    tre[x].rnum = r[y];
  } else {
    if (y <= tre[x].mid)
      change(x * 2, y);
    else
      change(x * 2 + 1, y);
    tre[x].lnum = max(tre[x * 2].lnum, tre[x * 2 + 1].lnum);
    tre[x].rnum = max(tre[x * 2].rnum, tre[x * 2 + 1].rnum);
  }
}
int main() {
  long long ans = 0;
  int q, lx, rx, x;
  int gl, gr, gmid;
  long long now1, now2;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &num[i]);
  num[0] = num[1];
  num[n + 1] = num[n];
  for (int i = 1; i <= n; i++) {
    l[i] = num[i] - num[i - 1];
    r[i] = num[i] - num[i + 1];
    ans += abs(num[i] - num[i - 1]);
    if (l[i] >= 0 && r[i] >= 0) {
      add(i, 1);
      ok[i] = 1;
    }
  }
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d%d%d", &lx, &rx, &x);
      if (ask(rx) > ask(lx - 1))
        printf("%lld\n", ans + 2LL * x);
      else {
        if ((l[lx] < 0 && r[rx] >= 0) || (l[lx] >= 0 && r[rx] < 0)) {
          if (l[lx] < 0 && r[rx] >= 0) {
            now1 = askt(1, lx, rx, 0);
            if (now1 < -x)
              now1 = 0;
            else
              now1 = now1 * 2LL + 2LL * x;
            printf("%lld\n", now1 + ans);
          } else {
            now1 = askt(1, lx, rx, 1);
            if (now1 < -x)
              now1 = 0;
            else
              now1 = now1 * 2LL + 2LL * x;
            printf("%lld\n", now1 + ans);
          }
        } else {
          gl = lx;
          gr = rx;
          while (gl != gr) {
            gmid = (gl + gr + 1) / 2;
            if (l[gmid] >= 0)
              gr = gmid - 1;
            else
              gl = gmid;
          }
          if (r[gl] == 0) {
            now1 = askt(1, lx, gl, 0);
            now2 = askt(1, gl + 1, rx, 1);
            if (now1 < -x)
              now1 = 0;
            else
              now1 = x * 2LL + 2LL * now1;
            if (now2 < -x)
              now2 = 0;
            else
              now2 = x * 2LL + 2LL * now2;
            printf("%lld\n", ans + max(now1, now2));
          } else {
            if (l[gl] < -x)
              now2 = -x;
            else
              now2 = 2LL * l[gl] + x;
            if (r[gl] < -x)
              now2 += -x;
            else
              now2 += 2LL * r[gl] + x;
            if (gl > lx) {
              now1 = askt(1, lx, gl - 1, 0);
              if (now1 < -x)
                now1 = 0;
              else
                now1 = x * 2LL + 2 * now1;
              now2 = max(now1, now2);
            }
            if (gr < rx) {
              now1 = askt(1, gr + 1, rx, 0);
              if (now1 < -x)
                now1 = 0;
              else
                now1 = x * 2LL + 2 * now1;
              now2 = max(now1, now2);
            }
            printf("%lld\n", ans + now2);
          }
        }
      }
    } else {
      scanf("%d%d%d", &lx, &rx, &x);
      ans -= abs(l[lx]);
      l[lx] += x;
      ans += abs(l[lx]);
      r[lx - 1] -= x;
      ans -= abs(r[rx]);
      r[rx] += x;
      ans += abs(r[rx]);
      l[rx + 1] -= x;
      change(1, lx);
      change(1, lx - 1);
      change(1, rx);
      change(1, rx + 1);
      gg(lx);
      gg(rx);
      gg(lx - 1);
      gg(rx + 1);
    }
  }
  return 0;
}
