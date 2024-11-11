#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    b.push_back({n - a[i] - a[(i + 1) % n], i});
  }
  sort(b.begin(), b.end());
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    c[b[i].second] = n - i - 1;
  }
  for (auto x : c) {
    cout << x << " ";
  }
  return 0;
}
