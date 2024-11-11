#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> v1(n);
  vector<int> v2(m);
  int min = INT_MAX, max = -1;
  for (int i = 0; i < n; i++) {
    cin >> v1[i];
    if (v1[i] < min) min = v1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> v2[i];
    if (v2[i] > max) max = v2[i];
  }
  if (min > max) {
    cout << r;
    return 0;
  }
  int s;
  s = r / min;
  r = r % min;
  r += max * s;
  cout << r;
}
