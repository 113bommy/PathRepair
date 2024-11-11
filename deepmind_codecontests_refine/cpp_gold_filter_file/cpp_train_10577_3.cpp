#include <bits/stdc++.h>
using namespace std;
const int G = 2520;
const int B = 41;
const int MAXN = B * G;
unsigned char S[G][B], ps[B + 1][G][4], mp[256];
string e;
void Pre() {
  mp['A'] = 0;
  mp['G'] = 1;
  mp['T'] = 2;
  mp['C'] = 3;
}
void build(int g) {
  for (int i = 0; i < 4; i++) {
    ps[0][g][i] = 0;
    for (int j = 0; j < B; j++) ps[j + 1][g][i] = ps[j][g][i] + (S[g][j] == i);
  }
}
void chng(int p, char c) {
  S[p % G][p / G] = c;
  build(p % G);
}
inline int nxt(int x, int y) {
  if (x % G <= y)
    return (x + (y - x % G)) / G;
  else
    return (x + (G + y - x % G)) / G;
}
inline int get(int g, int l, int r, int x) { return ps[r][g][x] - ps[l][g][x]; }
int t(int i) { return e[i % e.size()]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Pre();
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) S[i % G][i / G] = mp[s[i]];
  for (int i = 0; i < G; i++) build(i);
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      chng(x, mp[c]);
    } else {
      int l, r;
      cin >> l >> r >> e;
      l--;
      int ans = 0;
      for (int i = 0; i < G; i++) {
        ans += get(i, nxt(l, i), nxt(r, i), mp[t((i - l % G + G) % G)]);
      }
      cout << ans << endl;
    }
  }
}
