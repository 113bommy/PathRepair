#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int t, n;
  cin >> t;
  for (int i = 1; i <= 2000; i++) {
    if (i % 3 == 0 || i % 10 == 3) {
      continue;
    } else {
      v.push_back(i);
    }
  }
  for (int n = 1; n <= t; n++) {
    cin >> n;
    cout << v[n - 1] << "\n";
  }
}
