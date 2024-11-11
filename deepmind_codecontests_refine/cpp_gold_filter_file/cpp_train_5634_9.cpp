#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double pii = 3.14159265359;
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int> > grd(N, vector<int>(M));
  vector<vector<int> > ans(N, vector<int>(M));
  for (int x = 0; x < (N); x++) {
    string str;
    cin >> str;
    for (int y = 0; y < (M); y++) {
      grd[x][y] = str[y] == '#' ? 1 : 0;
    }
  }
  for (int x = 0; x < (N - 2); x++) {
    for (int y = 0; y < (M - 2); y++) {
      bool flag = true;
      for (int z = 0; z < (3); z++) {
        if (!grd[x + z][y]) flag = false;
        if (!grd[x + z][y + 2]) flag = false;
      }
      if (!grd[x][y + 1] || !grd[x + 2][y + 1]) flag = false;
      if (flag) {
        for (int z = 0; z < (3); z++) {
          ans[x + z][y] = 1;
          ans[x + z][y + 2] = 1;
        }
        ans[x][y + 1] = ans[x + 2][y + 1] = 1;
      }
    }
  }
  if (ans != grd) {
    cout << "NO" << nl;
  } else
    cout << "YES" << nl;
  return 0;
}
