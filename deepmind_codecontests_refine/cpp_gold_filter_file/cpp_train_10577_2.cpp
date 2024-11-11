#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
struct node {
  int a, t, g, c;
} * t[10][11];
void update(int sh, int st, int v, int tl, int tr, int pos, char val) {
  if (tl == tr) {
    t[sh][st][v].a = t[sh][st][v].t = t[sh][st][v].g = t[sh][st][v].c = 0;
    if (val == 'A') t[sh][st][v].a++;
    if (val == 'T') t[sh][st][v].t++;
    if (val == 'G') t[sh][st][v].g++;
    if (val == 'C') t[sh][st][v].c++;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    update(sh, st, v * 2, tl, tm, pos, val);
  else
    update(sh, st, v * 2 + 1, tm + 1, tr, pos, val);
  t[sh][st][v].a = t[sh][st][v * 2].a + t[sh][st][v * 2 + 1].a;
  t[sh][st][v].g = t[sh][st][v * 2].g + t[sh][st][v * 2 + 1].g;
  t[sh][st][v].t = t[sh][st][v * 2].t + t[sh][st][v * 2 + 1].t;
  t[sh][st][v].c = t[sh][st][v * 2].c + t[sh][st][v * 2 + 1].c;
}
int get(int sh, int st, int v, int tl, int tr, int l, int r, char val) {
  if (tl == l && tr == r) {
    if (val == 'A') return t[sh][st][v].a;
    if (val == 'T') return t[sh][st][v].t;
    if (val == 'G') return t[sh][st][v].g;
    if (val == 'C') return t[sh][st][v].c;
  }
  if (l > r) return 0;
  int tm = (tl + tr) / 2;
  return get(sh, st, v * 2, tl, tm, l, min(r, tm), val) +
         get(sh, st, v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s >> q;
  n = s.size();
  for (int i = 0; i < 10; i++)
    for (int st = 1; st <= 10; st++) t[i][st] = new node[4 * ((n / st) + 5)];
  for (int i = 0; i < s.size(); i++) {
    for (int sh = 0; sh < 10 && i >= sh; sh++) {
      int p = i - sh;
      for (int st = 1; st <= 10; st++)
        if (p % st == 0) update(sh, st, 1, 0, n / st + 5, p / st, s[i]);
    }
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      for (int sh = 0; sh < 10 && pos >= sh; sh++) {
        int p = pos - sh;
        for (int st = 1; st <= 10; st++)
          if (p % st == 0) update(sh, st, 1, 0, n / st + 5, p / st, c);
      }
    } else {
      int l, r, ans = 0;
      string e;
      cin >> l >> r >> e;
      l--;
      r--;
      int st = e.size();
      int sh = l % st;
      for (int i = 0; i < e.size() && r >= sh && r - l >= i; i++) {
        int ri = r - sh;
        int le = max(0, l - sh);
        ans += get(sh, st, 1, 0, n / st + 5, le / st + (le % st != 0), ri / st,
                   e[i]);
        sh = (sh + 1) % st;
      }
      cout << ans << endl;
    }
  }
}
