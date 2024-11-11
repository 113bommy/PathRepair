#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
bitset<100010> a[44];
int now, n, t, ans, m, ren, c[55][55], p[500010], tp[500010];
string s;
map<string, int> M;
bool u[500010];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  now = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> tp[i];
    if (tp[i] == 1) {
      if (tp[i - 1] == 1) continue;
      ++now;
    } else {
      cin >> s;
      if (M.find(s) == M.end()) M[s] = ++ren;
      t = M[s];
      a[t][now] = 1;
    }
  }
  for (int i = 1; i <= ren; ++i) c[i][i] = 1;
  for (int i = 1; i <= ren; ++i)
    for (int j = i + 1; j <= ren; ++j)
      if (((int)(a[i] & a[j]).count()) != 0) {
        c[i][j] = c[j][i] = 0;
      } else
        c[i][j] = c[j][i] = 1;
  int rp = 41;
  while (rp--) {
    for (int i = 1; i <= ren; ++i) p[i] = i;
    random_shuffle(p + 1, p + ren + 1);
    int s = 0;
    for (int i = 1; i <= ren; ++i) u[i] = 0;
    for (int i = 1; i <= ren; ++i) {
      bool gg = 0;
      int x = p[i];
      for (int j = 1; j <= ren; ++j)
        if (u[j] && !c[j][x]) gg = 1;
      if (!gg) {
        ++s;
        u[x] = 1;
      }
    }
    ans = max(ans, s);
  }
  cout << ans << endl;
  return 0;
}
