#include <bits/stdc++.h>
using namespace std;
const int N = 20, Wf = 150;
int n, a, b, h[N], f[N][N][N];
pair<int, int> g[N][N][N];
vector<int> path;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b;
  for (int i = (0); i < (n); ++i) {
    cin >> h[i];
  }
  for (int p = (0); p < (n + 1); ++p) {
    for (int i = (0); i < (N); ++i) {
      for (int j = (0); j < (N); ++j) {
        f[p][i][j] = Wf;
      }
    }
  }
  f[0][0][0] = 0;
  for (int p = (0); p < (n - 2); ++p) {
    for (int i = (0); i < (N); ++i) {
      for (int j = (0); j < (N); ++j)
        if (f[p][i][j] != Wf) {
          for (int x = (0); x < (N); ++x) {
            if (i + x * b > h[p]) {
              int I = min(j + x * a, N - 1);
              int J = min(x * b, N - 1);
              if (f[p][i][j] + x < f[p + 1][I][J]) {
                f[p + 1][I][J] = f[p][i][j] + x;
                g[p + 1][I][J].first = i;
                g[p + 1][I][J].second = j;
              }
            }
          }
        }
    }
  }
  int res = Wf;
  pair<int, int> now;
  for (int i = (0); i < (N); ++i) {
    for (int j = (0); j < (N); ++j) {
      if (i > h[n - 2] and j > h[n - 1]) {
        if (f[n - 2][i][j] < res) {
          res = f[n - 2][i][j];
          now.first = i, now.second = j;
        }
      }
    }
  }
  for (int p = (n - 2) - 1; p >= (0); --p) {
    int &i = now.first, &j = now.second;
    int I = g[p + 1][i][j].first, J = g[p + 1][i][j].second;
    for (int x = (0); x < (f[p + 1][i][j] - f[p][I][J]); ++x) {
      path.push_back(p);
    }
    i = I, j = J;
  }
  cout << res << '\n';
  for (const int &i : path) {
    cout << i + 2 << ' ';
  }
  cout << '\n';
  return 0;
}
