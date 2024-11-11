#include <bits/stdc++.h>
using namespace std;
long long int n, m, mod;
long long int dp[605][605];
long long int in[605], out[605];
long long int mat[605][605];
vector<long long int> E[605];
long long int recur(long long int pos, long long int goal) {
  if (pos == goal) return dp[pos][goal] = 1;
  long long int &res = dp[pos][goal];
  if (res != -1) return res;
  res = 0;
  for (long long int i = 0;
       i < ((long long int)(((long long int)(E[pos]).size()))); ++i)
    res = (res + recur(E[pos][i], goal)) % mod;
  return res;
}
long long int pow(long long int a, long long int p) {
  long long int res = 1;
  for (; p; p >>= 1) {
    if (p & 1) res = (a * res) % mod;
    a = (a * a) % mod;
  }
  return res;
}
long long int inv(long long int a) { return pow(a, mod - 2); }
int main() {
  memset(dp, -1, sizeof(dp));
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));
  cin >> n >> m >> mod;
  for (long long int i = 0; i < ((long long int)(m)); ++i) {
    long long int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
    in[b]++;
    out[a]++;
  }
  vector<long long int> a, b;
  for (long long int i = 0; i < ((long long int)(n)); ++i)
    if (in[i] == 0) a.push_back(i);
  for (long long int i = 0; i < ((long long int)(n)); ++i)
    if (out[i] == 0) b.push_back(i);
  for (long long int i = 0; i < ((long long int)(((long long int)(a).size())));
       ++i)
    for (long long int j = 0;
         j < ((long long int)(((long long int)(b).size()))); ++j)
      mat[i][j] = recur(a[i], b[j]);
  long long int res = 1;
  long long int n = ((long long int)(a).size());
  for (long long int i = 0; i < ((long long int)(n)); ++i) {
    long long int t = i;
    while (t < n && mat[t][i] == 0) t++;
    if (t == n) {
      res = 0;
      break;
    }
    while (i < t) {
      res *= -1;
      for (long long int j = i; j < n; j++) swap(mat[t][j], mat[t - 1][j]);
      t--;
    }
    res = (res * mat[i][i]) % mod;
    for (long long int j = i + 1; j < n; j++) {
      long long int dat = (inv(mat[i][i]) * mat[j][i]) % mod;
      for (long long int k = i + 1; k < n; k++)
        mat[j][k] = (mat[j][k] - dat * mat[i][k] % mod + mod) % mod;
    }
  }
  cout << (res + mod) % mod << endl;
}
