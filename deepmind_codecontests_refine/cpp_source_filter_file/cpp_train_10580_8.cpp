#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
long long seed;
int a[MAXN], le[2 * MAXN], ri[2 * MAXN];
long long data[2 * MAXN];
map<long long, int> s;
int rnd() {
  int ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
void init(int p, int l, int r) {
  le[p] = l;
  ri[p] = r;
  if (l == r) {
    data[p] = a[l];
    return;
  }
  data[p] = -1;
  int m = (l + r) / 2;
  init(p * 2, l, m);
  init(p * 2 + 1, m + 1, r);
}
void add(int p, int l, int r, int x) {
  if (x == 0) return;
  if (data[p] != -1) {
    if (le[p] >= l && ri[p] <= r) {
      data[p] += x;
      return;
    }
    data[p * 2] = data[p];
    data[p * 2 + 1] = data[p];
    data[p] = -1;
  }
  int m = (le[p] + ri[p]) / 2;
  if (m >= l) add(p * 2, l, r, x);
  if (m + 1 <= r) add(p * 2 + 1, l, r, x);
}
void assign(int p, int l, int r, int x) {
  if (le[p] >= l && ri[p] <= r) {
    data[p] = x;
    return;
  }
  if (data[p] != -1 && data[p] != x) {
    data[p * 2] = data[p];
    data[p * 2 + 1] = data[p];
    data[p] = -1;
  }
  int m = (le[p] + ri[p]) / 2;
  if (m >= l) assign(p * 2, l, r, x);
  if (m + 1 <= r) assign(p * 2 + 1, l, r, x);
}
void getrank(int p, int l, int r) {
  if (data[p] != -1) {
    int len = min(r, ri[p]) - max(l, le[p]) + 1;
    s[data[p]] += len;
    return;
  }
  int m = (le[p] + ri[p]) / 2;
  if (m >= l) getrank(p * 2, l, r);
  if (m + 1 <= r) getrank(p * 2 + 1, l, r);
}
long long getpow(long long b, int c, int y) {
  long long ans = 1, cur = b;
  while (c > 0) {
    if (c % 2 == 1) ans = (ans * cur) % y;
    c /= 2;
    cur = (cur * cur) % y;
  }
  return ans;
}
long long sum(int p, int l, int r, int x, int y) {
  long long tot = 0;
  if (data[p] != -1) {
    tot = (min(r, ri[p]) - max(l, le[p]) + 1) * getpow(data[p], x, y) % y;
    return tot;
  }
  int m = (le[p] + ri[p]) / 2;
  if (m >= l) tot = (tot + sum(p * 2, l, r, x, y)) % y;
  if (m + 1 <= r) tot = (tot + sum(p * 2 + 1, l, r, x, y)) % y;
  return tot;
}
int main() {
  int n, m, vmax;
  cin >> n >> m >> seed >> vmax;
  for (int i = 1; i <= n; i++) a[i] = (rnd() % vmax) + 1;
  init(1, 1, n);
  int nout = 0;
  while (m--) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % n) + 1;
    int r = (rnd() % n) + 1;
    int x, y = 0;
    if (l > r) swap(l, r);
    if (op == 3)
      x = (rnd() % (r - l + 1)) + 1;
    else
      x = (rnd() % vmax) + 1;
    if (op == 4) y = (rnd() % vmax) + 1;
    switch (op) {
      case 1:
        add(1, l, r, x);
        break;
      case 2:
        assign(1, l, r, x);
        break;
      case 3: {
        s.erase(s.begin(), s.end());
        getrank(1, l, r);
        int tmp = 0;
        nout++;
        for (map<long long, int>::iterator it = s.begin(); it != s.end();
             it++) {
          tmp += it->second;
          if (tmp >= x) {
            cout << it->first << endl;
            break;
          }
        }
        break;
      }
      case 4: {
        nout++;
        cout << sum(1, l, r, x, y) << endl;
        break;
      }
    }
  }
}
