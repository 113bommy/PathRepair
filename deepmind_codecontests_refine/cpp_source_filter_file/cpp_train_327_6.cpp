#include <bits/stdc++.h>
using namespace std;
int t;
int check(vector<int>& v) {
  int l = *min_element(v.begin(), v.end()),
      r = *max_element(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == l) {
      l = i;
      break;
    }
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i] == r) {
      r = i;
      break;
    }
  }
  return l > r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<int> X, Y;
    for (auto c : s) {
      if (c == 'W') Y.push_back(1);
      if (c == 'S') Y.push_back(-1);
      if (c == 'A') X.push_back(-1);
      if (c == 'D') X.push_back(1);
    }
    vector<int> px(X.size() + 1, 0), py(Y.size() + 1, 0), px2(X.size() + 1, 0),
        py2(Y.size() + 1, 0);
    for (int i = 1; i <= X.size(); i++)
      px[i] = px[i - 1] + X[i - 1], px2[i] = -px[i];
    for (int i = 1; i <= Y.size(); i++)
      py[i] = py[i - 1] + Y[i - 1], py2[i] = -py[i];
    int x = *max_element(px.begin(), px.end()) -
            *min_element(px.begin(), px.end()) + 1;
    int y = *max_element(py.begin(), py.end()) -
            *min_element(py.begin(), py.end()) + 1;
    long long res = x * y;
    if (x > 2 && (check(px) || check(px2))) res = min(res, 1ll * (x - 1) * y);
    if (y > 2 && (check(py) || check(py2))) res = min(res, 1ll * x * (y - 1));
    cout << res << endl;
  }
}
