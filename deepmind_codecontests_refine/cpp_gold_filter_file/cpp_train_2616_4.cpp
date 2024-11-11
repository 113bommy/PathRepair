#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int x, mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mx = max(x, mx);
    if (v.empty()) {
      v.push_back(x);
      continue;
    }
    if (x > v.back()) {
      cout << "NO";
      return 0;
    }
    if (x == v.back())
      v.pop_back();
    else
      v.push_back(x);
  }
  if (v.empty()) return cout << "YES", 0;
  if (v.back() == mx) return cout << "YES", 0;
  cout << "NO";
}
