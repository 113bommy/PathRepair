#include <bits/stdc++.h>
using namespace std;
const int N = 80;
const int oo = 1e9;
int n, s1, s2, s3, h[N][N][N], mh = -1;
char m[N][N];
pair<pair<int, int>, int> par[N][N][N], ans;
queue<pair<pair<int, int>, int> > q;
vector<pair<int, int> > vec;
bool lst(int r1, int r2, int r3) {
  if (r1 == 0 && r2 == 1 && r3 == 2) return true;
  if (r1 == 0 && r2 == 2 && r3 == 1) return true;
  if (r1 == 1 && r2 == 0 && r3 == 2) return true;
  if (r1 == 1 && r2 == 2 && r3 == 0) return true;
  if (r1 == 2 && r2 == 0 && r3 == 1) return true;
  if (r1 == 2 && r2 == 1 && r3 == 0) return true;
  return false;
}
void bfs(int r1, int r2, int r3) {
  h[r1][r2][r3] = 0;
  par[r1][r2][r3] = {{r1, r2}, r3};
  q.push({{r1, r2}, r3});
  while (!q.empty()) {
    pair<pair<int, int>, int> v = q.front();
    q.pop();
    int a, b, c;
    a = v.first.first;
    b = v.first.second;
    c = v.second;
    if (lst(a, b, c)) {
      ans = {{a, b}, c};
      mh = h[a][b][c];
      return;
    }
    for (int i = 0; i < n; i++) {
      if (a != i && b != i && c != i && m[a][i] == m[b][c] &&
          h[i][b][c] == -1) {
        h[i][b][c] = h[a][b][c] + 1;
        par[i][b][c] = v;
        q.push({{i, b}, c});
      }
    }
    for (int i = 0; i < n; i++) {
      if (a != i && b != i && c != i && m[b][i] == m[a][c] &&
          h[a][i][c] == -1) {
        h[a][i][c] = h[a][b][c] + 1;
        par[a][i][c] = v;
        q.push({{a, i}, c});
      }
    }
    for (int i = 0; i < n; i++) {
      if (a != i && b != i && c != i && m[c][i] == m[b][a] &&
          h[a][b][i] == -1) {
        h[a][b][i] = h[a][b][c] + 1;
        par[a][b][i] = v;
        q.push({{a, b}, i});
      }
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  memset(h, -1, sizeof h);
  cin >> n >> s1 >> s2 >> s3;
  s1--;
  s2--;
  s3--;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> m[i][j];
  bfs(s1, s2, s3);
  cout << mh << endl;
  if (mh == 1) return 0;
  for (int i = 0; i < mh; i++) {
    pair<pair<int, int>, int> k =
        par[ans.first.first][ans.first.second][ans.second];
    if (ans.first.first != k.first.first)
      vec.push_back({k.first.first, ans.first.first});
    else if (ans.first.second != k.first.second)
      vec.push_back({k.first.second, ans.first.second});
    else
      vec.push_back({k.second, ans.second});
    ans = k;
  }
  for (int i = vec.size() - 1; i >= 0; i--)
    cout << vec[i].first + 1 << " " << vec[i].second + 1 << endl;
  return 0;
}
