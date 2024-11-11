#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int t1[100005] = {};
  for (int i = 1; i <= n; i++) {
    int c, t;
    cin >> c >> t;
    t1[i] = t1[i - 1] + c * t;
  }
  int i0 = 0;
  for (int i = 0; i < m; i++) {
    int v;
    cin >> v;
    while (t1[i0] < v && i0 < n) i0++;
    cout << i0 << endl;
  }
  return 0;
}
