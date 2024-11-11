#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int main() {
  int n, s, q;
  scanf("%d %d %d", &n, &s, &q);
  vector<bitset<N>> st(s + 1);
  for (int i = 0; i < s; i++) {
    int c;
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
      int m;
      scanf("%d", &m);
      st[i][m - 1] = 1;
    }
  }
  unordered_map<bitset<N>, int> mp_pre, mp_suf;
  auto init = [&](int s) {
    int half = s / 3;
    for (int i = 0; i < (1 << half); i++) {
      bitset<N> sta;
      for (int j = 0; j < half; j++)
        if ((i >> j) & 1) sta ^= st[j];
      int cnt = __builtin_popcount(i);
      if (!mp_pre.count(sta))
        mp_pre[sta] = cnt;
      else
        mp_pre[sta] = min(mp_pre[sta], cnt);
    }
    for (int i = 0; i < (1 << (s - half)); i++) {
      bitset<N> sta;
      for (int j = 0; j < s - half; j++)
        if ((i >> j) & 1) sta ^= st[half + j];
      int cnt = __builtin_popcount(i);
      if (!mp_suf.count(sta))
        mp_suf[sta] = cnt;
      else
        mp_suf[sta] = min(mp_suf[sta], cnt);
    }
  };
  init(s);
  while (q--) {
    bitset<N> sta;
    int c;
    scanf("%d", &c);
    for (int i = 1; i <= c; i++) {
      int m;
      scanf("%d", &m);
      sta[m - 1] = 1;
    }
    int mi = INF;
    for (auto it : mp_pre) {
      auto x = it.first;
      auto y = it.second;
      if (mp_suf.count(sta ^ x)) mi = min(mi, y + mp_suf[sta ^ x]);
    }
    if (mi == INF)
      printf("-1\n");
    else
      printf("%d\n", mi);
  }
  return 0;
}
