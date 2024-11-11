#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] += i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    a[i] -= i;
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] > a[i + 1]) {
      cout << ":(\n";
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
}
void init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
int main() {
  init();
  solve();
  return 0;
}
