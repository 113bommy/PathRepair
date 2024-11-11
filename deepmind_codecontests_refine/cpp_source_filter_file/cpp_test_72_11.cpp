#include <bits/stdc++.h>
using namespace std;
inline long long query(int x, int y) {
  cout << "? " << x << " " << y << endl;
  long long ans;
  cin >> ans;
  if (ans == -1) exit(0);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  if (1) freopen("data.in", "r", stdin);
  long long base = query(1, 1);
  long long min_dis;
  const long long bound = 1e9;
  long long l = 1, r = bound;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    long long ans = query(mid, 1);
    if ((base - ans) == (mid - 1)) {
      l = mid;
      min_dis = ans;
    } else {
      r = mid;
    }
  }
  long long right_down = query(bound, 1);
  long long right_up = query(bound, bound);
  long long x1, y1, x2, y2;
  y1 = min_dis + 1;
  x1 = base - min_dis + 1;
  x2 = bound - (right_down - min_dis);
  y2 = bound - (right_up - (bound - x2));
  cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
