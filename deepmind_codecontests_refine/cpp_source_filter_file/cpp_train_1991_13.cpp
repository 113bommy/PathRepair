#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, q;
struct player {
  int freq[3];
  player operator+(const player &a) {
    player ret;
    for (int i = 0; i < 3; i++) ret.freq[i] = freq[i] + a.freq[i];
    return ret;
  }
} seg[4 * N];
string s;
set<int> st[3];
void build(int c, int l, int r, int s, int e) {
  if (l > e || r < s) return;
  if (l == r) {
    memset(seg[c].freq, 0, sizeof seg[c].freq);
    if (::s[l] == 'R') {
      seg[c].freq[0]++;
      st[0].insert(l);
    } else if (::s[l] == 'P') {
      seg[c].freq[1]++;
      st[1].insert(l);
    } else {
      seg[c].freq[2]++;
      st[2].insert(l);
    }
    return;
  }
  build(2 * c + 1, l, (l + r) / 2, s, e);
  build(2 * c + 2, (l + r) / 2 + 1, r, s, e);
  seg[c] = seg[2 * c + 1] + seg[2 * c + 2];
}
int get(int c, int l, int r, int s, int e, int at) {
  if (l > e || r < s) return 0;
  if (l >= s && r <= e) return seg[c].freq[at];
  return get(2 * c + 1, l, (l + r) / 2, s, e, at) +
         get(2 * c + 2, (l + r) / 2 + 1, r, s, e, at);
}
void find() {
  int ret = n;
  for (int i = 0; i < 3; i++)
    if (st[i].size() == n) {
      printf("%d\n", n);
      return;
    }
  for (int i = 0; i < 3; i++)
    if (st[i].empty()) {
      printf("%d\n", st[(i + 2) % 3].size());
      return;
    }
  for (int i = 0; i < 3; i++) {
    if (*st[(i + 1) % 3].begin() < *st[(i + 2) % 3].begin())
      ret -= get(0, 0, n - 1, *st[(i + 2) % 3].begin(),
                 *st[(i + 2) % 3].begin(), i);
    if (*st[(i + 1) % 3].rbegin() > *st[(i + 2) % 3].rbegin())
      ret -= get(0, 0, n - 1, *st[(i + 2) % 3].rbegin(),
                 *st[(i + 1) % 3].rbegin(), i);
  }
  printf("%d\n", ret);
}
int main() {
  scanf("%d%d", &n, &q);
  cin >> s;
  build(0, 0, n - 1, 0, n - 1);
  find();
  char c;
  for (int i = 0, id, at; i < q; i++) {
    scanf("%d %c", &id, &c);
    id--;
    int was;
    if (s[id] == 'R')
      was = 0;
    else if (s[id] = 'P')
      was = 1;
    else
      was = 2;
    st[was].erase(id);
    s[id] = c;
    build(0, 0, n - 1, id, id);
    find();
  }
}
