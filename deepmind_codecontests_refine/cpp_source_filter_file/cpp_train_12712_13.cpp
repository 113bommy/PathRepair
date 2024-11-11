#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
template <typename T>
string ts(T v) {
  string res = "{";
  bool r = true;
  for (const auto &x : v) {
    if (!r) res += ",";
    r = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void solve() {
  int n;
  cin >> n;
  int arr[n], best = 0;
  for (int i = 0; i < int(n); i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j <= i; j++) {
      int t = i - j + 1;
      s += arr[j];
      if (100 * t <= s) best = max(best, i - j + 1);
    }
  }
  cout << best << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
