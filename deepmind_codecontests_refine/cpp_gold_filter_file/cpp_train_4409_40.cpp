#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <class T>
inline void read(T &x) {
  char c;
  int flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag *= -1;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= flag;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, m, ctrow = 0, ctcol = 0;
  char board;
  vector<pair<long long int, long long int> > all;
  cin >> n >> m;
  bool strow[n + 5], stcol[m + 5];
  memset(strow, (false), sizeof(strow));
  memset(stcol, (false), sizeof(stcol));
  for (long long int i = 1; i <= n; i += 1) {
    for (long long int j = 1; j <= m; j += 1) {
      cin >> board;
      if (board == '*') {
        all.push_back({i, j});
      }
    }
  }
  for (long long int i = 0; i <= 3 - 1; i += 1) {
    if (!strow[all[i].first]) {
      strow[all[i].first] = true;
      ctrow += all[i].first;
    } else
      ctrow -= all[i].first;
    if (!stcol[all[i].second]) {
      stcol[all[i].second] = true;
      ctcol += all[i].second;
    } else
      ctcol -= all[i].second;
  }
  cout << ctrow << ' ' << ctcol << '\n';
  return 0;
}
