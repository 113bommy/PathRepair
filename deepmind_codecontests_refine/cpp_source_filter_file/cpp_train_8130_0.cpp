#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool RD(T& v) {
  char c;
  bool n;
  while (c = getchar(), c != '-' && (c < '0' || c > '9'))
    if (c == EOF) return false;
  if (c == '-') {
    n = true;
    v = 0;
  } else {
    n = false;
    v = c - '0';
  }
  while (c = getchar(), c >= '0' && c <= '9') v = (v << 3) + (v << 1) + c - '0';
  if (n) v *= -1;
  return true;
}
template <typename A, typename... Args>
inline bool RD(A& a, Args&... rest) {
  return RD(a) && RD(rest...);
}
inline int RD() {
  int v;
  RD(v);
  return v;
}
inline char getchar_buffered() {
  static char _BUF_[1 << 15], *_HEAD_ = _BUF_, *_TAIL_ = _BUF_;
  return _HEAD_ == _TAIL_ &&
                 (_TAIL_ = (_HEAD_ = _BUF_) + fread(_BUF_, 1, 1 << 15, stdin),
                  _HEAD_ == _TAIL_)
             ? EOF
             : *_HEAD_++;
}
template <typename T>
inline bool RDB(T& v) {
  char c;
  bool n;
  while (c = getchar_buffered(), c != '-' && (c < '0' || c > '9'))
    if (c == EOF) return false;
  if (c == '-') {
    n = true;
    v = 0;
  } else {
    n = false;
    v = c - '0';
  }
  while (c = getchar_buffered() - '0', c >= 0 && c <= 9)
    v = (v << 3) + (v << 1) + c;
  if (n) v *= -1;
  return true;
}
template <typename A, typename... Args>
inline bool RDB(A& a, Args&... rest) {
  return RDB(a) && RDB(rest...);
}
inline int RDB() {
  int v;
  RDB(v);
  return v;
}
template <typename T>
inline void _WR(T a) {
  if (a < 0) {
    putchar('-');
    a *= -1;
  }
  T t = a / 10;
  if (t) _WR(t);
  putchar(a - (t << 1) - (t << 3) + '0');
}
template <typename T>
inline void WR_(const T& a) {
  _WR(a);
  putchar(' ');
}
template <typename T>
inline void WR(const T& a) {
  _WR(a);
  putchar('\n');
}
template <typename A, typename... Args>
inline void _WR(const A& a, const Args&... rest) {
  WR_(a);
  _WR(rest...);
}
template <typename A, typename... Args>
inline void WR_(const A& a, const Args&... rest) {
  WR_(a);
  WR_(rest...);
}
template <typename A, typename... Args>
inline void WR(const A& a, const Args&... rest) {
  WR_(a);
  WR(rest...);
}
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxlog = 18;
template <typename T>
int cmin(T& x, T b) {
  if (b < x) {
    x = b;
    return 1;
  }
  if (x == b) return 0;
  return -1;
}
int n;
map<int, pair<int, int> > pos;
auto knight_moves = vector<pair<int, int> >{{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
int knight_dist[12][12];
void make_knight_dist_map(int x, int y) {
  memset(knight_dist, -1, sizeof(knight_dist));
  knight_dist[x][y] = 0;
  vector<pair<int, int> > q;
  q.push_back(pair<int, int>(x, y));
  for (int i = 0; i < (int)(q.size()); ++i) {
    int xi = q[i].first;
    int yi = q[i].second;
    for (auto pii : knight_moves) {
      int xx = xi + pii.first;
      int yy = yi + pii.second;
      if (xx >= 0 && xx < n && yy >= 0 && yy < n && knight_dist[xx][yy] == -1) {
        knight_dist[xx][yy] = knight_dist[xi][yi] + 1;
        q.push_back(pair<int, int>(xx, yy));
      }
    }
  }
}
pair<int, int> knight_to_knight(int x, int y, int a, int b) {
  make_knight_dist_map(x, y);
  if (knight_dist[a][b] > 0 && knight_dist[a][b] <= 3) {
    return {knight_dist[a][b], 0};
  }
  if (x == a || y == b || abs(x - a) == abs(y - b)) {
    return {3, (knight_dist[a][b] == 3 ? 0 : 2)};
  }
  return {4, (knight_dist[a][b] == 4 ? 0 : 2)};
}
pair<int, int> knight_to_bishop(int x, int y, int a, int b) {
  int dx = abs(x - a);
  int dy = abs(y - b);
  if (dx == dy) return {2, 1};
  if (dx > dy) swap(dx, dy);
  if (dx == 1 && dy == 2) return {2, 1};
  make_knight_dist_map(x, y);
  if (knight_dist[a][b] == 1) {
    return {2, 1};
  }
  if (knight_dist[a][b] == 2) {
    return {3, 1};
  }
  if ((dx & 1) == (dy & 1)) return {3, 1};
  int ret = inf;
  for (auto pii : knight_moves) {
    int xx = x + pii.first;
    int yy = y + pii.second;
    if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
    int t = knight_to_bishop(xx, yy, a, b).first;
    cmin(ret, t);
  }
  if (ret >= 3) {
    if (x == a || y == b) return {3, 2};
  }
  return {ret + 1, 1};
}
pair<int, int> knight_to_rook(int x, int y, int a, int b) {
  if (x == a || y == b) return {2, 1};
  int dx = abs(x - a);
  int dy = abs(y - b);
  if (dx > dy) swap(dx, dy);
  if (dx == 1 && dy == 2) return {2, 1};
  return {3, 1};
}
pair<int, int> bishop_to_bishop(int x, int y, int a, int b) {
  int dx = abs(x - a);
  int dy = abs(y - b);
  if (dx > dy) swap(dx, dy);
  if (dx == dy) return {1, 0};
  if ((dx & 1) == (dy & 1)) return {2, 0};
  if (x == a || y == b) return {3, 2};
  if (dx == 1 && dy == 2) return {3, 2};
  return {4, 2};
}
pair<int, int> bishop_to_rook(int x, int y, int a, int b) {
  int dx = abs(x - a);
  int dy = abs(y - b);
  if (dx == dy) return {2, 1};
  if (x == a || y == b) return {2, 1};
  return {3, 1};
}
pair<int, int> rook_to_rook(int x, int y, int a, int b) {
  if (x == a || y == b) return {1, 0};
  return {2, 0};
}
pair<int, int> dp[104][3];
pair<int, int> operator+(pair<int, int> x, pair<int, int> y) {
  return pair<int, int>(x.first + y.first, x.second + y.second);
}
int main() {
  RDB(n);
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(n); ++j) {
      int x = RDB();
      pos[x] = pair<int, int>(i, j);
    }
  for (int k = 0; k < (int)(3); ++k) dp[1][k] = pair<int, int>(0, 0);
  for (int i = 2; i < (int)(n * n + 1); ++i) {
    int x, y, a, b;
    tie(x, y) = pos[i - 1];
    tie(a, b) = pos[i];
    for (int k = 0; k < (int)(3); ++k) dp[i][k] = pair<int, int>(inf, inf);
    {
      auto kk = knight_to_knight(x, y, a, b);
      cmin(dp[i][0], dp[i - 1][0] + kk);
      auto kb = knight_to_bishop(x, y, a, b);
      cmin(dp[i][1], dp[i - 1][0] + kb);
      auto kr = knight_to_rook(x, y, a, b);
      cmin(dp[i][2], dp[i - 1][0] + kr);
    }
    {
      auto bk = knight_to_bishop(x, y, a, b);
      cmin(dp[i][0], dp[i - 1][1] + bk);
      auto bb = bishop_to_bishop(x, y, a, b);
      cmin(dp[i][1], dp[i - 1][1] + bb);
      auto br = bishop_to_rook(x, y, a, b);
      cmin(dp[i][2], dp[i - 1][1] + br);
    }
    {
      auto rk = knight_to_rook(x, y, a, b);
      cmin(dp[i][0], dp[i - 1][2] + rk);
      auto rb = bishop_to_rook(x, y, a, b);
      cmin(dp[i][1], dp[i - 1][2] + rb);
      auto rr = rook_to_rook(x, y, a, b);
      cmin(dp[i][2], dp[i - 1][2] + rr);
    };
  }
  pair<int, int> ret(inf, inf);
  for (int i = 0; i < (int)(3); ++i) cmin(ret, dp[n * n][i]);
  WR(ret.first, ret.second);
}
