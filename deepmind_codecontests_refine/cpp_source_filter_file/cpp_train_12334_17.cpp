#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
double eps = 1e-10;
const int maxn = 2e3 + 10;
const int mod = 998244353;
const double pi = acos(-1.0);
vector<pair<int, int> > vc[maxn * maxn];
int ru[maxn * maxn];
char s[maxn][maxn];
int n, m;
int getid(int x, int y) { return x * m + y; }
pair<int, int> getpos(int x) { return pair<int, int>(x / m, x % m); }
void make(int x, int y, int x1, int y1) {
  if (x == x1) {
    if (y > y1) {
      s[x][y] = '>';
      s[x1][y1] = '<';
    } else {
      s[x][y] = '<';
      s[x1][y1] = '>';
    }
  } else {
    if (x > x1) {
      s[x][y] = 'v';
      s[x1][y1] = '^';
    } else {
      s[x][y] = '^';
      s[x1][y1] = 'v';
    }
  }
}
int sum;
int point;
void topo() {
  queue<pair<int, int> > q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ru[getid(i, j)] == 1) {
        q.push(pair<int, int>(i, j));
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();
    int x = temp.first, y = temp.second;
    int id = getid(temp.first, temp.second);
    for (int i = 0; i < vc[id].size(); i++) {
      if (s[vc[id][i].first][vc[id][i].second] == '.') {
        make(x, y, vc[id][i].first, vc[id][i].second);
        int id2 = getid(vc[id][i].first, vc[id][i].second);
        sum += 2;
        for (int j = 0; j < vc[id2].size(); j++) {
          if (s[vc[id2][j].first][vc[id2][j].second] == '.') {
            ru[getid(vc[id2][j].first, vc[id2][j].second)]--;
            if (ru[getid(vc[id2][j].first, vc[id2][j].second)] == 1) {
              q.push(pair<int, int>(vc[id2][j].first, vc[id2][j].second));
            }
          }
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
  }
  int num = 0;
  int node = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.') {
        node++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.') {
        if (i >= 1 && s[i - 1][j] == '.') {
          vc[getid(i, j)].push_back(make_pair(i - 1, j));
          ru[getid(i - 1, j)]++;
        }
        if (i <= n - 2 && s[i + 1][j] == '.') {
          vc[getid(i, j)].push_back(make_pair(i + 1, j));
          ru[getid(i + 1, j)]++;
        }
        if (j >= 1 && s[i][j - 1] == '.') {
          vc[getid(i, j)].push_back(make_pair(i, j - 1));
          ru[getid(i, j - 1)]++;
        }
        if (j <= m - 2 && s[i][j + 1] == '.') {
          vc[getid(i, j)].push_back(make_pair(i, j + 1));
          ru[getid(i, j + 1)]++;
        }
      }
    }
  }
  topo();
  if (node == sum) {
    for (int i = 0; i < n; i++) {
      cout << s[i] << endl;
    }
  } else {
    cout << "Not unique";
  }
}
