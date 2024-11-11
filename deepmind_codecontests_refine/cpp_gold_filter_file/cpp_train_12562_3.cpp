#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 5;
const double eps = 1e-7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  int n, k;
  cin >> n >> k;
  vector<vector<int>> f(4, vector<int>(n));
  for (long long i = 0; i < (long long)4; i++) {
    for (long long j = 0; j < (long long)n; j++) {
      cin >> f[i][j];
    }
  }
  if (k == 2 * n) {
    int c = 0;
    for (long long i = 0; i < (long long)n; i++) {
      c += f[1][i] != f[0][i];
      c += f[2][i] != f[3][i];
    }
    if (c == k) {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<pair<int, pair<int, int>>> ans;
  while (k) {
    pair<int, int> pos;
    for (long long i = 0; i < (long long)n; i++) {
      if (f[1][i] != 0 && f[1][i] == f[0][i]) {
        k--;
        ans.push_back(make_pair(f[1][i], make_pair(0, i)));
        f[1][i] = 0;
      }
      if (f[2][i] != 0 && f[2][i] == f[3][i]) {
        k--;
        ans.push_back(make_pair(f[2][i], make_pair(3, i)));
        f[2][i] = 0;
      }
      if (f[1][i] == 0) {
        pos.first = 1;
        pos.second = i;
      }
      if (f[2][i] == 0) {
        pos.first = 2;
        pos.second = i;
      }
    }
    int st = pos.second;
    if (pos.first == 2) {
      while (pos.second < n - 1) {
        if (f[2][pos.second + 1] != 0) {
          f[2][pos.second] = f[2][pos.second + 1];
          f[2][pos.second + 1] = 0;
          ans.push_back(make_pair(f[2][pos.second], make_pair(2, pos.second)));
        }
        pos.second++;
      }
      if (f[1][pos.second] != 0) {
        f[2][pos.second] = f[1][pos.second];
        f[1][pos.second] = 0;
        ans.push_back(make_pair(f[2][pos.second], make_pair(2, pos.second)));
      }
      pos.first = 1;
      while (pos.second > 0) {
        if (f[1][pos.second - 1] != 0) {
          f[1][pos.second] = f[1][pos.second - 1];
          f[1][pos.second - 1] = 0;
          ans.push_back(make_pair(f[1][pos.second], make_pair(1, pos.second)));
        }
        pos.second--;
      }
      if (st > 0 && f[2][pos.second] != 0) {
        f[1][pos.second] = f[2][pos.second];
        f[2][pos.second] = 0;
        ans.push_back(make_pair(f[1][pos.second], make_pair(1, pos.second)));
      }
      pos.first = 2;
      while (pos.second < st - 1) {
        if (f[2][pos.second + 1] != 0) {
          f[2][pos.second] = f[2][pos.second + 1];
          f[2][pos.second + 1] = 0;
          ans.push_back(make_pair(f[2][pos.second], make_pair(2, pos.second)));
        }
        pos.second++;
      }
    } else {
      while (pos.second > 0) {
        if (f[1][pos.second - 1] != 0) {
          f[1][pos.second] = f[1][pos.second - 1];
          f[1][pos.second - 1] = 0;
          ans.push_back(make_pair(f[1][pos.second], make_pair(1, pos.second)));
        }
        pos.second--;
      }
      if (f[2][pos.second] != 0) {
        f[1][pos.second] = f[2][pos.second];
        f[2][pos.second] = 0;
        ans.push_back(make_pair(f[1][pos.second], make_pair(1, pos.second)));
      }
      pos.first = 2;
      while (pos.second < n - 1) {
        if (f[2][pos.second + 1] != 0) {
          f[2][pos.second] = f[2][pos.second + 1];
          f[2][pos.second + 1] = 0;
          ans.push_back(make_pair(f[2][pos.second], make_pair(2, pos.second)));
        }
        pos.second++;
      }
      if (st < n - 1 && f[1][pos.second] != 0) {
        f[2][pos.second] = f[1][pos.second];
        f[1][pos.second] = 0;
        ans.push_back(make_pair(f[2][pos.second], make_pair(2, pos.second)));
      }
      pos.first = 1;
      while (pos.second > st + 1) {
        if (f[1][pos.second - 1] != 0) {
          f[1][pos.second] = f[1][pos.second - 1];
          f[1][pos.second - 1] = 0;
          ans.push_back(make_pair(f[1][pos.second], make_pair(1, pos.second)));
        }
        pos.second--;
      }
    }
  }
  assert(ans.size() <= 20000);
  cout << ans.size() << endl;
  for (long long i = 0; i < (long long)ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second.first + 1 << " "
         << ans[i].second.second + 1 << endl;
  }
}
