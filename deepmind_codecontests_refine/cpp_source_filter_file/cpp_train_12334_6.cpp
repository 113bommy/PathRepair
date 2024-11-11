#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int NMAX = 2000 + 5;
const int MMAX = 100000 + 5;
const int INF = 1000000000;
const int BS = 1000000007;
template <typename T>
inline T abs(const T a) {
  if (a < 0) return -a;
  return a;
}
template <typename T>
inline T sqr(const T& a) {
  return a * a;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  int i, j;
  static char a[NMAX][NMAX];
  static int deg[NMAX][NMAX] = {0};
  queue<pair<int, int> > st;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '.') {
        deg[i - 1][j]++;
        deg[i + 1][j]++;
        deg[i][j - 1]++;
        deg[i][j + 1]++;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == '.') {
        if (deg[i][j] == 1) st.push(make_pair(i, j));
      }
    }
  }
  pair<int, int> cur;
  pair<int, int> wantgo;
  while (!st.empty()) {
    cur = st.front();
    st.pop();
    if (deg[cur.first][cur.second] == 0) continue;
    deg[cur.first][cur.second] = 0;
    wantgo = cur;
    wantgo.first++;
    if (a[wantgo.first][wantgo.second] == '.') {
      a[cur.first][cur.second] = '^';
      a[wantgo.first][wantgo.second] = 'v';
    } else {
      wantgo = cur;
      wantgo.first--;
      if (a[wantgo.first][wantgo.second] == '.') {
        a[cur.first][cur.second] = 'v';
        a[wantgo.first][wantgo.second] = '^';
      } else {
        wantgo = cur;
        wantgo.second++;
        if (a[wantgo.first][wantgo.second] == '.') {
          a[cur.first][cur.second] = '<';
          a[wantgo.first][wantgo.second] = '>';
        } else {
          wantgo = cur;
          wantgo.second--;
          if (a[wantgo.first][wantgo.second] == '.') {
            a[cur.first][cur.second] = '>';
            a[wantgo.first][wantgo.second] = '<';
          }
        }
      }
    }
    cur = wantgo;
    wantgo = cur;
    wantgo.first++;
    if (a[wantgo.first][wantgo.second] == '.') {
      deg[wantgo.first][wantgo.second]--;
      if (deg[wantgo.first][wantgo.second] == 1) st.push(wantgo);
    }
    wantgo = cur;
    wantgo.first--;
    if (a[wantgo.first][wantgo.second] == '.') {
      deg[wantgo.first][wantgo.second]--;
      if (deg[wantgo.first][wantgo.second] == 1) st.push(wantgo);
    }
    wantgo = cur;
    wantgo.second++;
    if (a[wantgo.first][wantgo.second] == '.') {
      deg[wantgo.first][wantgo.second]--;
      if (deg[wantgo.first][wantgo.second] == 1) st.push(wantgo);
    }
    wantgo = cur;
    wantgo.second--;
    if (a[wantgo.first][wantgo.second] == '.') {
      deg[wantgo.first][wantgo.second]--;
      if (deg[wantgo.first][wantgo.second] == 1) st.push(wantgo);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == '.') {
        cout << "Not unique" << endl;
        return 0;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
