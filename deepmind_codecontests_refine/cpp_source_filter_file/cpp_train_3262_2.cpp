#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, b;
  cin >> n >> b;
  vector<int> v;
  int sum = b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
    sum += x;
  }
  double k = sum / n;
  for (int i = 0; i < n; i++) {
    if (v[i] > k) return cout << -1 << '\n', 0;
  }
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(6) << k - v[i] << '\n';
  }
  return 0;
}
