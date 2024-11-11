#include <bits/stdc++.h>
using namespace std;
vector<long long int> a[1000000];
long long int dp[1000000];
long long int xxxx = 0;
void dfs(long long int x, long long int y) {
  if (dp[x]) {
    xxxx = 0;
    return;
  }
  dp[x] = 1;
  for (auto dd : a[x]) {
    if (dd != y) {
      dfs(dd, x);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int test, h, p, i, j, xy, flag = 0, n, u, count, d, o1 = 0, o2 = 0,
                                      s, e, l, r, x, y, m, z, max1, x1, y1, k,
                                      x2, y2, z1, z2, sum, min1;
  string a;
  cin >> a;
  n = a.size();
  for (i = 0; i < n - i - 1; i++) {
    if (a[i] != a[n - i - 1]) {
      string xx2, xx3;
      xx2 = xx3 = a;
      xx2.insert(xx2.begin() + i, a[n - i - 1]);
      xx3.insert(xx3.begin() + (n - i), a[i]);
      flag = 0;
      for (j = 0; j < xx3.size() - j - 1; j++) {
        if (xx3[j] != xx3[xx3.size() - j - 1]) {
          flag = 1;
        }
      }
      if (flag == 0) {
        cout << xx3 << "\n";
        return 0;
      }
      flag = 0;
      for (j = 0; j < xx2.size() - j - 1; j++) {
        if (xx2[j] != xx2[xx2.size() - j - 1]) {
          flag = 1;
        }
      }
      if (flag == 0) {
        cout << xx2 << "\n";
        return 0;
      }
      cout << "NA";
      return 0;
    }
  }
  a.insert(a.begin() + (a.size() / 2), a[((a.size() + 1) / 2) - 1]);
  cout << a << "\n";
  return 0;
}
