#include <bits/stdc++.h>
using namespace std;
const long long MAX = 101;
const int SIZE = 4010;
class Pair {
 public:
  long long x, y;
  Pair(long long x_ = 0, long long y_ = 0) { x = x_, y = y_; }
};
void print(Pair p) { cout << "(" << p.x << " " << p.y << ")"; }
bool operator<(const Pair &a, const Pair &b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
vector<Pair> P;
vector<Pair> CX, CY;
int board[SIZE][SIZE];
long long size(int i, int j) {
  long long a = CX[i].y - CX[i].x + 1;
  long long b = CY[j].y - CY[j].x + 1;
  return a * b;
}
int findpos(const vector<Pair> &a, long long x) {
  int l = 0, r = a.size() - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (a[mid].y < x)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}
void set_seg(vector<long long> &a, vector<Pair> &b) {
  a.push_back(1);
  a.push_back(MAX);
  sort(a.begin(), a.end());
  b.clear();
  for (int i = 0; i < a.size(); i++) {
    if (i > 0 && a[i] > a[i - 1] + 1) {
      b.push_back(Pair(a[i - 1] + 1, a[i] - 1));
    }
    if (i == 0 || a[i] != a[i - 1]) b.push_back(Pair(a[i], a[i]));
  }
}
queue<Pair> Q;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void work(void) {
  Q.push(Pair(0, 0));
  board[0][0] = 2;
  while (!Q.empty()) {
    Pair p = Q.front();
    Q.pop();
    for (int d = 0; d < 4; d++) {
      int x1 = p.x + dx[d], y1 = p.y + dy[d];
      if (x1 >= 0 && x1 < CX.size() && y1 >= 0 && y1 <= CY.size()) {
        if (board[x1][y1] == 0) {
          board[x1][y1] = 2;
          Q.push(Pair(x1, y1));
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < CX.size(); i++) {
    for (int j = 0; j < CY.size(); j++) {
      if (board[i][j] != 2) ans += size(i, j);
    }
  }
  cout << ans << endl;
}
void prepare(void) {
  static vector<long long> X, Y;
  for (int i = 0; i < P.size(); i++) {
    X.push_back(P[i].x);
    Y.push_back(P[i].y);
  }
  set_seg(X, CX);
  set_seg(Y, CY);
  for (int i = 0; i < P.size() - 1; i++) {
    int x1 = findpos(CX, P[i].x), x2 = findpos(CX, P[i + 1].x);
    int y1 = findpos(CY, P[i].y), y2 = findpos(CY, P[i + 1].y);
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for (int x = x1; x <= x2; x++) {
      for (int y = y1; y <= y2; y++) {
        board[x][y] = 1;
      }
    }
  }
}
void read(void) {
  int n;
  Pair now((MAX + 1) / 2, (MAX + 1) / 2);
  P.push_back(now);
  scanf("%d\n", &n);
  char ch;
  int d;
  for (int i = 0; i < n; i++) {
    scanf("%c %d\n", &ch, &d);
    if (ch == 'R')
      now.y += d;
    else if (ch == 'L')
      now.y -= d;
    else if (ch == 'U')
      now.x -= d;
    else if (ch == 'D')
      now.x += d;
    P.push_back(now);
  }
}
int main() {
  read();
  prepare();
  work();
  return 0;
}
