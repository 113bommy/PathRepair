#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int MAXN = 2000000;
struct Point {
  int x, y;
  void Read() { cin >> x >> y; }
  Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
bool in(int x, int a, int b) { return x >= a && a <= b; }
int dst(Point p, int n) {
  int res = 0;
  if (p.x == 0) {
    if (p.y == 0) return 0;
    return 4 * n - p.y;
  }
  if (p.y == 0) {
    return p.x;
  }
  if (p.x == n) return n + p.y;
  return n + n - p.x + n;
}
long long mas[100001];
int main() {
  int n, m, k;
  pair<pair<int, int>, int> mas[100001];
  cin >> n >> m >> k;
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    mas[i] = make_pair(make_pair(a, b), c);
  }
  long long res = 0;
  int x;
  for (int i = 0; i < k; ++i) {
    cin >> x;
    for (int j = 0; j < m; ++j) {
      if (in(x, mas[j].first.first, mas[j].first.second))
        res += mas[j].second + x - mas[j].first.first;
    }
  }
  cout << res;
  return 0;
}
