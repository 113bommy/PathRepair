#include <bits/stdc++.h>
using namespace std;
int d2x[] = {1, -1, 0, 0, 1, -1, 1, -1};
int d2y[] = {0, 0, 1, -1, 1, -1, -1, 1};
int d3x[] = {1, -1, 0, 0, 0, 0};
int d3y[] = {0, 0, 1, -1, 0, 0};
int d3z[] = {0, 0, 0, 0, 1, -1};
struct edge {
  int from, to, w;
  edge(int from, int to, int w) : from(from), to(to), w(w) {}
  bool operator<(const edge& e) const { return w > e.w; }
};
const double EPS = (1e-9);
int a, v, c, data;
bool p(int val);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> a >> v >> c;
  data = a * c;
  int low = 0, high = 1000003, mid;
  while (low < high) {
    mid = (low + high) / 2;
    if (p(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << endl;
  return 0;
}
bool p(int val) {
  int t = (data - val * v) / v + ((data - val * v) % v != 0);
  return (val * v + v * t >= data && val * v + v * t >= a * t);
}
