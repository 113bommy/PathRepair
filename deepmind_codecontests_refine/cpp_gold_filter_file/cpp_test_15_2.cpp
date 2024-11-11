#include <bits/stdc++.h>
using namespace std;
void in() { return; }
template <typename T, typename... Types>
void in(T &a, Types &...b) {
  cin >> (a);
  in(b...);
}
void o() { return; }
template <typename T, typename... Types>
void o(T a, Types... b) {
  cout << (a);
  cout << ' ';
  o(b...);
}
bool sortin(const pair<long long int, long long int> &e,
            const pair<long long int, long long int> &f) {
  return (e.first < f.first);
}
bool POT(long long int x) { return x && (!(x & (x - 1))); }
long long int i, j, k, l, m, n, p, q, r, a, b, c, x, y, z, ts, mn = 1e18,
                                                               mod = 1e9 + 7;
long long int ar[250005], br[250005], xr[250005], tem[250005];
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  in(ts);
  while (ts--) {
    in(n, m, k);
    string s[n + 2];
    vector<vector<long long int> > vis(n + 2, vector<long long int>(m + 2, 0));
    for (long long int i = 0; i <= n - 1; i++) {
      in(s[i]);
    }
    for (long long int i = 0; i <= n - 1; i++) {
      for (long long int j = 0; j <= m - 1; j++) {
        x = i;
        y = j;
        p = q = 0;
        while (x >= 0 and y >= 0 and s[x][y] == '*') x--, y--, p++;
        x = i;
        y = j;
        while (x >= 0 and y < m and s[x][y] == '*') x--, y++, q++;
        if (min(p, q) > k) {
          x = i;
          y = j;
          c = 0;
          while (c < min(p, q)) vis[x--][y--] = 1, c++;
          x = i;
          y = j;
          c = 0;
          while (c < min(p, q)) vis[x--][y++] = 1, c++;
        }
      }
    }
    c = 0;
    for (long long int i = 0; i <= n - 1; i++) {
      for (long long int j = 0; j <= m - 1; j++) {
        if (s[i][j] == '*' and vis[i][j] == 0) {
          c = 1;
          break;
        }
      }
    }
    c ? o("NO") : o("YES");
    cout << endl;
  }
}
