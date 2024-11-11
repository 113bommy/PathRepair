#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
mt19937 myrand(time(0));
int main() {
  ios::sync_with_stdio(0);
  cin.tie(), cout.tie();
  long long n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  long long ax = abs(x1 - x2);
  long long ay = abs(y1 - y2);
  if (ax < ay) swap(ax, ay);
  if (ax > 4 || ay > 4)
    cout << "Second" << endl;
  else if (ax == 4 && ay >= 3)
    cout << "Second" << endl;
  else
    cout << "First" << endl;
  return 0;
}
