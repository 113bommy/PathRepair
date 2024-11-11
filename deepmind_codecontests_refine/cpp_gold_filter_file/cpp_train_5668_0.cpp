#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 0x6fffffff;
const long long MAXLONG = (long long)1 << 60;
const int MAXN = 1e6 + 5;
int man[MAXN + MAXN];
int val[MAXN + MAXN];
int pos[MAXN];
bool ass[MAXN];
int n, m;
inline int lowbit(int x) {
  int ret = x & (-x);
  return ret;
}
void update(int idx, int v) {
  while (idx < MAXN + MAXN) {
    man[idx] += v;
    idx += lowbit(idx);
  }
}
int sum(int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += man[idx];
    idx -= lowbit(idx);
  }
  return ret;
}
int findK(int k, int s, int t) {
  int lo = s, hi = t;
  while (lo + 1 < hi) {
    int md = (lo + hi) >> 1;
    int sm = sum(md);
    if (sm < k) {
      lo = md;
    } else {
      hi = md;
    }
  }
  if (sum(hi) > k) {
    hi--;
  }
  return hi;
}
void init() {
  memset(man, 0, sizeof(man));
  memset(val, 0, sizeof(val));
  memset(ass, 0, sizeof(ass));
  memset(pos, 0, sizeof(pos));
}
int main() {
  while (scanf("%d %d", &n, &m) != -1) {
    init();
    for (long long i = (m + 1); i < (m + 1 + n); i += 1) {
      update(i, 1);
    }
    bool ok = true;
    for (long long i = (0); i < (m); i += 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (!ass[x]) {
        ass[x] = 1;
        int before = sum(m);
        if (y <= before) {
          ok = false;
          continue;
        }
        int pre = findK(y, 0, m + n);
        val[pre] = 0;
        update(pre, -1);
        update(m - i, 1);
        val[m - i] = x;
        pos[pre - m] = x;
      } else {
        int before = sum(m);
        if (y > before) {
          ok = false;
          continue;
        }
        int pre = findK(y, 1, m);
        if (val[pre] != x) {
          ok = false;
          continue;
        }
        val[pre] = 0;
        update(pre, -1);
        update(m - i, 1);
        val[m - i] = x;
      }
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    int nxt = 1;
    for (long long i = (1); i < (n + 1); i += 1) {
      if (pos[i] > 0) {
        printf("%d ", pos[i]);
      } else {
        while (ass[nxt]) {
          nxt++;
        }
        ass[nxt] = 1;
        printf("%d ", nxt);
      }
    }
    puts("");
  }
  return 0;
}
