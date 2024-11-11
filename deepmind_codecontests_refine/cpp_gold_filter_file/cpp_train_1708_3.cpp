#include <bits/stdc++.h>
using namespace std;
string s;
vector<bool> exist;
int m;
void input() {
  cin >> s;
  cin >> m;
}
void solve() {
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0')
      exist.push_back(false);
    else
      exist.push_back(true);
  }
  vector<vector<int>> vLastDiff(10, vector<int>(11, -1));
  stack<vector<vector<int>>> s;
  vector<vector<int>> temp(10, vector<int>(11, -1));
  for (int t = 0; t < m; ++t) {
    temp = vector<vector<int>>(10, vector<int>(11, -1));
    for (int i = 0; i < 10; ++i) {
      for (int j = 1; j <= 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          if (t != 0) {
            if (vLastDiff[i][j] == -1) continue;
            if (k + 1 <= j) continue;
            if (i == k) continue;
          }
          if (!exist[i]) continue;
          if (!exist[k]) continue;
          if (t != 0) {
            temp[k][k - j + 1] = i;
          } else {
            temp[k][k + 1] = i;
          }
        }
      }
    }
    vLastDiff = temp;
    s.push(vLastDiff);
  }
  int a;
  for (int i = 0; i < vLastDiff.size(); ++i) {
    for (int j = 0; j < vLastDiff[i].size(); ++j) {
      if (vLastDiff[i][j] != -1) {
        cout << "YES" << endl;
        stack<int> sans;
        while (!s.empty()) {
          temp = s.top();
          s.pop();
          sans.push(i);
          if (s.empty()) break;
          a = temp[i][j];
          j = i - j + 1;
          i = a;
        }
        while (!sans.empty()) {
          cout << (sans.top() + 1) << ' ';
          sans.pop();
        }
        return;
      }
    }
  }
  cout << "NO";
}
int main() {
  input();
  solve();
  return 0;
}
