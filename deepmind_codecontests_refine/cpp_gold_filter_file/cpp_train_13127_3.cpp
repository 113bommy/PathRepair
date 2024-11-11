#include <bits/stdc++.h>
using namespace std;
struct node {
  int l, r, len;
};
char s[100010];
int n, m, pre[100010][30], nxt[100010][30];
int f[100010][30], fl[100010][30], fr[100010][30];
vector<node> v;
vector<int> g;
bool cmp(node x, node y) { return x.len < y.len; }
inline int mex(int mask) {
  for (int i = 0; i < 26; i++) {
    if (!(mask & (1 << i))) {
      return i;
    }
  }
  return 26;
}
int work1(int i, int j) {
  int mask = 0;
  for (int k = 0; k < 26; k++) {
    if (nxt[i][k] > j) {
      continue;
    }
    int l = nxt[i][k];
    int r = pre[j][k];
    int h = nxt[l + 1][k], now = 0;
    while (h <= r) {
      now ^= f[h][k];
      h = nxt[h + 1][k];
    }
    if (i < l) {
      if (fr[i][k] == -1) {
        fr[i][k] = work1(i, l - 1);
      }
      now ^= fr[i][k];
    }
    if (j > r) {
      if (fl[j][k] == -1) {
        fl[j][k] = work1(r + 1, j);
      }
      now ^= fl[j][k];
    }
    if (now < 26) {
      mask |= (1 << now);
    }
  }
  return mex(mask);
}
int work2(int i, int j) {
  int mask = 0;
  for (int k = 0; k < 26; k++) {
    if (nxt[i][k] > j) {
      continue;
    }
    int l = nxt[i][k];
    int r = pre[j][k];
    int now = f[l][k] ^ f[r][k];
    if (i < l) {
      if (fr[i][k] == -1) {
        fr[i][k] = work2(i, l - 1);
      }
      now ^= fr[i][k];
    }
    if (j > r) {
      if (fl[j][k] == -1) {
        fl[j][k] = work2(r + 1, j);
      }
      now ^= fl[j][k];
    }
    if (now < 26) {
      mask |= (1 << now);
    }
  }
  return mex(mask);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 0; i < 26; i++) {
    pre[0][i] = 0;
    nxt[n + 1][i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      pre[i][j] = pre[i - 1][j];
    }
    pre[i][s[i] - 'a'] = i;
  }
  for (int i = n; i; i--) {
    for (int j = 0; j < 26; j++) {
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][s[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; i++) {
    g.clear();
    for (int j = 1; j <= n; j++) {
      if (s[j] == 'a' + i) {
        g.push_back(j);
      }
    }
    for (int j = 1; j < g.size(); j++) {
      v.push_back((node){g[j - 1], g[j], g[j] - g[j - 1] + 1});
    }
  }
  sort(v.begin(), v.end(), cmp);
  memset(fl, -1, sizeof(fl));
  memset(fr, -1, sizeof(fr));
  for (int i = 0; i < v.size(); i++) {
    int l = v[i].l;
    int r = v[i].r;
    if (l + 1 >= r) {
      continue;
    }
    f[r][s[r] - 'a'] = work1(l + 1, r - 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      f[i][j] ^= f[i - 1][j];
    }
  }
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (work2(l, r)) {
      puts("Alice");
    } else {
      puts("Bob");
    }
  }
  return 0;
}
