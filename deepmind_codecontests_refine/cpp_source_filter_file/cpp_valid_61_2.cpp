#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N];
char ans[2] = {'B', 'R'};
vector<pair<char, int> > v;
int main() {
  int t;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> (s + 1);
    v.clear();
    v.push_back({'a', 0});
    for (int i = 1; i <= n; i++) {
      if (s[i] != '?') {
        v.push_back({s[i], i});
      }
    }
    if (v.size() == 1) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        s[i] = ans[(cnt++) % 2];
      }
    } else if (v.size() == 2) {
      int cnt = 0;
      if (v[1].first == 'B') {
        cnt = 1;
      } else
        cnt = 0;
      for (int i = v[1].second - 1; i >= 1; i--) {
        s[i] = ans[(cnt++) % 2];
      }
      if (v[1].first == 'B') {
        cnt = 1;
      } else
        cnt = 0;
      for (int i = v[1].second + 1; i <= n; i++) {
        s[i] = ans[(cnt++) % 2];
      }
    } else {
      int cnt = 0;
      for (int i = 1; i < v.size(); i++) {
        if (i != v.size() - 1) {
          if (v[i].first == 'B') {
            cnt = 1;
          } else
            cnt = 0;
          for (int j = v[i].second - 1; j > v[i - 1].second; j--) {
            s[j] = ans[(cnt++) % 2];
          }
        } else {
          if (v[i].first == 'B') {
            cnt = 1;
          } else
            cnt = 0;
          for (int j = v[i].second - 1; j > v[i - 1].second; j--) {
            s[j] = ans[(cnt++) % 2];
          }
          if (v[i].first == 'B') {
            cnt = 1;
          } else
            cnt = 0;
          for (int j = v[0].second + 1; j <= n; j++) {
            s[j] = ans[(cnt++) % 2];
          }
        }
      }
    }
    cout << (s + 1) << endl;
  }
}
