#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int f, t, max_joy = 0;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> f >> t;
    if (t <= k) {
      max_joy = f;
    } else {
      max_joy = f - (t - k);
    }
    v.push_back(max_joy);
  }
  sort(v.begin(), v.end());
  if (n == 1) {
    cout << v.front();
  } else
    cout << v.back();
}
