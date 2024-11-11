#include <bits/stdc++.h>
using namespace std;
struct speed {
  int s, r, no;
};
bool operator<(speed k1, speed k2) {
  if (k1.r != k2.r) return (k1.r > k2.r);
  return (k1.s > k2.s);
}
int main() {
  int n;
  cin >> n;
  vector<speed> a;
  for (int i = 0; i < n; i++) {
    speed x;
    cin >> x.s >> x.r;
    x.no = i + 1;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  vector<speed> win;
  double key[n + 1];
  key[a[0].no] = (1 << 30);
  win.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    speed x = win[win.size() - 1];
    if (a[i].r == x.r) {
      if (a[i].s == x.s) {
        key[a[i].no] = key[x.no];
        win.push_back(a[i]);
      }
    } else {
      if (a[i].s < x.s) continue;
      key[a[i].no] =
          double(1.0 / x.s - 1.0 / a[i].s) / double(1.0 / a[i].r - 1.0 / x.r);
      while (key[a[i].no] > key[win[win.size() - 1].no] + 1e-6) {
        win.pop_back();
        speed x = win[win.size() - 1];
        key[a[i].no] =
            double(1.0 / x.s - 1.0 / a[i].s) / double(1.0 / a[i].r - 1.0 / x.r);
      }
      win.push_back(a[i]);
    }
  }
  bool v[n + 1];
  memset(v, 0, sizeof(v));
  for (int i = 0; i < win.size(); i++) {
    v[win[i].no] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (v[i]) cout << i << " ";
  }
  return 0;
}
