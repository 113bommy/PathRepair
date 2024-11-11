#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, l, x, y;
  cin >> n >> l >> x >> y;
  std::vector<long long> v(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long long a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (binary_search(v.begin(), v.end(), v[i] + x)) a++;
    if (binary_search(v.begin(), v.end(), v[i] + y)) b++;
  }
  if (a && b) {
    cout << 0;
    return 0;
  }
  if (a) {
    cout << 1 << '\n' << y;
    return 0;
  }
  if (b) {
    cout << 1 << '\n' << x;
    return 0;
  }
  b = 0;
  for (int i = 0; i < n && (v[i] + x <= l); ++i) {
    if (binary_search(v.begin(), v.end(), v[i] + x - y) ||
        binary_search(v.begin(), v.end(), v[i] + x + y)) {
      cout << 1 << '\n' << v[i] + x;
      return 0;
    }
  }
  for (int i = n - 1; i >= 0 && (v[i] - x >= 0); --i) {
    if (binary_search(v.begin(), v.end(), v[i] - x - y) ||
        binary_search(v.begin(), v.end(), v[i] - x + y)) {
      cout << 1 << '\n' << v[i] - x;
      return 0;
    }
  }
  cout << 2 << '\n' << x << " " << y;
}
