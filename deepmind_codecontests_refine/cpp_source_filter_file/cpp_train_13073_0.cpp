#include <bits/stdc++.h>
using namespace std;
map<int, map<int, int> > a;
int b[102];
int main() {
  int n;
  cin >> n;
  int ans = 0, ans1 = 0;
  string s1, s2;
  cin >> s1 >> s2;
  set<pair<int, int> > s;
  for (int i = 0; i < s1.size(); i++) {
    s.insert(make_pair(-(s1[i] - '0'), i));
    b[s2[i] - '0']++;
  }
  for (int i = 9; i >= 1; i--) {
    for (int j = 1; j <= b[i]; j++) {
      while (!s.empty()) {
        if (-s.begin()->first < i) {
          s.erase(s.begin());
          ans++;
          break;
        } else {
          s.erase(s.begin());
        }
      }
    }
  }
  s.clear();
  for (int i = 0; i < n; i++) s.insert(make_pair(-(s1[i] - '0'), i));
  for (int i = 9; i >= 1; i--) {
    for (int j = 1; j <= b[i]; j++) {
      while (!s.empty()) {
        if (-s.begin()->first <= i) {
          s.erase(s.begin());
          ans1++;
          break;
        } else {
          s.erase(s.begin());
        }
      }
    }
  }
  cout << n - ans1 << '\n';
  cout << ans << '\n';
}
