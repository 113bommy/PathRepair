#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
string in;
int mat[111][111];
vector<pair<int, int> > ans;
int main() {
  memset(mat, 0, sizeof mat);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in;
    for (int j = 0; j < n; j++) {
      if (in[j] != '.') mat[i][j] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 0) {
        ans.push_back(make_pair(i, j));
        break;
      }
    }
  if (ans.size() < n) {
    ans.clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (mat[j][i] == 0) {
          ans.push_back(make_pair(j, i));
          break;
        }
  }
  if (ans.size() < n)
    cout << "-1\n";
  else
    for (int i = 0; i < n; i++)
      cout << ans[i].first << " " << ans[i].second << endl;
}
