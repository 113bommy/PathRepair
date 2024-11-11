#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> v(m);
  for (long long i = 0; i < m; i++) {
    cin >> v[i];
  }
  long long sum = 0, turn = 0;
  for (long long i = 0; i < m - 1; i++) {
    if (v[i + 1] < v[i]) {
      sum = v[i + 1];
      turn = turn + 1;
    } else {
      sum = v[i + 1] - 1;
    }
  }
  cout << (turn * n) + sum;
}
