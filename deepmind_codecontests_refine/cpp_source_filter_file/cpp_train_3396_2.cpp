#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> &operator+=(vector<T> &v, T x) {
  v.push_back(x);
  return v;
}
void solve() {
  int a, b, f, k;
  cin >> a >> b >> f >> k;
  bool lr = true;
  k--;
  int c = 0;
  int bb = b;
  bb -= f;
  if (b < 0) {
    cout << -1;
    return;
  }
  while (k) {
    k--;
    if (lr) {
      if ((a - f) * 2 > bb) {
        c++;
        bb = b;
      }
      bb -= (a - f) * 2;
    } else {
      if (2 * f > bb) {
        c++;
        bb = b;
      }
      bb -= 2 * f;
    }
    lr = !lr;
    if (bb < 0) {
      cout << -1;
      return;
    }
  }
  if (lr && (a - f) > bb) {
    if (b < a - f) {
      cout << -1;
      return;
    }
    c++;
  }
  if (!lr && f > bb) {
    if (b < f) {
      cout << -1;
      return;
    }
    c++;
  }
  cout << c;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
