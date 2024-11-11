#include <bits/stdc++.h>
using namespace std;
long long fat[int(1e6 + 5)];
vector<int> x[int(1e6 + 5)];
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  int g, t;
  fat[0] = fat[1] = 1;
  for (int i = 2; i < int(1e6 + 5); i++) {
    fat[i] = (i * fat[i - 1]) % mod;
  }
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> g;
    for (int j = 0; j < g; j++) {
      cin >> t;
      x[t].push_back(i);
    }
  }
  sort(x, x + m + 1);
  long long size = 1, asnw = 1;
  for (int i = 2; i <= m; i++) {
    if (x[i] == x[i - 1]) {
      size++;
    } else {
      asnw = (asnw * fat[size]) % mod;
      size = 1;
    }
  }
  asnw = (asnw * fat[size]) % mod;
  cout << asnw << '\n';
  return 0;
}
