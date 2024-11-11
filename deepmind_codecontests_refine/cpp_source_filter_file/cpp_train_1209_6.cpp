#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
inline char mygetchar() {
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
const int Bsz = 500, B = 2000;
int n, m, a[200111], cnt[200111];
long long v[200111], sum[500];
vector<int> pos[200111], big, color;
vector<pair<int, int> > qr[200111];
long long ans[200111];
void add(int x, long long t) {
  v[x] += t;
  sum[x / Bsz] += t;
}
long long query(int x) {
  int i = 0;
  long long res = 0;
  while (i + Bsz - 1 <= x) res += sum[i / Bsz], i += Bsz;
  while (i <= x) res += v[i], i++;
  return res;
}
int main() {
  n = getnum(), m = getnum();
  for (int i = 1; i <= n; i++) a[i] = getnum(), color.push_back(a[i]);
  sort(color.begin(), color.end());
  color.erase(unique(color.begin(), color.end()), color.end());
  int tot = color.size();
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(color.begin(), color.end(), a[i]) - color.begin();
    pos[a[i]].push_back(i);
  }
  for (int i = 0; i < tot; i++) {
    if (pos[i].size() > B) {
      big.push_back(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    l = getnum(), r = getnum();
    qr[r].push_back(make_pair(l - 1, i));
  }
  for (int i = 1; i <= n; i++) {
    if (pos[a[i]].size() <= B) add(i, color[a[i]]);
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += 1ll * color[a[i]] * (cnt[a[i]] * 2 + 1);
    cnt[a[i]]++;
    if (pos[a[i]].size() <= B) {
      for (int j = 0; j < pos[a[i]].size() && pos[a[i]][j] < i; j++) {
        add(pos[a[i]][j], 2 * color[a[i]]);
      }
    }
    for (int j = 0; j < qr[i].size(); j++) {
      long long &r = ans[qr[i][j].second];
      r = sum - query(qr[i][j].first);
      for (int k = 0; k < big.size(); k++) {
        long long tt = upper_bound(pos[big[k]].begin(), pos[big[k]].end(),
                                   qr[i][j].first) -
                       pos[big[k]].begin();
        r -= 1ll * tt * (2 * cnt[big[k]] - tt) * color[a[big[k]]];
      }
    }
  }
  for (int i = 1; i <= m; i++) putnum(ans[i]), putendl();
  return 0;
}
