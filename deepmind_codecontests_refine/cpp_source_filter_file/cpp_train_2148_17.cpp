#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 1e6 + 10;
int main() {
  int n;
  cin >> n;
  map<int, int> mc;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mc[x] = i;
  }
  pair<int, int> ans = {n, n};
  for (auto &p : mc) {
    pair<int, int> pp = p;
    swap(pp.first, pp.second);
    ans = min(ans, pp);
  }
  cout << ans.second << endl;
  return 0;
}
