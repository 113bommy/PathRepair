#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmin(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
void chkmax(T &x, T y) {
  if (y > x) x = y;
}
const int N = 100005, Q = 500005, kc = 500;
int n, q, k, now = 1, opt, x, y, len, lp = 1, rpp;
int bcj[N], siz[N], top;
pair<int, int> sta[N];
struct node {
  int t, x, y;
} o[Q];
int ask(int x) { return x == bcj[x] ? x : ask(bcj[x]); }
void merge(int x, int y) {
  x = ask(x);
  y = ask(y);
  if (siz[x] < siz[y]) swap(x, y);
  sta[++top] = pair<int, int>(x, y);
  if (x == y) return;
  siz[x] += siz[y];
  bcj[y] = x;
}
void ctrlz() {
  int x = sta[top].first, y = sta[top].second;
  top--;
  if (x == y) return;
  siz[x] -= siz[y];
  bcj[y] = y;
}
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 1; i <= (n); i++) bcj[i] = i, siz[i] = 1;
  for (int i = 1; i <= (q); i++) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &x, &y);
      o[++len] = {now, x, y};
      if (len % kc == 0) {
        rpp = len;
        for (int j = 1; j <= (n); j++) bcj[j] = j, siz[j] = 1;
        top = 0;
        for (int j = rpp; j >= (lp); j--) merge(o[j].x, o[j].y);
      }
    } else if (opt == 2) {
      scanf("%d", &x);
      y = max(lp, rpp + 1);
      for (int j = y; j <= (len); j++) merge(o[j].x, o[j].y);
      printf("%d\n", siz[ask(x)]);
      for (int j = len; j >= (y); j--) ctrlz();
    } else {
      now++;
      while (lp <= len && o[lp].t + k <= now)
        if (lp++ <= rpp) ctrlz();
    }
  }
}
