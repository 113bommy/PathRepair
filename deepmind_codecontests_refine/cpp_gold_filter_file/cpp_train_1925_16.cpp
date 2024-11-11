#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  vector<int> s(t), q(t);
  vector<pair<int, int> > ans;
  int k = 0;
  for (int i = 0; i < t; i++) cin >> s[i];
  for (int i = 0; i < t; i++) cin >> q[i];
  for (int i = 0; i < t; i++) {
    if (q[i] != s[i]) {
      int c;
      for (int j = i + 1; j < t; j++) {
        if (q[j] == s[i]) {
          c = j;
          break;
        }
      }
      for (int j = c; j > i; j--) {
        ans.push_back(pair<int, int>(j, j + 1));
        k++;
        swap(q[j - 1], q[j]);
      }
    }
  }
  cout << k << '\n';
  for (auto x : ans) {
    cout << x.first << " " << x.second << '\n';
  }
}
