#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
constexpr int MOD = 1000000007;
int main() {
  int T;
  cin >> T;
  for (int t = (0), t_end_ = (T); t < t_end_; t++) {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> map(r);
    for (int i = (0), i_end_ = (r); i < i_end_; i++) {
      cin >> map[i];
    }
    int rice = 0;
    for (int i = (0), i_end_ = (r); i < i_end_; i++) {
      for (int j = (0), j_end_ = (c); j < j_end_; j++) {
        if (map[i][j] == 'R') {
          rice++;
        }
      }
    }
    int a = rice / k;
    int b = rice % k;
    vector<int> ricelist(k, a);
    for (int i = (0), i_end_ = (b); i < i_end_; i++) {
      ricelist[i]++;
    }
    vector<vector<char>> ans(r, vector<char>(c));
    int nowk = 0;
    for (int i = (0), i_end_ = (r); i < i_end_; i++) {
      if (i % 2 == 0) {
        for (int j = (0), j_end_ = (c); j < j_end_; j++) {
          if (nowk >= 36) {
            ans[i][j] = 'a' + (nowk - 36);
          } else if (nowk >= 10) {
            ans[i][j] = 'A' + (nowk - 10);
          } else {
            ans[i][j] = '0' + nowk;
          }
          if (map[i][j] == 'R') {
            ricelist[nowk]--;
          }
          if (ricelist[nowk] == 0 && nowk != k - 1) {
            nowk++;
          }
        }
      } else {
        for (int j = (c)-1, j_begin_ = (0); j >= j_begin_; j--) {
          if (nowk >= 36) {
            ans[i][j] = 'a' + (nowk - 36);
          } else if (nowk >= 10) {
            ans[i][j] = 'A' + (nowk - 10);
          } else {
            ans[i][j] = '0' + nowk;
          }
          if (map[i][j] == 'R') {
            ricelist[nowk]--;
          }
          if (ricelist[nowk] == 0 && nowk != k - 1) {
            nowk++;
          }
        }
      }
    }
    for (int i = (0), i_end_ = (r); i < i_end_; i++) {
      for (int j = (0), j_end_ = (c); j < j_end_; j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
}
