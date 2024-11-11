#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, v;
  cin >> n >> m >> v;
  --v;
  long long sum = ((n - 1) * (n - 2)) / 2;
  if (m < n - 1 || m > sum + 1) {
    cout << -1;
    return 0;
  }
  vector<pair<int, int>> vec;
  vec.push_back({0, 1});
  m--;
  for (int i = 1; m && i < n; i++) {
    for (int j = i + 1; m && j < n; j++) {
      --m;
      vec.push_back({i, j});
    }
  }
  for (pair<int, int> x : vec) {
    int a = x.first;
    if (a == v)
      a = 1;
    else if (a == 1)
      a = v;
    int b = x.second;
    if (b == v)
      b = 1;
    else if (b == 1)
      b = v;
    cout << a + 1 << " " << b + 1 << "\n";
  }
  return 0;
}
