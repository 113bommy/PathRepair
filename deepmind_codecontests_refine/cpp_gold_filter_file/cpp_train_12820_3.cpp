#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n, q;
string s;
string t[3];
int p[26][100005];
int dp[255][255][255];
void init() {
  for (int j = 0; j < 26; ++j) {
    p[j][n] = p[j][n + 1] = n;
  }
  for (int i = n - 1; i >= 0; --i) {
    int ix = s[i] - 'a';
    for (int j = 0; j < 26; ++j) {
      p[j][i] = p[j][i + 1];
    }
    p[ix][i] = i;
  }
}
void upd(int i, int j, int k) {
  int &x = dp[i][j][k];
  x = n;
  if (i != 0) {
    x = min(x, p[t[0][i - 1] - 'a'][dp[i - 1][j][k] + 1]);
  }
  if (j != 0) {
    x = min(x, p[t[1][j - 1] - 'a'][dp[i][j - 1][k] + 1]);
  }
  if (k != 0) {
    x = min(x, p[t[2][k - 1] - 'a'][dp[i][j][k - 1] + 1]);
  }
}
bool check() {
  return dp[(int)t[0].size()][(int)t[1].size()][(int)t[2].size()] < n;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  cin >> s;
  init();
  dp[0][0][0] = -1;
  int i;
  char type, c;
  while (q--) {
    cin >> type >> i;
    --i;
    if (type == '-') {
      t[i].pop_back();
    } else {
      cin >> c;
      t[i] += c;
      int mx0 = (int)(t[0].size()), mx1 = (int)(t[1].size()),
          mx2 = (int)(t[2].size());
      int mn0 = (i == 0 ? mx0 : 0), mn1 = (i == 1 ? mx1 : 0),
          mn2 = (i == 2 ? mx2 : 0);
      for (int i = mn0; i <= mx0; ++i) {
        for (int j = mn1; j <= mx1; ++j) {
          for (int k = mn2; k <= mx2; ++k) {
            upd(i, j, k);
          }
        }
      }
    }
    cout << (check() ? "YES" : "NO") << endl;
  }
  return 0;
}
