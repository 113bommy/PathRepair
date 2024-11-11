#include <bits/stdc++.h>
using namespace std;
int special(vector<int> v) {
  int cnt = 0;
  for (int i = 0; i < v.size(); ++i)
    if (v[i] != 0) {
      ++cnt;
      if (cnt > 1) return 2;
    }
  return cnt;
}
int isg(vector<int> v) {
  if (v.size() == 1) return true;
  if (v[0] == 0) return special(v);
  double c, b;
  c = v[0];
  b = 1.0 * v[1] / v[0];
  int cnt = 0;
  for (int i = 1; i < v.size(); ++i) {
    if (b == 0) {
      if (v[i] != 0) {
        ++cnt;
        if (cnt > 1) return 2;
      }
      continue;
    }
    if (v[i - 1] == 0) return 2;
    if (fabs(1.0 * v[i] / v[i - 1] - b) > 1e-9) {
      ++cnt;
      v[i] = v[i - 1];
      if (cnt > 1) return 2;
    }
  }
  return cnt;
}
int main() {
  int n;
  cin >> n;
  vector<int> v;
  v.resize(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  int a = isg(v);
  if (a == 0) {
    cout << 0 << endl;
    return 0;
  } else if (a == 1) {
    cout << 1 << endl;
    return 0;
  }
  vector<int> vv = v;
  vv.erase(vv.begin());
  a = isg(vv);
  if (a == 0) {
    cout << 1 << endl;
    return 0;
  }
  vv = v;
  vv.erase(vv.begin() + 1);
  a = isg(vv);
  if (a == 0) {
    cout << 1 << endl;
    return 0;
  }
  cout << 2 << endl;
  return 0;
}
