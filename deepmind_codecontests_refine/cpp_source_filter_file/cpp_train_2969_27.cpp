#include <bits/stdc++.h>
using namespace std;
int i, z, n, m, j, maxi = 0, start, final, mini = 100000000, first, b, a,
                   second, total = 1, c, k, d, ok;
int v[1000010], dp[1000001], f[200005];
long long int ans;
vector<int> r;
string s, t;
map<string, int> mymap;
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed;
  cin >> a;
  cin >> s >> s;
  v[1] = 52;
  v[2] = 53;
  v[3] = 52;
  v[4] = 52;
  v[5] = 53;
  v[6] = 53;
  v[1] = 53;
  for (i = 1; i <= 29; i++) dp[i] = 31;
  dp[30] = 11;
  dp[31] = 7;
  if (s[0] == 'w') {
    cout << v[a];
  } else {
    cout << dp[a];
  }
  return 0;
}
