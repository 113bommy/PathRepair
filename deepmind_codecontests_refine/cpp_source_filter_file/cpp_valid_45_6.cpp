#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
void maxi() {
  long long n;
  vector<int> v[2];
  cin >> n;
  v[0].clear(), v[1].clear();
  for (int i = 0, x; i < n; i++) cin >> x, v[x & 1].push_back(i);
  if (v[0].size() < v[1].size()) swap(v[0], v[1]);
  if (v[0].size() != (n + 1) / 2) {
    cout << -1 << endl;
    return;
  }
  long long ret = n * 2;
  for (int i = 0; i < 2 - (n & 1); i++) {
    long long x = 0;
    for (int j = 0; j < v[i].size(); j++) x += abs(v[i][j] - 2 * j);
    ret = min(ret, x);
  }
  cout << ret << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    maxi();
  }
  return 0;
}
