#include <bits/stdc++.h>
using namespace std;
int dcmp(double x, double y) {
  return fabs(x - y) <= 1e-9 ? 0 : x < y ? -1 : 1;
}
const int MAX = 220;
char s[MAX], t[MAX];
int n, m;
int memo[MAX][MAX][1500];
int dp(int i, int j, int cnt) {
  if (cnt > 1000 || cnt < 0) return (int)1e9 + 9;
  if (i == n && j == m) {
    return cnt;
  }
  int &ret = memo[i][j][cnt];
  if (ret != -1) return ret;
  int path1 = (int)1e9 + 9;
  int path2 = (int)1e9 + 9;
  int ni = i + (s[i] == ')');
  int nj = j + (t[j] == ')');
  path1 = 1 + dp(ni, nj, cnt - 1);
  ni = i + (s[i] == '(');
  nj = j + (t[j] == '(');
  path2 = 1 + dp(ni, nj, cnt + 1);
  return ret = min(path1, path2);
}
void get_path(int i, int j, int cnt) {
  if (i == n && j == m) {
    if (cnt > 0) {
      for (int k = 0; k < cnt; k++) {
        cout << ')';
      }
    }
    return;
  }
  int path1 = (int)1e9 + 9;
  int path2 = (int)1e9 + 9;
  int &ret = memo[i][j][cnt];
  int ni = i + (s[i] == ')');
  int nj = j + (t[j] == ')');
  path1 = 1 + dp(ni, nj, cnt - 1);
  int ni1 = i + (s[i] == '(');
  int nj1 = j + (t[j] == '(');
  path2 = 1 + dp(ni1, nj1, cnt + 1);
  if (path1 < path2) {
    cout << ')';
    get_path(ni, nj, cnt - 1);
    return;
  } else {
    cout << '(';
    get_path(ni1, nj1, cnt + 1);
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  memset(memo, -1, sizeof(memo));
  cin >> s >> t;
  n = strlen(s);
  m = strlen(t);
  int ans = dp(0, 0, 0);
  get_path(0, 0, 0);
}
