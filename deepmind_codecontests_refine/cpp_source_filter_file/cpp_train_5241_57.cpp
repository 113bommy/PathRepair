#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
template <typename X>
inline X abs(const X& a) {
  return a < 0 ? -a : a;
}
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
const int INF = int(1e9);
const long long INF64 = long long(1e18);
const long double EPS = 1e-9, PI = 3.1415926535897932384626433832795;
const int N = 2000 + 3;
int n;
int a[N][N];
inline bool read() {
  if (scanf("%d", &n) != 1) return false;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(n); j++) assert(scanf("%d", &a[i][j]) == 1);
  return true;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<pair<long double, long double> > border;
int used[N][N];
void dfs(int first, int second) {
  bool is = false;
  used[first][second] = true;
  for (int i = 0; i < int(8); i++) {
    int xx = first + dx[i], yy = second + dy[i];
    if (!(0 <= (xx) && (xx) < (n) && 0 <= (yy) && (yy) < (n)) ||
        a[xx][yy] == 0) {
      is = true;
      continue;
    }
    if (used[xx][yy]) continue;
    dfs(xx, yy);
  }
  if (is) border.push_back(make_pair((first), (second)));
}
inline long double dist(const pair<long double, long double>& a,
                        const pair<long double, long double>& b) {
  return sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}
inline bool checkCircle() {
  long double first = 0.0, second = 0.0;
  for (int i = 0; i < int(int((border).size())); i++) {
    first += border[i].first;
    second += border[i].second;
  }
  first /= int((border).size());
  second /= int((border).size());
  long double d = dist(make_pair((first), (second)), border[0]);
  for (int i = 0; i < int(int((border).size())); i++) {
    long double v = abs(d - dist(make_pair((first), (second)), border[i]));
    if (v > 3) return false;
  }
  return true;
}
inline void solve() {
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < int(n); i++)
    for (int j = 0; j < int(n); j++)
      if (a[i][j] != 0 && !used[i][j]) {
        border.clear();
        dfs(i, j);
        if (checkCircle())
          ans1++;
        else
          ans2++;
      }
  cout << ans1 << ' ' << ans2 << endl;
}
int main() {
  assert(read());
  solve();
  return 0;
}
