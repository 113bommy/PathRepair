#include <bits/stdc++.h>
using namespace std;
set<string> s;
vector<int> ind[4];
vector<string> a;
int main() {
  int t;
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    a.clear();
    s.clear();
    for (int i = 0; i < 4; i++) ind[i].clear();
    for (int i = 0; i < n; i++) {
      cin >> s1;
      s.insert(s1);
      a.push_back(s1);
      int len = s1.size();
      if (len >= 2) {
        ind[int(s1[0] - '0') * 2 + int(s1[len - 1] - '0')].push_back(i);
      } else {
        if (s1[0] == '0')
          ind[int(s1[0] - '0')].push_back(i);
        else
          ind[3].push_back(i);
      }
    }
    int n0, n1, n2, n3;
    n0 = ind[0].size();
    n1 = ind[1].size();
    n2 = ind[2].size();
    n3 = ind[3].size();
    if (n == n0 || n == n3) {
      cout << 0 << '\n' << '\n';
    } else if (n1 + n2 == 0) {
      cout << -1 << '\n';
    } else {
      if (n1 < n2) {
        int k = (n2 - n1) / 2;
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < n2; i++) {
          s1 = a[ind[2][i]];
          reverse(s1.begin(), s1.end());
          if (s.find(s1) == s.end()) {
            cnt++;
            ans.push_back(ind[2][i]);
          }
        }
        if (cnt < k) {
          cout << -1 << '\n';
        } else {
          cout << k << '\n';
          for (int i = 0; i < k; i++) {
            cout << ans[i] + 1 << " ";
          }
          cout << '\n';
        }
      } else {
        int k = max((n1 - n2) / 2, 0);
        int cnt = 0;
        vector<int> ans;
        for (int i = 0; i < n1; i++) {
          s1 = a[ind[1][i]];
          reverse(s1.begin(), s1.end());
          if (s.find(s1) == s.end()) {
            cnt++;
            ans.push_back(ind[1][i]);
          }
        }
        if (cnt < k) {
          cout << -1 << '\n';
        } else {
          cout << k << '\n';
          for (int i = 0; i < k; i++) {
            cout << ans[i] + 1 << " ";
          }
          cout << '\n';
        }
      }
    }
  }
}
