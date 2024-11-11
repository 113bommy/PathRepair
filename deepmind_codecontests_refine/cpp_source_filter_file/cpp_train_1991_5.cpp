#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
int n, q, l[5], r[5], cnt[5], id[1000];
char s[N];
set<int> p[3];
set<int>::iterator it;
struct tree {
  int sh[N];
  inline int lowbit(int x) { return (x & (-x)); }
  inline void change(int x, int v) {
    while (x <= n) {
      sh[x] += v;
      x += lowbit(x);
    }
  }
  inline int query(int x) {
    int ans = 0;
    while (x > 0) {
      ans += sh[x];
      x -= lowbit(x);
    }
    return ans;
  }
} T[3];
inline int win(int s) { return (s + 1) % 3; }
inline int lose(int s) { return (s + 2) % 3; }
inline int get() {
  int ans = 0;
  for (int ch = 0; ch < 3; ch++) {
    if (cnt[lose(ch)] == 0) {
      ans += cnt[ch];
      continue;
    }
    if (cnt[win(ch)] == 1) {
      if (cnt[lose(ch)] == 1) {
        int L = min(l[lose(ch)], l[win(ch)]), R = max(l[lose(ch)], l[win(ch)]);
        ans += cnt[ch] - (T[ch].query(R) - T[ch].query(L - 1));
      }
      if (cnt[lose(ch)] == 2) {
        int L = min(l[lose(ch)], l[win(ch)]), R = max(r[lose(ch)], l[win(ch)]);
        ans += cnt[ch] - (T[ch].query(R) - T[ch].query(L - 1));
      }
    }
    if (cnt[win(ch)] == 2) {
      if (cnt[lose(ch)] == 1) {
        int pos = l[lose(ch)];
        ans += cnt[ch];
        if (pos < l[win(ch)])
          ans -= T[ch].query(l[win(ch)]) - T[ch].query(pos - 1);
        if (pos > r[win(ch)])
          ans -= T[ch].query(pos) - T[ch].query(r[win(ch)] - 1);
      }
      if (cnt[lose(ch)] == 2) {
        ans += cnt[ch];
        if (l[lose(ch)] < l[win(ch)])
          ans -= T[ch].query(l[win(ch)]) - T[ch].query(l[lose(ch)] - 1);
        if (r[lose(ch)] > r[win(ch)])
          ans -= T[ch].query(r[lose(ch)]) - T[ch].query(r[win(ch)] - 1);
      }
    }
  }
  return ans;
}
signed main() {
  id['S'] = 0;
  id['P'] = 1;
  id['R'] = 2;
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) cnt[id[s[i]]]++, p[id[s[i]]].insert(i);
  for (int i = 1; i <= n; i++) T[id[s[i]]].change(i, 1);
  for (int i = 0; i < 3; i++) {
    if (p[i].empty()) continue;
    l[i] = *p[i].begin();
    r[i] = *p[i].rbegin();
  }
  printf("%d\n", get());
  int wh;
  char op[5];
  while (q--) {
    scanf("%d%s", &wh, op);
    it = p[id[s[wh]]].lower_bound(wh);
    p[id[s[wh]]].erase(it);
    p[id[op[0]]].insert(wh);
    T[id[s[wh]]].change(wh, -1);
    T[id[op[0]]].change(wh, 1);
    cnt[id[s[wh]]]--;
    cnt[id[op[0]]]++;
    s[wh] = op[0];
    for (int i = 0; i < 3; i++) {
      if (p[i].empty()) continue;
      l[i] = *p[i].begin();
      r[i] = *p[i].rbegin();
    }
    printf("%d\n", get());
  }
}
