#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 5;
vector<int> v;
long long A[MAX];
int y = 1;
double f(int x) {
  double s;
  if (x < y - 1) {
    s = A[x] + v[y - 1];
    s /= (x + 1);
  } else {
    s = A[x];
    s /= x;
  }
  return s;
}
double ternary() {
  double mx = v[y - 1];
  int l = 1, r = y - 1, mid1, mid2;
  double mn = v[y - 1];
  for (int i = 0; i < 50; ++i) {
    mid1 = (2 * l + r) / 3;
    mid2 = (l + 2 * r) / 3;
    if (f(mid1) < f(mid2))
      r = mid2;
    else
      l = mid1;
  }
  mn = f(mid2);
  return mx - mn;
}
int main() {
  int q, c, x;
  double ans;
  cin >> q;
  v.push_back(0);
  for (int i = 0; i < q; ++i) {
    cin >> c;
    if (c == 1) {
      cin >> x;
      v.push_back(x);
      A[y] = A[y - 1] + x;
      y++;
    } else {
      ans = ternary();
      cout << setprecision(9) << ans << endl;
    }
  }
  return 0;
}
