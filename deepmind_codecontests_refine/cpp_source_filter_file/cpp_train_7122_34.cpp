#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
const int N = 1e2 + 5;
int given[N], recieved[N];
int main() {
  cin >> n >> m;
  if (m == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    given[x] += z;
    recieved[y] += z;
  }
  long long sum = 0;
  for (int i = 1; i < n; i++) {
    if (given[i] > recieved[i]) {
      sum += abs(recieved[i] - given[i]);
    }
  }
  cout << sum;
  return 0;
}
