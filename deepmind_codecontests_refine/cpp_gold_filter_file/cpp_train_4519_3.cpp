#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
long long ans, nbr;
int n, k, a[N][N];
vector<int> v;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    a[i][i] = -1;
    for (int j = i + 1; j <= n; ++j) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }
  if (k < 3) {
    for (int i = 1; i <= n; ++i) {
      long long sum = 0;
      for (int j = 1; j <= n; ++j)
        if (a[i][j] >= 0) {
          v.push_back(a[i][j]);
          sum += v.back();
        }
      int mul = int(v.size());
      if (k == 2) mul = mul * (int(v.size()) - 1) / 2;
      ans += 1LL * (k == 2 ? (int(v.size()) - 1) : 1) * sum;
      nbr += mul;
      v.clear();
    }
    ans /= nbr;
  } else {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (a[i][j] > 0) ans += a[i][j];
    ans /= n;
  }
  cout << ans << '\n';
}
