#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int N = 55;
bool st[N * 2];
bool check(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) swap(a, b);
  return b.first < a.second && b.second > a.second;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<pair<int, int> > line;
    memset(st, false, sizeof st);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      line.push_back({x, y});
      st[x] = st[y] = true;
    }
    vector<int> unused;
    for (int i = 1; i <= 2 * n; i++)
      if (!st[i]) unused.push_back(i);
    for (int i = 0; i < n - m; i++)
      line.push_back({unused[i], unused[i + n - m]});
    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (check(line[i], line[j])) res++;
    cout << res << endl;
  }
}
