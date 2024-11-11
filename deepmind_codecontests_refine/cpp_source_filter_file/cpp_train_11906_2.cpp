#include <bits/stdc++.h>
using namespace std;
void calc(int, int, vector<int>&);
const int MAXN = 512, MAXQ = 6e5 + 15;
bitset<MAXN> le[MAXN][MAXN], ri[MAXN][MAXN];
vector<int> FN;
char a[MAXN][MAXN];
int n, m, q;
bool ans[MAXQ];
int sx[MAXQ], sy[MAXQ], ex[MAXQ], ey[MAXQ];
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cerr << "HELLO WORLD :)\n";
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    sx[i]--, sy[i]--, ex[i]--, ey[i]--;
  }
  FN.resize(q);
  iota(FN.begin(), FN.end(), 0);
  calc(0, n - 1, FN);
  for (int i = 0; i < q; i++) cout << (ans[i] ? "YES " : "NO ");
  return cout << '\n', false;
}
void calc(int b, int e, vector<int>& g) {
  if (b > e || g.empty()) return;
  int mid = (b + e) >> 1;
  for (int i = mid; i <= e; i++)
    for (int j = 0; j < m; j++) {
      ri[i][j].reset();
      if (a[i][j] == '#') continue;
      if (i == mid)
        ri[i][j][j] = 1;
      else
        ri[i][j] |= ri[i - 1][j];
      if (j > 0) ri[i][j] |= ri[i][j - 1];
    }
  for (int i = mid; i >= b; i--)
    for (int j = m - 1; ~j; j--) {
      le[i][j].reset();
      if (a[i][j] == '#') continue;
      if (i == mid)
        le[i][j][j] = 1;
      else
        le[i][j] |= le[i + 1][j];
      if (j + 1 < m) le[i][j] |= le[i][j + 1];
    }
  vector<int> l, r;
  for (auto i : g) {
    if (ex[i] < mid)
      l.push_back(i);
    else if (sx[i] > mid)
      r.push_back(i);
    else
      ans[i] = (le[sx[i]][sy[i]] & ri[ex[i]][ey[i]]).any();
  }
  calc(b, mid - 1, l);
  calc(mid + 1, e, r);
}
