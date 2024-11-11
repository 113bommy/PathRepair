#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 305;
string s[MAX_N][MAX_N], t[MAX_N][MAX_N];
int cnt0[MAX_N], cnt1[MAX_N];
int n, m;
struct Move {
  int x_1, y_1, x_2, y_2;
  Move(int x_1_, int y_1_, int x_2_, int y_2_)
      : x_1(x_1_), y_1(y_1_), x_2(x_2_), y_2(y_2_) {}
  Move() {}
};
vector<Move> ans;
void go0(int i, int j) {
  if (i == 0 && j == 0) {
    ans.push_back(Move(0, 0, 0, m - 1));
    ans.push_back(Move(0, m - 1, 0, 0));
  }
  if (j != 0) ans.push_back(Move(0, 0, 0, j));
  if (i != 0) ans.push_back(Move(0, j, i, j));
}
void go1(int i, int j) {
  if (i == n - 1 && j == m - 1) {
    ans.push_back(Move(n - 1, m - 1, 0, m - 1));
    ans.push_back(Move(0, m - 1, n - 1, m - 1));
  }
  if (i != n - 1) ans.push_back(Move(n - 1, m - 1, i, m - 1));
  if (j != m - 1) ans.push_back(Move(i, m - 1, i, j));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; (i) < (n); ++i) {
    for (int j = 0; (j) < (m); ++j) cin >> s[i][j];
  }
  for (int i = 0; (i) < (n); ++i) {
    for (int j = 0; (j) < (m); ++j) cin >> t[i][j];
  }
  for (int i = (1); (i) < (n - 1); ++i)
    for (int j = 0; (j) < (m); ++j) {
      int len = (int)((s[i][j]).size());
      for (int g = (len)-1; (g) >= 0; --g) {
        if (s[i][j][g] == '0')
          ans.push_back(Move(i, j, 0, j)), cnt0[j]++;
        else
          ans.push_back(Move(i, j, n - 1, j)), cnt1[j]++;
      }
    }
  for (int j = 0; (j) < (m); ++j) {
    int len = (int)((s[0][j]).size());
    for (int g = (len)-1; (g) >= 0; --g)
      if (s[0][j][g] == '1')
        ans.push_back(Move(0, j, n - 1, j)), cnt1[j]++;
      else {
        if (j != 0)
          ans.push_back(Move(0, j, 0, 0)), cnt0[0]++;
        else
          ans.push_back(Move(0, 0, 0, n - 1)), cnt0[n - 1]++;
      }
  }
  for (int j = (m)-1; (j) >= 0; --j) {
    int len = (int)((s[n - 1][j]).size());
    for (int g = (len)-1; (g) >= 0; --g)
      if (s[n - 1][j][g] == '0')
        ans.push_back(Move(n - 1, j, 0, j)), cnt0[j]++;
      else {
        if (j != m - 1)
          ans.push_back(Move(n - 1, j, n - 1, m - 1)), cnt1[m - 1]++;
        else
          ans.push_back(Move(n - 1, m - 1, n - 1, 0)), cnt1[0]++;
      }
  }
  for (int i = (1); (i) < (m); ++i)
    for (int g = 0; (g) < (cnt0[i]); ++g) ans.push_back(Move(0, i, 0, 0));
  for (int i = 0; (i) < (m - 1); ++i)
    for (int g = 0; (g) < (cnt1[i]); ++g)
      ans.push_back(Move(n - 1, i, n - 1, m - 1));
  vector<pair<int, int> > v;
  for (int i = (1); (i) < (n); ++i)
    for (int j = 0; (j) < (m - 1); ++j) {
      v.push_back(make_pair(i, j));
    }
  for (int j = (1); (j) < (m - 1); ++j) v.push_back(make_pair(0, j));
  for (int i = (1); (i) < (n - 1); ++i) v.push_back(make_pair(i, m - 1));
  v.push_back(make_pair(0, 0));
  v.push_back(make_pair(n - 1, m - 1));
  v.push_back(make_pair(0, m - 1));
  for (auto np : v) {
    int x = np.first, y = np.second;
    int len = (int)((t[x][y]).size());
    for (int g = (len)-1; (g) >= 0; --g) {
      if (t[x][y][g] == '0')
        go0(x, y);
      else
        go1(x, y);
    }
  }
  printf("%d\n", (int)((ans).size()));
  for (auto mov : ans) {
    printf("%d %d %d %d\n", mov.x_1 + 1, mov.y_1 + 1, mov.x_2 + 1, mov.y_2 + 1);
  }
  return 0;
}
