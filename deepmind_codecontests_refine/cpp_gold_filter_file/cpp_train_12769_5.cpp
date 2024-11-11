#include <bits/stdc++.h>
using namespace std;
struct pt {
  long long x, y;
  pt operator-(pt a) { return {x - a.x, y - a.y}; }
  void read() { cin >> x >> y; }
};
long long cross(pt a, pt b) { return a.x * b.y - b.x * a.y; }
vector<pt> v;
bool sol(pt a, pt b) {
  vector<pt> vv;
  for (auto u : v) {
    if (cross(b - a, u - a) != 0) {
      vv.push_back(u);
    }
  }
  if (vv.size() < 3) {
    return true;
  }
  pt c = vv[0], d = vv[1];
  for (auto u : vv) {
    if (cross(d - c, u - c) != 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    pt a;
    a.read();
    v.push_back(a);
  }
  if (n < 5) {
    cout << "YES" << endl;
    return 0;
  }
  int ind = -1;
  for (int i = 2; i < v.size(); i++) {
    if (cross(v[i] - v[i - 1], v[i] - v[i - 2]) != 0) {
      ind = i;
      break;
    }
  }
  if (ind == -1) {
    cout << "YES\n";
    return 0;
  }
  bool is = false;
  is |= sol(v[ind], v[ind - 1]);
  is |= sol(v[ind - 1], v[ind - 2]);
  is |= sol(v[ind], v[ind - 2]);
  if (is) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
