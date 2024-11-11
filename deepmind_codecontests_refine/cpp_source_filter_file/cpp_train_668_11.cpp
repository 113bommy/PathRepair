#include <bits/stdc++.h>
using namespace std;
const long long INFLL = 2 * (long long)1e18 + 100;
const int INFINT = 2 * (int)1e9 + 100;
void die() {
  cout << "-1";
  exit(0);
}
const int NMAX = 100 + 5;
const int MOD = 1e9 + 7;
const double PI = atan(1) * 4;
const double EPS = 1e-12;
string s;
long long dp[2][2], noi[2][2];
vector<pair<int, int> > v;
void solve(int index, int cnt, bool parity) {
  if (parity) swap(noi[index][0], noi[index][1]);
  noi[index][0]++;
  dp[index][0] += noi[index][0];
  dp[index][1] += noi[index][1];
  for (int i = 1; i <= cnt - 1; i++) {
    int temp = noi[index][0];
    noi[index][0] = noi[index][1] + 1;
    noi[index][1] = temp;
    dp[index][0] += noi[index][0];
    dp[index][1] += noi[index][1];
  }
  0;
  0;
  0;
}
int lena, lenb;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  for (auto i : s) {
    if (i == 'a') {
      lena++;
      if (lenb) {
        0;
        v.push_back({0, lenb});
        lenb = 0;
      }
    } else {
      lenb++;
      if (lena) {
        0;
        v.push_back({1, lena});
        lena = 0;
      }
    }
  }
  if (lena) v.push_back({1, lena});
  if (lenb) v.push_back({0, lenb});
  bool par = 0;
  for (auto cur : v) {
    0;
    solve(cur.first, cur.second, par);
    if (cur.second % 2) par ^= 1;
  }
  cout << dp[0][1] + dp[1][1] << ' ' << dp[0][0] + dp[1][0];
  return 0;
}
