#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MAXN = 30005;
int lst[MAXN], N;
bool ok(vector<int> &v) {
  if ((int)v.size() <= 2) return true;
  for (int i = (int)v.size() - 2; i >= max(1, (int)v.size() - 5); i--)
    if (v[i + 1] - v[i] != v[1] - v[0]) return false;
  return true;
}
bool check(vector<int> &a, vector<int> &b, int n) {
  if ((int)a.size() < 2) {
    b.push_back(lst[n]);
    if (!ok(b)) {
      b.erase(b.end() - 1);
      a.push_back(lst[n]);
    }
  } else if ((int)b.size() < 2) {
    a.push_back(lst[n]);
    if (!ok(a)) {
      a.erase(a.end() - 1);
      b.push_back(lst[n]);
    }
  } else {
    a.push_back(lst[n]);
    if (!ok(a)) {
      a.erase(a.end() - 1);
      b.push_back(lst[n]);
    }
  }
  return ok(a) && ok(b);
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> lst[i];
  int sz = min(6, N);
  vector<int> x, y;
  for (int mask = 0; mask < (1 << sz); mask++) {
    vector<int> a, b;
    for (int i = 0; i < sz; i++) {
      if (mask & (1 << i))
        a.push_back(lst[i]);
      else
        b.push_back(lst[i]);
    }
    if (!ok(a) || !ok(b)) continue;
    bool k = true;
    for (int i = sz; i < N; i++) {
      if (!check(a, b, i)) {
        k = false;
        break;
      }
    }
    if (k) {
      x = a, y = b;
      break;
    }
  }
  if ((int)x.size() == 0 && (int)y.size() > 0) {
    x.push_back(y[(int)y.size() - 1]);
    y.erase(y.end() - 1);
  } else if ((int)y.size() == 0 && (int)x.size() > 0) {
    y.push_back(x[(int)x.size() - 1]);
    x.erase(x.end() - 1);
  }
  if ((int)x.size() == 0 && (int)y.size() == 0) {
    cout << "No solution" << endl;
    return 0;
  }
  for (int i = 0; i < (int)x.size(); i++) cout << x[i] << " ";
  cout << endl;
  for (int i = 0; i < (int)y.size(); i++) cout << y[i] << " ";
  cout << endl;
}
