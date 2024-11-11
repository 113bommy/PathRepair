#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long mod = 1e9 + 7;
const long long linf = 1LL << 62;
const double EPS = 1e-7;
template <class T>
void chmin(T& x, T y) {
  if (x > y) x = y;
}
template <class T>
void chmax(T& x, T y) {
  if (x < y) x = y;
}
void culc(int& a, int& b, int& c) {
  swap(b, c);
  swap(a, b);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> ans;
  for (int i = 0; i < n - 2; i++) {
    auto it = min_element(a.begin() + i, a.end()) - a.begin();
    if (i % 2 != it % 2) {
      if (it < n - 1)
        culc(a[it - 1], a[it], a[it + 1]), ans.push_back(it - 1), it++;
      else {
        culc(a[it - 2], a[it - 1], a[it]);
        culc(a[it - 2], a[it - 1], a[it]);
        ans.push_back(it - 2);
        ans.push_back(it - 2);
        it--;
      }
    }
    while (it != i) {
      culc(a[it - 2], a[it - 1], a[it]);
      ans.push_back(it - 2);
      it -= 2;
    }
  }
  bool flag = true;
  if (a[n - 1] < a[n - 2]) {
    flag = false;
    for (int i = n - 3; i >= 1; i--) {
      culc(a[i], a[i + 1], a[i + 2]);
      ans.push_back(i);
      if (a[i] <= a[i + 1]) {
        flag = true;
        break;
      }
    }
  }
  if (!flag) {
    cout << -1 << endl;
    return;
  }
  cout << ans.size() << endl;
  for (auto u : ans) cout << u + 1 << " ";
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
