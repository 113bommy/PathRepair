#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<int> x) {
  for (int i = 0; i < (int)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (int)x.size() - 1]);
}
int s[22], len[22], t[22];
struct Seg {
  int l, r, id;
};
Seg a[22];
struct Node {
  int len, id;
};
Node b[22];
int f[1 << 22], fr[1 << 22], be[1 << 22], n, p;
int ans[22], ans2[22];
int get(int val) {
  for (int i = 0; i < n; i++) {
    if (val >> i & 1) return i;
  }
  assert(0);
}
signed main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) s[i] = read(), len[i] = read(), t[i] = read();
  for (int i = 0; i < n; i++)
    a[i].l = s[i], a[i].r = s[i] + len[i] - 1, a[i].id = i;
  for (int i = 0; i < n; i++) b[i].len = t[i], b[i].id = i;
  sort(a, a + n, [&](Seg x, Seg y) { return x.l < y.l; });
  sort(b, b + n, [&](Node x, Node y) { return x.len < y.len; });
  memset(f, 0x3f, sizeof(f));
  f[0] = 1;
  a[n].l = 0x3f3f3f3f;
  for (int i = 0; i < 1 << n; i++) {
    if (f[i] == 0x3f3f3f3f) continue;
    int cur = 0, beg;
    while (cur < n && a[cur].r < f[i]) cur++;
    if (cur == n) continue;
    beg = f[i];
    while (a[cur].l <= beg && a[cur].r >= beg) beg = a[cur].r + 1, cur++;
    while (cur < n && !(i >> a[cur].id & 1)) cur++;
    for (int j = 0; j < n; j++) {
      if (i >> b[j].id & 1) continue;
      if (a[cur].l - beg - 1 >= b[j].len) {
        if (beg + b[j].len < f[i | 1 << b[j].id] &&
            beg + b[j].len < s[b[j].id]) {
          f[i | 1 << b[j].id] = beg + b[j].len;
          fr[i | 1 << b[j].id] = i;
          be[i | 1 << b[j].id] = beg;
        }
      } else {
        while (a[cur].l - beg - 1 < b[j].len) {
          beg = a[cur].r + 1;
          cur++;
          while (a[cur].l <= beg && a[cur].r >= beg) beg = a[cur].r + 1, cur++;
          while (cur < n && !(i >> a[cur].id & 1)) cur++;
        }
        if (a[cur].l - beg - 1 >= b[j].len) {
          if (beg + b[j].len < f[i | 1 << b[j].id] &&
              beg + b[j].len < s[b[j].id]) {
            f[i | 1 << b[j].id] = beg + b[j].len;
            fr[i | 1 << b[j].id] = i;
            be[i | 1 << b[j].id] = beg;
          }
        }
      }
    }
  }
  int LIM = (1 << n) - 1;
  if (p == 1) {
    if (f[LIM] != 0x3f3f3f3f) {
      cout << "YES\n";
      int tmp = LIM;
      while (tmp) {
        int t = fr[tmp];
        ans[get(tmp ^ t)] = be[tmp];
        ans2[get(tmp ^ t)] = 1;
        tmp = t;
      }
      for (int i = 0; i < n; i++) printf("%d %d\n", ans2[i], ans[i]);
      return 0;
    }
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < 1 << n; i++) {
    if (f[i] != 0x3f3f3f3f && f[LIM ^ i] != 0x3f3f3f3f) {
      cout << "YES\n";
      int tmp = i;
      while (tmp) {
        int t = fr[tmp];
        ans[get(tmp ^ t)] = be[tmp];
        ans2[get(tmp ^ t)] = 1;
        tmp = t;
      }
      tmp = LIM ^ i;
      while (tmp) {
        int t = fr[tmp];
        ans[get(tmp ^ t)] = be[tmp];
        ans2[get(tmp ^ t)] = 2;
        tmp = t;
      }
      for (int i = 0; i < n; i++) printf("%d %d\n", ans2[i], ans[i]);
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
