#include <bits/stdc++.h>
const double EPS = 0.0000001;
using namespace std;
string a[30][4];
int sz[30];
string b[30][40];
int n;
int dp[100][100];
int inv[30];
string org[4];
int is(int i, int j, int k, int z) {
  if (i == n) return 1;
  if (j == sz[z]) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = 0;
  if (a[k][i] == b[z][j]) ans = max(ans, is(i + 1, j + 1, k, z));
  ans = max(ans, is(i, j + 1, k, z));
  return dp[i][j] = ans;
}
set<pair<int, int>> st;
int idx(int i, int j) {
  for (int k = 0; k < n; k++)
    if (org[k] == a[i][j]) return k;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> org[i];
  string tmp[4];
  for (int i = 0; i < n; i++) tmp[i] = org[i];
  sort(tmp, tmp + n);
  int z = 0;
  do {
    for (int i = 0; i < n; i++) a[z][i] = tmp[i];
    z++;
  } while (next_permutation(tmp, tmp + n));
  for (int i = 0; i < z; i++) {
    int cur = 0;
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (idx(i, j) > idx(i, k)) cur++;
      }
    }
    st.insert(make_pair(cur, i));
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> sz[i];
    for (int j = 0; j < sz[i]; j++) cin >> b[i][j];
  }
  int ans = -1, bst = 10000;
  for (int j = 0; j < m; j++) {
    for (auto entry : st) {
      int i = entry.second;
      memset(dp, -1, sizeof(dp));
      if (is(0, 0, i, j)) {
        if (entry.first < bst) {
          bst = entry.first;
          ans = j;
        }
      }
    }
  }
  if (ans == -1)
    cout << "Brand new problem!" << endl;
  else {
    cout << ans << endl;
    int p = (n * (n - 1)) / 2 - bst + 1;
    cout << "[:";
    for (int i = 0; i < p; i++) cout << "|";
    cout << ":]" << endl;
  }
  int ___________;
  cin >> ___________;
  return 0;
}
