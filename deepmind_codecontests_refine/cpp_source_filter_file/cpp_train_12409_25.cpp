#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 100005;
const int M = 1000005;
bool distinct(int x) {
  bool visited[10] = {false};
  while (x) {
    if (visited[x % 10]) return false;
    visited[x % 10] = true;
    x /= 10;
  }
  return true;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int l, r;
  cin >> l >> r;
  if (l >= r) {
    cout << -1 << endl;
    return 0;
  }
  int ans;
  for (int i = (int)l + 1; i < (int)r; ++i) {
    if (distinct(i)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
