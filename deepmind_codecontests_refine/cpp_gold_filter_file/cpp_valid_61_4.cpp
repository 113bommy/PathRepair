#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> temp;
  vector<int> k;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      k.push_back(i);
    } else {
      if (k.size() != 0) {
        temp.push_back(k);
        k.clear();
      }
    }
  }
  if (k.size() != 0) {
    temp.push_back(k);
  }
  for (auto i : temp) {
    int d1 = i[0];
    int s1 = i.size();
    int d2 = i[s1 - 1];
    if (d1 == 0) {
      if (d1 == n - 1) {
        s[d1] = 'R';
      } else {
        if (s[d2 + 1] == 'R') {
          s[d2] = 'B';
          int cnt = 0;
          for (int i = d2; i >= d1; i--) {
            if (cnt % 2 == 0) {
              s[i] = 'B';
            } else {
              s[i] = 'R';
            }
            cnt++;
          }
        } else {
          s[d2] = 'R';
          int cnt = 0;
          for (int i = d2; i >= d1; i--) {
            if (cnt % 2 == 0) {
              s[i] = 'R';
            } else {
              s[i] = 'B';
            }
            cnt++;
          }
        }
      }
    } else if (d2 == n - 1) {
      if (s[d1 - 1] == 'R') {
        s[d1] = 'B';
        int cnt = 0;
        for (int i = d1; i <= d2; i++) {
          if (cnt % 2 == 0) {
            s[i] = 'B';
          } else {
            s[i] = 'R';
          }
          cnt++;
        }
      } else {
        s[d1] = 'R';
        int cnt = 0;
        for (int i = d1; i <= d2; i++) {
          if (cnt % 2 == 0) {
            s[i] = 'R';
          } else {
            s[i] = 'B';
          }
          cnt++;
        }
      }
    } else {
      if (s[d1 - 1] == 'R') {
        s[d1] = 'B';
        int cnt = 0;
        for (int i = d1; i <= d2; i++) {
          if (cnt % 2 == 0) {
            s[i] = 'B';
          } else {
            s[i] = 'R';
          }
          cnt++;
        }
      } else {
        s[d1] = 'R';
        int cnt = 0;
        for (int i = d1; i <= d2; i++) {
          if (cnt % 2 == 0) {
            s[i] = 'R';
          } else {
            s[i] = 'B';
          }
          cnt++;
        }
      }
    }
  }
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
