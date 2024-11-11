#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-9;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int mod = 1000000007;
int main(int argc, char const *argv[]) {
  int n, x;
  cin >> n >> x;
  if (n == 1) {
    cout << "YES" << endl << x << endl;
    return 0;
  }
  if (n == 2 && x == 0) {
    cout << "NO" << endl;
    return 0;
  }
  vector<int> ans;
  ans.push_back(524287);
  int cnt = 0, i = 0;
  int now = 524287;
  while (cnt != n - 2) {
    if (i == x || (now ^ i) == (524287 ^ x)) {
      i++;
      continue;
    }
    ans.push_back(i);
    now ^= i;
    i++;
    cnt++;
  }
  ans.push_back(now ^ x);
  cout << "YES" << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
