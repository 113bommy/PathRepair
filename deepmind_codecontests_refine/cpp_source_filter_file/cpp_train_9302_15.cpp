#include <bits/stdc++.h>
using namespace std;
int n, l;
struct Z {
  int f, s;
  Z() {}
  Z(int a, int b) {
    f = a;
    s = b;
  }
};
Z solve(int modify) {
  int i, j;
  for (i = 1; i < n * l + 1; i++) {
    for (j = 1; j < n + 1; j++) {
      if (j - i == modify) return Z(j, i);
    }
  }
  for (i = -1; i >= (-n * l); i--) {
    for (j = 1; j < n + 1; j++) {
      if (j - i == modify) return Z(j, i);
    }
  }
  for (j = 1; j < n + 1; j++) {
    if (j - 0 == modify) return Z(j, i);
  }
  return Z(0, 0);
}
int main() {
  int i, j, k;
  int d;
  cin >> l >> d >> n;
  int val = d;
  vector<int> res;
  for (i = 1; i < l; i++) {
    Z tmp = solve(val);
    res.push_back(tmp.f);
    val = tmp.s;
    if (val == 0 && tmp.f == 0) {
      cout << -11 << endl;
      return 0;
    }
  }
  if (val <= 0 || val > n) {
    cout << val << endl;
    return 0;
  }
  res.push_back(val);
  cout << res[0];
  for (i = 1; i < res.size(); i++) cout << " " << res[i];
  return 0;
}
