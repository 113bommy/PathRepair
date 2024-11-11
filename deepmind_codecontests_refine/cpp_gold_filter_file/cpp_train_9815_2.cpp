#include <bits/stdc++.h>
using namespace std;
bitset<1005> tt[30];
unordered_map<bitset<1005>, int> ff;
pair<bitset<1005>, int> ar[1000005];
int bc[1000005];
void print(bitset<1005> t) {
  for (int i = 0; i < 12; ++i) {
    if (t[i]) {
      putchar('1');
    } else {
      putchar('0');
    }
  }
  putchar('\n');
}
int construct(int l, int r, bool isG) {
  bitset<1005> tmp;
  ar[0] = {tmp, 0};
  int cc = 1;
  for (int i = l; i <= r; ++i) {
    int ind = i;
    if (isG) {
      ind -= l;
    }
    int tcc = cc;
    for (int j = 0; j < cc; ++j) {
      ar[tcc++] = {ar[j].first ^ tt[i], (1 << ind) + ar[j].second};
    }
    cc = tcc;
  }
  if (!isG) {
    for (int i = 0; i < cc; ++i) {
      if (!ff.count(ar[i].first)) {
        ff[ar[i].first] = bc[ar[i].second];
      } else {
        ff[ar[i].first] = min(ff[ar[i].first], bc[ar[i].second]);
      }
    }
  }
  return cc;
}
void solve() {
  int n, s, d;
  scanf("%d %d %d ", &n, &s, &d);
  for (int i = 0; i < s; ++i) {
    int x;
    scanf("%d ", &x);
    while (x--) {
      int t;
      scanf("%d ", &t);
      tt[i][t - 1] = 1;
    }
  }
  bc[0] = 0;
  for (int i = 1; i < 1000005; ++i) {
    bc[i] = bc[i / 2] + (i & 1);
  }
  int g = min(s - 1, 18);
  construct(0, g, 0);
  int sz = construct(g + 1, s - 1, 1);
  while (d--) {
    bitset<1005> tmp;
    int x;
    scanf("%d ", &x);
    while (x--) {
      int t;
      scanf("%d ", &t);
      tmp[t - 1] = 1;
    }
    const int inf = 1e9;
    int ret = inf;
    for (int i = 0; i < sz; ++i) {
      if (ff.count(tmp ^ ar[i].first)) {
        ret = min(ret, bc[ar[i].second] + ff[tmp ^ ar[i].first]);
      }
    }
    if (ret == inf) {
      ret = -1;
    }
    printf("%d\n", ret);
  }
}
int main() {
  solve();
  return 0;
}
