#include <bits/stdc++.h>
using namespace std;
bool canTell(int way, vector<vector<int>>& mark) {
  vector<vector<int>> tmp(5, vector<int>(5, 0));
  for (int i = 0; i < 10; i++) {
    if (way & (1 << i)) {
      if (i < 5) {
        for (int j = 0; j < 5; j++) {
          tmp[i][j] = i + 1;
        }
      } else {
        for (int j = 0; j < 5; j++) {
          tmp[j][i - 5] = tmp[j][i - 5] * 10 + i - 5;
        }
      }
    }
  }
  for (int i = 0; i < 25; i++) {
    if (mark[i / 5][i % 5] == 0) continue;
    for (int j = i + 1; j < 25; j++) {
      if (mark[j / 5][j % 5] == 0) continue;
      if (tmp[i / 5][i % 5] == tmp[j / 5][j % 5]) {
        return false;
      }
    }
  }
  return true;
}
void solve(int ncase) {
  string colors = "RGBYW";
  map<char, int> c2i;
  for (int i = 0; i < 5; i++) c2i[colors[i]] = i;
  int n;
  cin >> n;
  vector<vector<int>> mark(5, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    string card;
    cin >> card;
    mark[c2i[card[0]]][card[1] - '1'] = 1;
  }
  int ans = 10;
  for (int k = 0; k < (1 << 10); k++) {
    int tmp = __builtin_popcount(k);
    if (tmp < ans && canTell(k, mark)) {
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  int ncase = 0;
  while (T--) {
    solve(++ncase);
  }
}
