#include <bits/stdc++.h>
using namespace std;
const int di[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
const int dj[] = {-1, 0, 1, 0, -1, 1, -1, 1, 0};
int a, b, c, d, i, j, n, m, k;
pair<int, int> w1, w2, wk, bk;
inline void get(pair<int, int> &a) {
  string s;
  cin >> s;
  a.first = s[0] - 'a';
  a.second = s[1] - '1';
}
inline bool bt(pair<int, int> w, pair<int, int> t) {
  if (w.first != t.first && w.second != t.second) return 0;
  if (w.first == t.first) {
    if (wk.first == w.first && wk.second >= min(w.second, t.second) &&
        wk.second <= max(w.second, t.second))
      return 0;
  } else {
    if (wk.second == w.second && wk.first >= min(w.first, t.first) &&
        wk.first <= max(w.first, t.first))
      return 0;
  }
  return 1;
}
inline bool beat(pair<int, int> t) {
  if (w1 != t && bt(w1, t)) return 1;
  if (w2 != t && bt(w2, t)) return 1;
  return abs(t.first - wk.first) <= 1 && abs(t.second - wk.second) <= 1;
}
int main() {
  get(w1);
  get(w2);
  get(wk);
  get(bk);
  a = 1;
  for (int z = 0; z < 9; z++) {
    int ni = bk.first + di[z];
    int nj = bk.second + dj[z];
    if (ni < 0 || ni >= 8 || nj < 0 || nj >= 8) continue;
    if (!beat(make_pair(ni, nj))) {
      a = 0;
      break;
    }
  }
  if (a) {
    cout << "CHECKMATE";
  } else
    cout << "OTHER";
  return 0;
}
