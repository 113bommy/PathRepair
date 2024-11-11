#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, q, r, s, i, j, k, l;
  cin >> p >> q;
  cin >> r >> s;
  cin >> i >> j;
  cin >> k >> l;
  if (((q > i && r > l) && (q > k && r > j)) ||
      ((p > j && s > k) && (p > l && s > i))) {
    cout << "Team 1";
    return 0;
  }
  if (((i > s && l > p) || (k > s && j > p)) ||
      ((k > q && j > r) || (i > q && l > r))) {
    cout << "Team 2";
    return 0;
  } else {
    cout << "Draw";
    return 0;
  }
}
