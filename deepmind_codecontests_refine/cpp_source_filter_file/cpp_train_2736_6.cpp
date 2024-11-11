#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s[n];
    for (long long i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<pair<long long, long long>> ans;
    for (long long i = 0; i < n; i += 2) {
      long long x = i;
      if (i == n - 1) x--;
      for (long long j = 0; j < m; j += 2) {
        long long y = j;
        if (j == m - 1) y--;
        vector<pair<long long, long long>> z, o;
        if (s[x][y] == '1')
          o.push_back({x + 1, y + 1});
        else
          z.push_back({x + 1, y + 1});
        if (s[x + 1][y] == '1')
          o.push_back({x + 2, y + 1});
        else
          z.push_back({x + 2, y + 1});
        if (s[x][y + 1] == '1')
          o.push_back({x + 1, y + 2});
        else
          z.push_back({x + 1, y + 2});
        if (s[x + 1][y + 1] == '1')
          o.push_back({x + 2, y + 2});
        else
          z.push_back({x + 2, y + 2});
        for (auto i : o) {
          s[i.first - 1][i.second - 1] = '0';
        }
        if (z.size() == 1) {
          for (auto i : o) {
            ans.push_back(i);
          }
        } else if (z.size() == 2) {
          for (auto i : z) {
            ans.push_back(i);
          }
          ans.push_back(o[0]);
          for (auto i : z) {
            ans.push_back(i);
          }
          ans.push_back(o[1]);
        } else if (z.size() == 3) {
          for (auto i : o) {
            ans.push_back(i);
          }
          ans.push_back(z[0]);
          ans.push_back(z[1]);
          ans.push_back(z[2]);
          ans.push_back(o[0]);
          ans.push_back(z[1]);
          ans.push_back(z[2]);
          ans.push_back(o[0]);
          ans.push_back(z[0]);
        } else if (z.size() == 0) {
          ans.push_back(o[0]);
          ans.push_back(o[1]);
          ans.push_back(o[2]);
          ans.push_back(o[3]);
          ans.push_back(o[0]);
          ans.push_back(o[1]);
          ans.push_back(o[0]);
          ans.push_back(o[2]);
          ans.push_back(o[3]);
          ans.push_back(o[0]);
          ans.push_back(o[1]);
          ans.push_back(o[2]);
        }
      }
    }
    cout << ans.size() / 3 << '\n';
    long long c = 0;
    for (auto i : ans) {
      cout << i.first << " " << i.second << " ";
      c++;
      c %= 3;
      if (c == 0) cout << '\n';
    }
  }
  return 0;
}
