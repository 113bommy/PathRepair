#include <bits/stdc++.h>
using namespace std;
const int L = 5e4 + 10;
const int N = 2600;
char s[L];
int cnt[30];
int f[N][N];
pair<int, int> pre[N][N];
int ans;
int n;
vector<char> v;
void print(char c) {
  for (int i = 0; i < 100; ++i) putchar(c);
  putchar('\n');
}
void dfs(int x, int y) {
  int nx = pre[x][y].first;
  int ny = pre[x][y].second;
  if (nx == 0 && ny == 0) {
    if (s[x] == s[y]) v.push_back(s[x]);
    return;
  }
  if (s[x] == s[y] && f[nx][ny] + 1 == f[x][y]) {
    v.push_back(s[x]);
  }
  dfs(nx, ny);
}
void printodd() {
  for (int i = v.size() - 1; i >= 0; --i) {
    putchar(v[i]);
  }
  for (int i = 1; i < v.size(); ++i) {
    putchar(v[i]);
  }
  putchar('\n');
}
void printeven() {
  for (int i = min((int)v.size() - 1, 49); i >= 0; --i) {
    putchar(v[i]);
  }
  for (int i = 0; i < min(50, (int)v.size()); ++i) {
    putchar(v[i]);
  }
  putchar('\n');
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] >= 100) {
      print('a' + i);
      return 0;
    }
  }
  assert(n < N);
  for (int j = n - 1; j >= 0; --j) {
    f[0][j] = (s[0] == s[j]);
    f[0][j] = max(f[0][j + 1], f[0][j]);
    if (f[0][j] == f[0][j + 1]) pre[0][j] = make_pair(0, j + 1);
  }
  for (int i = 0; i < n; ++i) {
    f[i][n - 1] = (s[i] == s[n - 1]);
    if (i) {
      f[i][n - 1] = max(f[i - 1][n - 1], f[i][n - 1]);
      if (f[i][n - 1] == f[i - 1][n - 1])
        pre[i][n - 1] = make_pair(i - 1, n - 1);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = n - 2; j >= i; --j) {
      f[i][j] = max(f[i][j + 1], f[i - 1][j]);
      f[i][j] = max(f[i][j], f[i - 1][j + 1] + (s[i] == s[j]));
      if (f[i][j] == f[i][j + 1]) {
        pre[i][j] = make_pair(i, j + 1);
      } else if (f[i][j] == f[i - 1][j]) {
        pre[i][j] = make_pair(i - 1, j);
      } else {
        pre[i][j] = make_pair(i - 1, j + 1);
      }
    }
  }
  int mxodd = 0, mxeven = 0;
  int whoodd = -1, whoeven = -1;
  for (int i = 0; i < n - 1; ++i) {
    mxeven = max(mxeven, f[i][i + 1]);
  }
  for (int i = 0; i < n - 1; ++i) {
    if (mxeven == f[i][i + 1]) whoeven = i;
  }
  for (int i = 0; i < n; ++i) {
    mxodd = max(mxodd, f[i][i]);
  }
  for (int i = 0; i < n; ++i) {
    if (mxodd == f[i][i]) whoodd = i;
  }
  if (mxeven * 2 >= 100) {
    dfs(mxeven, mxeven + 1);
    printeven();
  } else {
    if (mxodd * 2 - 1 > mxeven * 2) {
      dfs(whoodd, whoodd);
      printodd();
    } else {
      dfs(whoeven, whoeven + 1);
      printeven();
    }
  }
  return 0;
}
