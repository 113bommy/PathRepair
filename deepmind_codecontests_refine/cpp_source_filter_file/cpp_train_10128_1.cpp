#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int n, m, a[103][103];
char s[103][103];
vector<int> ans;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      for (int j = 0; j < m; j++) {
        a[i][j] = 0;
        if (s[i][j] == '1') a[i][j] = 1;
      }
    }
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1) {
          if (j != m - 1) {
            a[i][j] ^= 1, a[i + 1][j] ^= 1, a[i + 1][j + 1] ^= 1;
            ans.push_back(i), ans.push_back(j);
            ans.push_back(i + 1), ans.push_back(j);
            ans.push_back(i + 1), ans.push_back(j + 1);
          } else {
            a[i][j] ^= 1, a[i + 1][j] ^= 1, a[i + 1][j - 1] ^= 1;
            ans.push_back(i), ans.push_back(j);
            ans.push_back(i + 1), ans.push_back(j);
            ans.push_back(i + 1), ans.push_back(j - 1);
          }
        }
      }
    }
    for (int i = 0; i < m - 2; i++) {
      for (int j = n - 2; j < n; j++) {
        if (a[j][i] == 1) {
          if (j != n - 1) {
            a[j][i] ^= 1, a[j][i + 1] ^= 1, a[j + 1][i + 1] ^= 1;
            ans.push_back(j), ans.push_back(i);
            ans.push_back(j), ans.push_back(i + 1);
            ans.push_back(j + 1), ans.push_back(i + 1);
          } else {
            a[j][i] ^= 1, a[j][i + 1] ^= 1, a[j - 1][i + 1] ^= 1;
            ans.push_back(j), ans.push_back(i);
            ans.push_back(j), ans.push_back(i + 1);
            ans.push_back(j - 1), ans.push_back(i + 1);
          }
        }
      }
    }
    vector<pair<int, int> > on, ze;
    for (int i = n - 1; i >= n - 2; i--) {
      for (int j = m - 1; j >= m - 2; j--) {
        if (a[i][j] == 1) on.push_back({i, j});
        if (a[i][j] == 0) ze.push_back({i, j});
      }
    }
    while (on.size()) {
      if (on.size() == 1) {
        for (int z = 0; z < 1; z++) {
          ans.push_back(on[z].first);
          ans.push_back(on[z].second);
          ze.insert(ze.begin(), on[z]);
          on.erase(on.begin());
        }
        for (int z = 2; z >= 1; z--) {
          ans.push_back(ze[z].first);
          ans.push_back(ze[z].second);
          on.push_back(ze[z]);
          ze.pop_back();
        }
      }
      if (on.size() == 2) {
        for (int z = 0; z < 1; z++) {
          ans.push_back(on[z].first);
          ans.push_back(on[z].second);
          ze.insert(ze.begin(), on[z]);
          on.erase(on.begin());
        }
        for (int z = 1; z >= 0; z--) {
          ans.push_back(ze[z].first);
          ans.push_back(ze[z].second);
          on.push_back(ze[z]);
          ze.pop_back();
        }
      }
      if (on.size() == 3) {
        for (int z = 0; z < on.size(); z++) {
          ans.push_back(on[z].first);
          ans.push_back(on[z].second);
        }
        ze.clear(), on.clear();
      }
      if (on.size() == 4) {
        for (int z = 3; z >= 1; z--) {
          ans.push_back(on[z].first);
          ans.push_back(on[z].second);
          ze.push_back(on[z]);
          on.pop_back();
        }
      }
    }
    cout << ans.size() / 6 << endl;
    for (int i = 0; i < ans.size(); i += 6) {
      for (int j = i; j < i + 6; j++) cout << ans[j] + 1 << ' ';
      cout << endl;
    }
  }
}
