#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};
const int mod = (int)1e9 + 7;
const double pi = acos(-1);
const int N = 1e6 + 2;
unordered_map<int, int> g;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, o = 0, z = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i])
      o++;
    else
      z++;
  }
  if (n == 1 && a[0] == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 1 && a[0] == 0) {
    cout << 1 << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int one = 0, zero = 0;
      for (int k = i; k < j; ++k) {
        if (a[k])
          one++;
        else
          zero++;
      }
      ans = max(ans, (o - one) + zero);
    }
  }
  cout << ans << endl;
  return 0;
}
