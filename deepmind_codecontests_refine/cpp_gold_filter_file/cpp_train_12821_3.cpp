#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
const int MAXN = 1013;
int N;
int x[MAXN], y[MAXN];
vector<pair<pair<int, int>, pair<int, int> > > res;
int32_t main() {
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(4);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (auto i = (0); i < (N); i++) {
    cin >> x[i];
    x[i]--;
  }
  for (auto i = (0); i < (N); i++) {
    cin >> y[i];
    y[i]--;
  }
  for (auto i = (0); i < (N); i++) {
    int vx, vy;
    for (auto j = (0); j < (N); j++) {
      if (x[j] == i) vx = j;
      if (y[j] == i) vy = j;
    }
    if (vx == i && vy == i) continue;
    res.push_back({{i, vy}, {vx, i}});
    swap(x[vx], x[i]);
    swap(y[vy], y[i]);
  }
  cout << ((int)(res).size()) << '\n';
  for (auto a : res) {
    cout << a.first.first + 1 << ' ' << a.first.second + 1 << ' '
         << a.second.first + 1 << ' ' << a.second.second + 1 << '\n';
  }
  return 0;
}
