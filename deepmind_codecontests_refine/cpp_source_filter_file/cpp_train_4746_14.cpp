#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
const int MOD = 1000000009;
const int INF = 1000000000;
const long long LINF = 1000000000000000000LL;
vector<string> vs;
pair<int, int> arr[260][260];
map<string, pair<int, int> > mapa;
int n, m;
long long pdcol[260], pdrow[260];
void debug() {
  for (int i = int(1); i <= int(n); i++) {
    for (int j = int(1); j <= int(m); j++)
      printf("(%d,%d) ", arr[i][j].first, arr[i][j].second);
    puts("");
  }
}
void init() {
  mapa["........."] = make_pair(0, 3), mapa["....O...."] = make_pair(1, 3),
  mapa["..O...O.."] = make_pair(2, 1), mapa["O.......O"] = make_pair(2, 2),
  mapa["..O.O.O.."] = make_pair(3, 1);
  mapa["O...O...O"] = make_pair(3, 2), mapa["O.O...O.O"] = make_pair(4, 3),
  mapa["O.O.O.O.O"] = make_pair(5, 3), mapa["O.OO.OO.O"] = make_pair(6, 1),
  mapa["OOO...OOO"] = make_pair(6, 2);
  string str;
  cin >> n >> m;
  for (int i = int(1); i <= int(4 * n + 1); i++) cin >> str, vs.push_back(str);
  for (int i = int(1); i <= int(n); i++)
    for (int j = int(1); j <= int(m); j++) {
      str = "";
      for (int k = int(1); k <= int(3); k++)
        str += vs[4 * (i - 1) + k].substr(4 * (j - 1) + 1, 3);
      arr[i][j] = mapa[str];
    }
}
long long uni(int c) {
  if (n % 2) return 0LL;
  long long ret = 1LL;
  for (int i = int(1); i <= int(n); i++) ret &= arr[i][c].second & 1;
  return ret;
}
long long dupla(int c) {
  for (int i = int(1); i <= int(n); i++) {
    pdrow[i] = 1LL * (arr[i][c - 1].second & 2) / 2LL * (arr[i][c].second & 2) /
               2LL * pdrow[i - 1];
    if (i > 1)
      pdrow[i] = (pdrow[i] + 1LL * (arr[i - 1][c - 1].second & 1) *
                                 (arr[i - 1][c].second & 1) *
                                 (arr[i][c - 1].second & 1) *
                                 (arr[i][c].second & 1) * pdrow[i - 2] % MOD) %
                 MOD;
  }
  pdrow[n] = (pdrow[n] - 1LL * uni(c) * uni(c - 1) + MOD) % MOD;
  return pdrow[n];
}
int main() {
  init(), pdcol[0] = pdrow[0] = 1LL;
  for (int i = int(1); i <= int(m); i++) {
    pdcol[i] = 1LL * uni(i) * pdcol[i - 1];
    if (i > 1)
      pdcol[i] = (pdcol[i] + 1LL * dupla(i) * pdcol[i - 2] % MOD) % MOD;
  }
  cout << pdcol[m] << endl;
  return 0;
}
