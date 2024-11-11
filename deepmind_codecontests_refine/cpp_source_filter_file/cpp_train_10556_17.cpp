#include <bits/stdc++.h>
using namespace std;
template <typename t>
t ceil(t a, t b) {
  return a / b + (a % b == 0 ? 0 : 1);
}
bool comp(pair<int, int> p1, pair<int, int> p2) {
  if (p2.second > p1.second) {
    return 1;
  }
  return 0;
}
int bs(int l, int r, int val, vector<int> &arr) {
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == val) {
      return m;
    } else if (arr[m] > val) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t{1};
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0) {
      cout << 0 << " " << x + y << " " << x + y << " " << 0 << "\n";
    } else if (x > 0 && y < 0) {
      cout << 0 << " " << x - y << " " << -x + y << " " << 0 << "\n";
    } else if (x < 0 && y > 0) {
      cout << x - y << " " << 0 << " " << 0 << " " << -x + y << "\n";
    } else if (x < 0 && y < 0) {
      cout << x + y << " " << 0 << " " << 0 << " " << x + y << "\n";
    }
  }
  return 0;
}
