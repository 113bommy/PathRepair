#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int MX = 1 << 23;
int a, b, c, d, i, j, n, m, k;
int lenl[MX + 1], lenr[MX + 1], cnt[MX + 1], len[MX + 1], num[MX + 1];
pair<int, int> sm[MX + 1];
map<int, int> onwork;
inline int create(int l, int r) {
  sm[k] = make_pair(-1, -1);
  cnt[k] = 0;
  len[k] = lenl[k] = lenr[k] = r - l;
  num[k] = l;
  return k++;
}
inline int getcnt(int l, int r, int a, int b, int v) {
  if (l >= r || a > b) return 0;
  if (l == a && b == r - 1) return cnt[v];
  int xx = (r + l) / 2;
  if (b < xx) {
    if (sm[v].first == -1) sm[v].first = create(l, xx);
    return getcnt(l, xx, a, b, sm[v].first);
  }
  if (a >= xx) {
    if (sm[v].second == -1) sm[v].second = create(xx, r);
    return getcnt(xx, r, a, b, sm[v].second);
  }
  if (sm[v].first == -1) sm[v].first = create(l, xx);
  if (sm[v].second == -1) sm[v].second = create(xx, r);
  return getcnt(l, xx, a, xx - 1, sm[v].first) +
         getcnt(xx, r, xx, b, sm[v].second);
}
void add(int l, int r, int first, int cc, int v) {
  if (l >= r || first >= r || first < l) return;
  if (l == r - 1) {
    cnt[v] = cc;
    num[v] = l;
    lenl[v] = lenr[v] = len[v] = cc ^ 1;
    return;
  }
  int xx = (r + l) / 2;
  if (sm[v].first == -1) sm[v].first = create(l, xx);
  if (sm[v].second == -1) sm[v].second = create(xx, r);
  if (first < xx) {
    add(l, xx, first, cc, sm[v].first);
  } else {
    add(xx, r, first, cc, sm[v].second);
  }
  lenl[v] = lenr[v] = len[v] = 0;
  cnt[v] = 0;
  {
    lenl[v] = lenl[sm[v].first];
    len[v] = len[sm[v].first];
    num[v] = num[sm[v].first];
    cnt[v] = cnt[sm[v].first];
  }
  {
    if (lenl[v] == xx - l) lenl[v] += lenl[sm[v].second];
    lenr[v] = lenr[sm[v].second];
    if (lenr[v] == r - xx) lenr[v] += lenr[sm[v].first];
    if (lenr[sm[v].first] + lenl[sm[v].second] >= len[v]) {
      len[v] = lenr[sm[v].first] + lenl[sm[v].second];
      num[v] = xx - lenr[sm[v].first];
    }
    if (len[sm[v].second] >= len[v]) {
      len[v] = len[sm[v].second];
      num[v] = num[sm[v].second];
    }
    cnt[v] += cnt[sm[v].second];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  sm[0] = make_pair(-1, -1);
  lenl[0] = lenr[0] = len[0] = n;
  num[0] = 1;
  k = 1;
  for (int _n((m)-1), i(0); i <= _n; i++) {
    scanf("%d", &a);
    if (!a) {
      scanf("%d%d", &a, &b);
      printf("%d\n", getcnt(1, n + 1, a, b, 0));
    } else {
      if (onwork.count(a)) {
        add(1, n + 1, onwork[a], 0, 0);
        onwork.erase(onwork.find(a));
      } else {
        int l = num[0], r = num[0] + len[0];
        add(1, n + 1, (r + l) / 2, 1, 0);
        onwork[a] = (r + l) / 2;
      }
    }
  }
}
