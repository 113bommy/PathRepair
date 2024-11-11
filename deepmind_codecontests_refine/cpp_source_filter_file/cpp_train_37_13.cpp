#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1001000;
int pfx[NMAX];
int f[NMAX][20];
string s[NMAX];
int n, r, c;
void buildf() {
  int j = 1;
  for (int i = 1; i <= n; ++i) {
    while (j <= n && pfx[j] - pfx[i - 1] - 1 <= c) {
      ++j;
    }
    f[i][0] = j;
  }
  f[n + 1][0] = n + 1;
  for (int l = 1; l < 20; ++l) {
    for (int i = 1; i <= n; ++i) {
      f[i][l] = f[f[i][l - 1]][l - 1];
    }
  }
}
void swim(int& x, int h) {
  for (int i = 0; i < 20; ++i) {
    if (h & 1) x = f[x][i];
    h >>= 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> r >> c;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  pfx[0] = 0;
  for (int i = 1; i <= n; ++i) {
    pfx[i] = pfx[i - 1] + s[i].size() + 1;
  }
  buildf();
  pair<long long, long long> best(0, 0);
  for (int i = 1; i <= n; ++i) {
    int j = i;
    swim(j, r);
    best = max(best, pair<long long, long long>(j - i, i));
  }
  int p = best.second;
  int sz = 0;
  for (int i = 0; i < r && sz < best.first; + i, p = f[p][0]) {
    for (int j = p; j < f[p][0] - 1; ++j) {
      cout << s[j] << " ";
      ++sz;
    }
    cout << s[f[p][0] - 1] << "\n";
    ++sz;
  }
  return 0;
}
