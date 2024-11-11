#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
inline int read() {
  int ans = 0;
  bool f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = getchar();
  return f ? ans : -ans;
}
long long n, m;
bool CanMove(long long x, long long y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}
long long DFS1(long long x, long long y, long long sx, long long sy) {
  x--, y--;
  sx--, sy--;
  long long val[n][m];
  queue<pair<long long, long long> > q;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) val[i][j] = 0;
  q.push(make_pair(x, y));
  val[x][y] = 1;
  while (!q.empty()) {
    pair<long long, long long> p = q.front();
    q.pop();
    long long X = p.first, Y = p.second;
    if (CanMove(X + 1, Y + 2) && val[X + 1][Y + 2] == 0) {
      q.push(make_pair(X + 1, Y + 2));
      val[X + 1][Y + 2] = val[X][Y] + 1;
    }
    if (CanMove(X + 1, Y - 2) && val[X + 1][Y - 2] == 0) {
      q.push(make_pair(X + 1, Y - 2));
      val[X + 1][Y - 2] = val[X][Y] + 1;
    }
    if (CanMove(X - 1, Y + 2) && val[X - 1][Y + 2] == 0) {
      q.push(make_pair(X - 1, Y + 2));
      val[X - 1][Y + 2] = val[X][Y] + 1;
    }
    if (CanMove(X - 1, Y - 2) && val[X - 1][Y - 2] == 0) {
      q.push(make_pair(X - 1, Y - 2));
      val[X - 1][Y - 2] = val[X][Y] + 1;
    }
    if (CanMove(X + 2, Y + 1) && val[X + 2][Y + 1] == 0) {
      q.push(make_pair(X + 2, Y + 1));
      val[X + 2][Y + 1] = val[X][Y] + 1;
    }
    if (CanMove(X + 2, Y - 1) && val[X + 2][Y - 1] == 0) {
      q.push(make_pair(X + 2, Y - 1));
      val[X + 2][Y - 1] = val[X][Y] + 1;
    }
    if (CanMove(X - 2, Y + 1) && val[X - 2][Y + 1] == 0) {
      q.push(make_pair(X - 2, Y + 1));
      val[X - 2][Y + 1] = val[X][Y] + 1;
    }
    if (CanMove(X - 2, Y - 1) && val[X - 2][Y - 1] == 0) {
      q.push(make_pair(X - 2, Y - 1));
      val[X - 2][Y - 1] = val[X][Y] + 1;
    }
  }
  return val[sx][sy];
}
vector<pair<long long, long long> > DFS2(long long x, long long y, long long sx,
                                         long long sy) {
  x--, y--;
  sx--, sy--;
  long long val[n][m];
  pair<long long, long long> pre[n][m];
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) val[i][j] = 0;
  vector<pair<long long, long long> > v;
  v.clear();
  queue<pair<long long, long long> > q;
  q.push(make_pair(x, y));
  val[x][y] = 1;
  while (!q.empty()) {
    pair<long long, long long> pp = q.front();
    q.pop();
    long long X = pp.first, Y = pp.second;
    if (CanMove(X + 1, Y + 2) && val[X + 1][Y + 2] == 0) {
      q.push(make_pair(X + 1, Y + 2));
      val[X + 1][Y + 2] = val[X][Y] + 1;
      pre[X + 1][Y + 2] = make_pair(X, Y);
    }
    if (CanMove(X + 1, Y - 2) && val[X + 1][Y - 2] == 0) {
      q.push(make_pair(X + 1, Y - 2));
      val[X + 1][Y - 2] = val[X][Y] + 1;
      pre[X + 1][Y - 2] = make_pair(X, Y);
    }
    if (CanMove(X - 1, Y + 2) && val[X - 1][Y + 2] == 0) {
      q.push(make_pair(X - 1, Y + 2));
      val[X - 1][Y + 2] = val[X][Y] + 1;
      pre[X - 1][Y + 2] = make_pair(X, Y);
    }
    if (CanMove(X - 1, Y - 2) && val[X - 1][Y - 2] == 0) {
      q.push(make_pair(X - 1, Y - 2));
      val[X - 1][Y - 2] = val[X][Y] + 1;
      pre[X - 1][Y - 2] = make_pair(X, Y);
    }
    if (CanMove(X + 2, Y + 1) && val[X + 2][Y + 1] == 0) {
      q.push(make_pair(X + 2, Y + 1));
      val[X + 2][Y + 1] = val[X][Y] + 1;
      pre[X + 2][Y + 1] = make_pair(X, Y);
    }
    if (CanMove(X + 2, Y - 1) && val[X + 2][Y - 1] == 0) {
      q.push(make_pair(X + 2, Y - 1));
      val[X + 2][Y - 1] = val[X][Y] + 1;
      pre[X + 2][Y - 1] = make_pair(X, Y);
    }
    if (CanMove(X - 2, Y + 1) && val[X - 2][Y + 1] == 0) {
      q.push(make_pair(X - 2, Y + 1));
      val[X - 2][Y + 1] = val[X][Y] + 1;
      pre[X - 2][Y + 1] = make_pair(X, Y);
    }
    if (CanMove(X - 2, Y - 1) && val[X - 2][Y - 1] == 0) {
      q.push(make_pair(X - 2, Y - 1));
      val[X - 2][Y - 1] = val[X][Y] + 1;
      pre[X - 2][Y - 1] = make_pair(X, Y);
    }
  }
  while (sx != x || sy != y) {
    v.push_back(make_pair(sx + 1, sy + 1));
    pair<long long, long long> pp = pre[sx][sy];
    sx = pp.first, sy = pp.second;
  }
  return v;
}
vector<pair<long long, long long> > v;
long long x, y, sx, sy;
long long fl1, fl2;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> x >> y >> sx >> sy;
  fl1 = ((x + y) % 2 != (sx + sy) % 2);
  long long aa = DFS1(x, y, n / 2, m / 2);
  long long bb = DFS1(sx, sy, n / 2, m / 2);
  long long cc = DFS1(x, y, n / 2 + 1, m / 2);
  long long dd = DFS1(sx, sy, n / 2 + 1, m / 2);
  if (fl1 == 0)
    fl2 = ((dd < aa) || (bb <= aa));
  else
    fl2 = (!((aa <= dd) || ((cc - 1) <= dd)));
  cout << (fl2 ? "BLACK" : "WHITE") << endl;
  if (fl2) {
    if (fl1) {
      v = DFS2(sx, sy, n / 2 + 1, m / 2);
      for (long long i = (long long)v.size() - 1; i >= 0; i--) {
        long long a, b;
        cin >> a >> b;
        cout << v[i].first << ' ' << v[i].second << endl;
      }
    } else {
      if (dd < aa) {
        v = DFS2(sx, sy, n / 2 + 1, m / 2);
        for (long long i = (long long)v.size() - 1; i >= 0; i--) {
          long long a, b;
          cin >> a >> b;
          cout << v[i].first << ' ' << v[i].second << endl;
          if ((a == v[i].first) && (b == v[i].second)) return 0;
        }
      } else {
        v = DFS2(sx, sy, n / 2, m / 2);
        for (long long i = (long long)v.size() - 1; i >= 0; i--) {
          long long a, b;
          cin >> a >> b;
          long long c, d;
          c = abs(sx - a);
          d = abs(sy - b);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << a << ' ' << b << endl;
            return 0;
          } else {
            cout << v[i].first << ' ' << v[i].second << endl;
            sx = v[i].first, sy = v[i].second;
          }
        }
        long long a, b;
        cin >> a >> b;
        long long c, d;
        c = abs(sx - a);
        d = abs(sy - b);
        if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
          cout << a << ' ' << b << endl;
          return 0;
        } else {
          sx++, sy += 2;
          cout << sx << ' ' << sy << endl;
          cin >> a >> b;
          c = abs(sx - a);
          d = abs(sy - b);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << a << ' ' << b << endl;
            return 0;
          } else {
            sx -= 2;
            sy--;
            cout << sx << ' ' << sy << endl;
            sx += 2;
            sy--;
            cin >> a >> b;
            cout << sx << ' ' << sy << endl;
          }
        }
      }
    }
  } else {
    if (!fl1) {
      v = DFS2(x, y, n / 2, m / 2);
      cout << v[v.size() - 1].first << ' ' << v[v.size() - 1].second << endl;
      for (long long i = (long long)v.size() - 2; i >= 0; i--) {
        long long a, b;
        cin >> a >> b;
        cout << v[i].first << ' ' << v[i].second << endl;
      }
    } else {
      if (aa <= dd) {
        v = DFS2(x, y, n / 2, m / 2);
        cout << v[v.size() - 1].first << ' ' << v[v.size() - 1].second << endl;
        if (v[v.size() - 1].first == x && v[v.size() - 1].second == y) return 0;
        for (long long i = (long long)v.size() - 2; i >= 0; i--) {
          long long a, b;
          cin >> a >> b;
          cout << v[i].first << ' ' << v[i].second << endl;
          if (v[i].first == x && v[i].second == y) return 0;
        }
      } else {
        v = DFS2(x, y, n / 2 + 1, m / 2);
        long long P = sx, Q = sy;
        long long X = x, Y = y;
        for (long long i = (long long)v.size() - 1; i >= 0; i--) {
          long long c, d;
          c = abs(X - P);
          d = abs(Y - Q);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << P << ' ' << Q << endl;
            return 0;
          } else {
            cout << v[i].first << ' ' << v[i].second << endl;
            cin >> P >> Q;
            X = v[i].first;
            Y = v[i].second;
          }
        }
        long long c, d;
        c = abs(X - P);
        d = abs(Y - Q);
        if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
          cout << P << ' ' << Q << endl;
          return 0;
        } else {
          X -= 2, Y++;
          cout << X << ' ' << Y << endl;
          cin >> P >> Q;
          c = abs(X - P);
          d = abs(Y - Q);
          if ((c == 1 && d == 2) || (c == 2 && d == 1)) {
            cout << P << ' ' << Q << endl;
            return 0;
          } else {
            X += 2, Y++;
            cout << X << ' ' << Y << endl;
            cin >> P >> Q;
            X--, Y -= 2;
            cout << X << ' ' << Y << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
