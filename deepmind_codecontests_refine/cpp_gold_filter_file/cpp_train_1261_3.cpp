#include <bits/stdc++.h>
using namespace std;
long long Set(long long N, long long pos) { return N = N | (1 << pos); }
long long reset(long long N, long long pos) { return N = N & ~(1 << pos); }
bool check(long long N, long long pos) { return (bool)(N & (1 << pos)); }
void CI(long long &_x) { scanf("%d", &_x); }
void CO(long long &_x) { cout << _x; }
template <typename T>
void getarray(T a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void prLLIarray(T a[], long long n) {
  for (long long i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const long long INF = 0x7f7f7f7f;
long long dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
long long dr4[4] = {0, 0, 1, -1};
long long dc4[4] = {-1, 1, 0, 0};
long long kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
char grid[1005][1005];
vector<pair<char, int> > MV;
int dp_left[1005][1005];
int dp_right[1005][1005];
int dp_up[1005][1005];
int dp_down[1005][1005];
void calc_left(int r, int c) {
  for (int i = 0; i < r; i++)
    for (int j = 1; j < c; j++)
      if (grid[i][j] == '#')
        dp_left[i][j] = 0;
      else
        dp_left[i][j] = 1 + dp_left[i][j - 1];
}
void calc_right(int r, int c) {
  for (int i = 0; i < r; i++)
    for (int j = c - 1; j >= 0; j--)
      if (grid[i][j] == '#')
        dp_right[i][j] = 0;
      else
        dp_right[i][j] = 1 + dp_right[i][j + 1];
}
void calc_upper(int r, int c) {
  for (int i = 1; i < r; i++)
    for (int j = 0; j < c; j++)
      if (grid[i][j] == '#')
        dp_up[i][j] = 0;
      else
        dp_up[i][j] += 1 + dp_up[i - 1][j];
}
void calc_down(int r, int c) {
  for (int i = r - 1; i >= 1; i--)
    for (int j = 0; j < c; j++)
      if (grid[i][j] == '#')
        dp_down[i][j] = 0;
      else
        dp_down[i][j] += 1 + dp_down[i + 1][j];
}
bool dfs(int r, int c, int m) {
  if (m == MV.size()) return 1;
  bool ans = 0;
  int len = MV[m].second;
  if (MV[m].first == 'N') {
    if (dp_up[r][c] > len) ans |= dfs(r - len, c, m + 1);
  } else if (MV[m].first == 'S') {
    if (dp_down[r][c] > len) ans |= dfs(r + len, c, m + 1);
  } else if (MV[m].first == 'E') {
    if (dp_right[r][c] > len) ans |= dfs(r, c + len, m + 1);
  } else if (MV[m].first == 'W') {
    if (dp_left[r][c] > len) ans |= dfs(r, c - len, m + 1);
  }
  return ans;
}
int main() {
  int row, col;
  cin >> row >> col;
  for (long long i = 0; i < row; i++)
    for (long long j = 0; j < col; j++) cin >> grid[i][j];
  calc_left(row, col);
  calc_right(row, col);
  calc_upper(row, col);
  calc_down(row, col);
  int m;
  cin >> m;
  while (m--) {
    char dir;
    int val;
    cin >> dir >> val;
    MV.push_back(make_pair(dir, val));
  }
  string res = "";
  for (long long i = 0; i < row; i++)
    for (long long j = 0; j < col; j++)
      if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
        bool temp = dfs(i, j, 0);
        if (temp) res = res + grid[i][j];
      }
  sort(res.begin(), res.end());
  if (res.size() == 0) {
    puts("no solution");
  } else
    cout << res << "\n";
  puts("");
}
