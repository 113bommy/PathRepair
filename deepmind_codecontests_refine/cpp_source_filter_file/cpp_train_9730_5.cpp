#include <bits/stdc++.h>
using namespace std;
const int ch = 1 << 20;
const int inf = 1 << 29;
const int mod = 1000000007;
const double eps = 1e-8;
int n, m;
vector<string> v;
string s;
double dp[ch];
long long bit[ch];
int c[ch], all;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  m = s.size();
  dp[0] = 1;
  all = 1 << m;
  for (int i = 0; i < all; i++) {
    int r = 0;
    for (int j = 0; j < m; j++)
      if (i & (1 << j)) r++;
    c[i] = m - r;
  }
  for (int i = 0; i < all; i++)
    for (int j = 0; j < m; j++) {
      if (!(i & (1 << j))) {
        dp[i ^ (1 << j)] += dp[i] / c[i];
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int same = 0;
      for (int k = 0; k < m; k++)
        if (v[i][k] == v[j][k]) same |= (1 << k);
      bit[same] |= (1ll << i) | (1ll << j);
    }
  for (int i = all - 1; i; i--)
    for (int j = 0; j < m; j++) {
      if (i & (1 << j)) bit[i ^ (1 << j)] |= bit[i];
    }
  double res = 0;
  for (int i = 0; i < all; i++)
    for (int j = 0; j < n; j++)
      if (bit[i] & (1ll << j)) {
        res += dp[i];
      }
  printf("%10f\n", res / n);
}
