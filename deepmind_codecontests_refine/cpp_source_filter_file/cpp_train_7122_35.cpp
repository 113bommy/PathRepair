#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int count = 0;
  vector<int> v(100, 0);
  int sum = 0;
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    v[x] -= z;
    v[y] += z;
  }
  for (int i = 0; i < n; i++) {
    if (v[i] >= 0) sum += v[i];
  }
  cout << sum;
}
