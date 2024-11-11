#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T MDINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first - b.first) * (b.second - c.second) -
       (b.first - c.first) * (a.second - b.second)) < 0.0)
    return 1;
  else
    return 0;
}
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char ch[n + 2][m + 2];
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch[i] + 1);
  }
  int a[n + 2][m + 2];
  memset(a, 0, sizeof a);
  queue<pair<int, int> > q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == '*') continue;
      for (int k = 0; k < 4; k++) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (x >= 1 && x <= n && y >= 1 && y <= m) {
          if (ch[x][y] == '.') a[i][j]++;
        }
      }
      if (a[i][j] == 1) {
        q.push(make_pair(i, j));
      }
    }
  }
  bool fl = 0;
  while (!q.empty()) {
    pair<int, int> x = q.front();
    q.pop();
    bool cl = 0;
    for (int i = 0; i < 4; i++) {
      int u = x.first + dx[i];
      int v = x.second + dy[i];
      if (u >= 1 && u <= n && v >= 1 && v <= m && ch[u][v] == '.') {
        a[x.first][x.second]--;
        a[u][v]--;
        for (int k = 0; k < 4; k++) {
          int ho = u + dx[k];
          int jo = v + dy[k];
          if (ho >= 1 && ho <= n && jo >= 1 && jo <= m && ch[ho][jo] == '.' &&
              ho != x.first && jo != x.second) {
            a[ho][jo]--;
            if (a[ho][jo] == 1) q.push(make_pair(ho, jo));
          }
        }
        cl = 1;
        if (x.first == u) {
          if (x.second < v) {
            ch[x.first][x.second] = '<';
            ch[u][v] = '>';
          } else {
            ch[x.first][x.second] = '>';
            ch[u][v] = '<';
          }
        } else {
          if (x.first < u) {
            ch[x.first][x.second] = '^';
            ch[u][v] = 'v';
          } else {
            ch[x.first][x.second] = 'v';
            ch[u][v] = '^';
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == '.') fl = 1;
    }
  }
  if (fl == 1)
    printf("Not unique\n");
  else {
    for (int i = 1; i <= n; i++) {
      printf("%s\n", ch[i] + 1);
    }
  }
  return 0;
}
