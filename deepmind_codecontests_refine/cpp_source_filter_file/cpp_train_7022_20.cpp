#include <bits/stdc++.h>
using namespace std;
template <class T>
void debug(T a, T b) {
  ;
}
template <class T>
void chmin(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
namespace std {
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& a) {
  out << '(' << a.first << ',' << a.second << ')';
  return out;
}
}  // namespace std
long long int readL() {
  long long int res;
  scanf("%I64d", &res);
  return res;
}
void printL(long long int res) { printf("%I64d", res); }
int h, w;
int buf[35][35];
int goal[35][35];
pair<int, int> res[1000005];
int mark[35][35];
int cnt;
int sx, sy;
void up() {
  swap(buf[sy][sx], buf[sy - 1][sx]);
  --sy;
  res[cnt++] = make_pair(sy, sx);
}
void down() {
  swap(buf[sy][sx], buf[sy + 1][sx]);
  ++sy;
  res[cnt++] = make_pair(sy, sx);
}
void right() {
  swap(buf[sy][sx + 1], buf[sy][sx]);
  ++sx;
  res[cnt++] = make_pair(sy, sx);
}
void left() {
  swap(buf[sy][sx - 1], buf[sy][sx]);
  --sx;
  res[cnt++] = make_pair(sy, sx);
}
int id[35][35], curid = 1;
pair<int, int> back[35][35];
void go(int y, int x) {
  ++curid;
  queue<pair<int, int> > q;
  q.push(make_pair(sy, sx));
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dx = (-1); dx < (2); ++dx)
      for (int dy = (-1); dy < (2); ++dy) {
        if (dx == 0 && dy == 0) continue;
        int px = cur.second + dx, py = cur.first + dy;
        if (px < 0 || py < 0 || px >= w || py >= h || mark[py][px] ||
            id[py][px] == curid)
          continue;
        q.push(make_pair(py, px));
        id[py][px] = curid;
        back[py][px] = make_pair(cur.first, cur.second);
        if (make_pair(py, px) == make_pair(y, x)) {
          goto exi4;
        }
      }
  }
exi4:;
  ;
  ;
  vector<pair<int, int> > way;
  pair<int, int> cur = make_pair(y, x);
  while (cur != make_pair(sy, sx)) {
    way.push_back(cur);
    cur = back[cur.first][cur.second];
  }
  reverse((way).begin(), (way).end());
  for (int i = 0; i < (way.size()); ++i) {
    swap(buf[way[i].first][way[i].second], buf[sy][sx]);
    sy = way[i].first;
    sx = way[i].second;
    res[cnt++] = way[i];
  }
  sx = x;
  sy = y;
}
void moveR(int y, int x) {
  mark[y][x] = 1;
  go(y, x + 1);
  left();
  mark[y][x] = 0;
}
void moveL(int y, int x) {
  mark[y][x] = 1;
  go(y, x - 1);
  right();
  mark[y][x] = 0;
}
void moveD(int y, int x) {
  mark[y][x] = 1;
  go(y + 1, x);
  up();
  mark[y][x] = 0;
}
void moveU(int y, int x) {
  mark[y][x] = 1;
  go(y - 1, x);
  down();
  mark[y][x] = 0;
}
void end() {
  puts("-1");
  exit(0);
}
void print() {
  printf("%d\n", cnt - 1);
  for (int i = 0; i < (cnt); ++i)
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
  exit(0);
}
int main() {
  cin >> h >> w;
  for (int i = 0; i < (h); ++i)
    for (int j = 0; j < (w); ++j) cin >> buf[i][j];
  for (int i = 0; i < (h); ++i)
    for (int j = 0; j < (w); ++j) cin >> goal[i][j];
  if (h < 2 || w < 2) {
    int ar[35] = {0}, ar2[35] = {0};
    int n;
    if (h == 1) {
      for (int i = 0; i < (w); ++i) ar[i] = buf[0][i], ar2[i] = goal[0][i];
      n = w;
    } else {
      for (int i = 0; i < (h); ++i) ar[i] = buf[i][0], ar2[i] = goal[i][0];
      n = h;
    }
    for (int i = 0; i < (n); ++i)
      if (ar[i] != ar2[i]) {
        for (int j = (i + 1); j < (n); ++j)
          if (ar2[i] == ar[j]) {
            ;
            ;
            ;
            ;
            rotate(ar + i, ar + j, ar + j + 1);
            int fail = 0;
            for (int k = 0; k < (n); ++k)
              if (ar[k] != ar2[k]) fail = 1;
            if (!fail) {
              for (int k = j; k >= i; --k) res[cnt++] = make_pair(k, 0);
              goto exi3;
            }
            rotate(ar + i, ar + i + 1, ar + j + 1);
          }
        for (int j = (i + 1); j < (n); ++j)
          if (ar2[j] == ar[i]) {
            rotate(ar + i, ar + i + 1, ar + j + 1);
            int fail = 0;
            for (int k = 0; k < (n); ++k)
              if (ar[k] != ar2[k]) fail = 1;
            if (!fail) {
              for (int k = j; k >= i; --k) res[cnt++] = make_pair(k, 0);
              goto exi3;
            }
            rotate(ar + i, ar + j, ar + j + 1);
          }
        break;
      }
    end();
  exi3:;
    if (w == 1)
      ;
    else
      for (int i = 0; i < (cnt); ++i) {
        swap(res[i].first, res[i].second);
      }
    print();
  }
  sx = sy = -1;
  for (int i = 0; i < (h); ++i)
    for (int j = 0; j < (w); ++j)
      if (buf[i][j] == goal[h - 1][w - 1]) {
        sy = i;
        sx = j;
      }
  if (sx == -1) end();
  res[cnt++] = make_pair(sy, sx);
  for (int i = 0; i < (h - 2); ++i)
    for (int j = 0; j < (w); ++j) {
      pair<int, int> pos;
      for (int k = 0; k < (h); ++k)
        for (int l = 0; l < (w); ++l)
          if (!mark[k][l] && make_pair(k, l) != make_pair(sy, sx) &&
              goal[i][j] == buf[k][l]) {
            pos = make_pair(k, l);
            goto exi;
          }
      end();
    exi:;
      while (pos != make_pair(i, j)) {
        if (pos.second < j) {
          moveR(pos.first, pos.second);
          ++pos.second;
        } else if (pos.second > j) {
          moveL(pos.first, pos.second);
          --pos.second;
        } else if (pos.first > i) {
          moveU(pos.first, pos.second);
          --pos.first;
        }
      }
      mark[i][j] = 1;
    }
  for (int j = 0; j < (w - 1); ++j)
    for (int i = (h - 2); i < (h); ++i) {
      ;
      ;
      ;
      ;
      ;
      ;
      pair<int, int> pos;
      for (int k = 0; k < (h); ++k)
        for (int l = 0; l < (w); ++l)
          if (!mark[k][l] && make_pair(k, l) != make_pair(sy, sx) &&
              goal[i][j] == buf[k][l]) {
            pos = make_pair(k, l);
            goto exi2;
          }
      end();
    exi2:;
      ;
      ;
      while (pos != make_pair(i, j)) {
        if (i < pos.first) {
          moveU(pos.first, pos.second);
          --pos.first;
        } else if (i > pos.first) {
          moveD(pos.first, pos.second);
          ++pos.first;
        } else {
          moveL(pos.first, pos.second);
          --pos.second;
        }
      }
      mark[i][j] = 1;
    }
  if (sy < h - 1) down();
  if (buf[h - 2][w - 1] == goal[h - 2][w - 1])
    ;
  else
    end();
  print();
  return 0;
}
