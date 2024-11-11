#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const double EPS = 1e-9;
const int N = 2e5 + 9;
int n, b[303], mem[603][303][2];
vector<int> a, t;
int dp(int i, int sum, int f) {
  if (sum < 0) return 0;
  if (i == 600) {
    if (sum == 0 && f == 1) return 1;
    return 0;
  }
  int& ret = mem[i][sum][f];
  if (~ret) return ret;
  for (int j = 0; j <= 9; j++) {
    int x = 0;
    if (f == 0) {
      if (j == a[i])
        x = dp(i + 1, sum - j, 0);
      else if (j > a[i])
        x = dp(i + 1, sum - j, 1);
    } else {
      x = dp(i + 1, sum - j, 1);
    }
    if (x) {
      a[i] = j;
      return ret = 1;
    }
  }
  return ret = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= 600; i++) a.push_back(0);
  for (int i = 1; i <= n; i++) {
    memset(mem, -1, sizeof mem);
    dp(0, b[i], 0);
    int ck = 0;
    for (int i = 0; i < 600; i++) {
      if (a[i] == 0 && ck == 0) continue;
      ck = 1;
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
}
