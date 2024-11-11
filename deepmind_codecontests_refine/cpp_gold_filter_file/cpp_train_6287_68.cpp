#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const int nmax = 1700;
int px[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int py[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int n, m;
int a[nmax][nmax];
vector<pair<int, int> > now;
int dfs(int x, int y, int c1, int c2, int d) {
  int res = 1;
  now.push_back(make_pair(x, y));
  a[x][y] = c2;
  for (int i = -d; i <= d; i++)
    for (int j = -d; j <= d; j++) {
      int nx = x + i;
      int ny = y + j;
      if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == c1)
        res += dfs(nx, ny, c1, c2, d);
    }
  return res;
}
int get(int x, int y, int c) {
  int res = 0;
  for (int i = 0; i < (int)(9); i++) {
    int nx = x + px[i];
    int ny = y + py[i];
    if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == c) res++;
  }
  return res;
}
void write() {
  return;
  for (int i = 0; i < (int)(n); i++) {
    for (int j = 0; j < (int)(m); j++) cout << a[i][j];
    cout << endl;
  }
}
bool check(int x, int y) {
  int res = 0;
  for (int i = -3; i <= 3; i++)
    for (int j = -3; j <= 3; j++) {
      int nx = x + i;
      int ny = y + j;
      if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
        if (a[nx][ny] == 2) res--;
        if (a[nx][ny] == 3) res++;
      }
    }
  return res > 0;
}
int calc() {
  vector<pair<int, int> > kl, w;
  for (int i = 0; i < (int)(now.size()); i++) {
    int x = now[i].first;
    int y = now[i].second;
    int e = get(x, y, 2);
    if (e < 9) kl.push_back(make_pair(x, y));
  }
  for (int i = 0; i < (int)(kl.size()); i++) {
    int x = kl[i].first;
    int y = kl[i].second;
    a[x][y] = 3;
  }
  for (int i = 0; i < (int)(now.size()); i++) {
    int x = now[i].first;
    int y = now[i].second;
    if (a[x][y] == 3) continue;
    int e = get(x, y, 3);
    int q = get(x, y, 2);
    if (e <= 3 || q >= 6) continue;
    if (check(x, y)) w.push_back(make_pair(x, y));
  }
  for (int i = 0; i < (int)(w.size()); i++) {
    int x = w[i].first;
    int y = w[i].second;
    a[x][y] = 5;
  }
  write();
  int res = 0;
  for (int i = 0; i < (int)(w.size()); i++) {
    int x = w[i].first;
    int y = w[i].second;
    if (a[x][y] == 5) {
      int w = dfs(x, y, 5, 6, 2);
      if (w > 3) res++;
    }
  }
  for (int i = 0; i < (int)(now.size()); i++) {
    int x = now[i].first;
    int y = now[i].second;
    a[x][y] = 0;
  }
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) {
      int x;
      scanf("%d", &x);
      a[i][j] = x;
    }
  vector<int> res;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++)
      if (a[i][j] == 1) {
        now.clear();
        dfs(i, j, 1, 2, 3);
        res.push_back(calc());
      }
  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for (int i = 0; i < (int)(res.size()); i++) cout << res[i] << " ";
  cout << endl;
  return 0;
}
