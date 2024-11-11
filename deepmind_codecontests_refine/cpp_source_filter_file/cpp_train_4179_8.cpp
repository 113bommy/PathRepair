#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string s, d = "hard";
long long int n, a[N];
map<char, int> mskk;
long long int dp[N][32];
long long int calc(int i, int msk) {
  if (i == n) {
    if (msk == 15)
      return 1e10;
    else
      return 0;
  }
  long long int &ret = dp[i][msk];
  if (ret != -1) return ret;
  if (s[i] == 'h') {
    if (msk == 0)
      return ret = min(calc(i + 1, 1), a[i] + calc(i + 1, msk));
    else
      return ret = min(calc(i + 1, msk), a[i] + calc(i + 1, msk));
  }
  for (int j = 1; j < d.size(); j++) {
    if (s[i] == d[j]) {
      int ww = mskk[d[j]] - 1;
      int zz = msk - ww;
      if (zz >= 0)
        return ret =
                   min(calc(i + 1, msk | mskk[d[j]]), a[i] + calc(i + 1, msk));
      else
        return ret = min(calc(i + 1, msk), a[i] + calc(i + 1, msk));
    }
  }
  return ret = calc(i + 1, msk);
}
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cc = 1;
  for (int i = 0; i < d.size(); i++) {
    mskk[d[i]] = cc;
    cc *= 2;
  }
  memset(dp, -1, sizeof dp);
  cout << calc(0, 0) << endl;
  return 0;
}
