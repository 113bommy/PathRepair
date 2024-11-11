#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
int n, m;
vector<int> ans_r;
bool check(vector<vector<int>> &a) {
  for (int(i) = 0; (i) < ans_r.size(); (i)++) ans_r[i] = 0;
  bool one = false;
  for (int i = 0; i < m; ++i) one |= (a[0][i] == 1);
  for (int i = 1; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      sum += a[i][j];
    }
    if (sum == 0) {
      if (!one) {
      } else {
        ans_r[i] = 1;
        for (int j = 0; j < m; ++j) {
          a[i][j] ^= 1;
        }
        one = true;
      }
      continue;
    }
    if (sum == m) {
      if (one) {
      } else {
        ans_r[i] = 1;
        for (int j = 0; j < m; ++j) {
          a[i][j] ^= 1;
        }
      }
      continue;
    }
    if (one) {
      return false;
    }
    one = true;
    vector<int> tt = a[i];
    sort((tt).begin(), (tt).end());
    if (a[i] == tt) continue;
    for (int j = 0; j < m; ++j) {
      ans_r[i] = 1;
      a[i][j] ^= 1;
    }
    tt = a[i];
    sort((tt).begin(), (tt).end());
    if (a[i] == tt) continue;
    return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<int> r(n), c(m);
  for (int(i) = 0; (i) < n; (i)++) {
    for (int(j) = 0; (j) < m; (j)++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    if (a[0][i] == 0) {
      c[i] ^= 1;
      for (int j = 0; j < n; ++j) {
        a[j][i] ^= 1;
      }
    }
  }
  ans_r.resize(n);
  for (int i = 0; i < m; ++i) {
    if (a[0][i] == 1) {
      vector<int> new_c = c;
      vector<vector<int>> a2 = a;
      if (check(a2)) {
        cout << "YES" << endl;
        for (int i = 0; i < ans_r.size(); ++i) cout << ans_r[i];
        cout << endl;
        for (int i = 0; i < new_c.size(); ++i) cout << new_c[i];
        return 0;
      }
      c[i] ^= 1;
      for (int j = 0; j < n; ++j) {
        a[j][i] ^= 1;
      }
    }
    if (check(a)) {
      cout << "YES" << endl;
      for (int i = 0; i < ans_r.size(); ++i) cout << ans_r[i];
      cout << endl;
      for (int i = 0; i < c.size(); ++i) cout << c[i];
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
