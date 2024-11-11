#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int Read() {
  char c;
  c = getchar();
  int tsqua = 0;
  while (c != ' ' && c != '\n') {
    tsqua = (((tsqua << 1) << 1) << 1) + (tsqua << 1) + (int)(c - '0');
    c = getchar();
  }
  return tsqua;
}
int n, m;
char graph[20][20];
deque<char> posit, tmp_posit;
int kx, tmp_kx;
int tmp;
int ans = -1;
pair<int, int> p;
pair<int, deque<char> > pv;
set<pair<int, int> > s;
queue<pair<int, deque<char> > > q;
queue<int> mask;
int snake;
int pow_of(int x, int y) {
  int ret = 1;
  for (int i = 0; i < y; i++) ret *= x;
  return ret;
}
int To_Data(deque<char> deq) {
  int ret = 0;
  int powthing = 0;
  for (int i = 0; i < deq.size(); i++) {
    if (deq[i] == 'U')
      ret += (4 * (pow_of(10, powthing++)));
    else if (deq[i] == 'D')
      ret += (3 * (pow_of(10, powthing++)));
    else if (deq[i] == 'L')
      ret += (1 * (pow_of(10, powthing++)));
    else if (deq[i] == 'R')
      ret += (2 * (pow_of(10, powthing++)));
  }
  return ret;
}
void DFS(int x, int y) {
  if ((x >= 1) && (graph[x - 1][y] == graph[x][y] + 1)) {
    posit.push_back('U');
    DFS(x - 1, y);
  } else if ((x < n - 1) && (graph[x + 1][y] == graph[x][y] + 1)) {
    posit.push_back('D');
    DFS(x + 1, y);
  } else if (y >= 1 && graph[x][y - 1] == graph[x][y] + 1) {
    posit.push_back('L');
    DFS(x, y - 1);
  } else if ((x < m - 1) && graph[x][y + 1] == graph[x][y] + 1) {
    posit.push_back('R');
    DFS(x, y + 1);
  } else
    ;
}
bool check(char pos) {
  tmp_posit = posit;
  tmp_kx = kx;
  if (pos == 'L') {
    if ((tmp_kx % 100) < 1) return false;
    tmp_kx--;
    tmp_posit.push_front('R');
  } else if (pos == 'R') {
    if ((tmp_kx % 100) >= m - 1) return false;
    tmp_kx++;
    tmp_posit.push_front('L');
  } else if (pos == 'U') {
    if ((tmp_kx) / 100 < 1) return false;
    tmp_kx -= 100;
    tmp_posit.push_front('D');
  } else if (pos == 'D') {
    if ((tmp_kx) / 100 >= n - 1) return false;
    tmp_kx += 100;
    tmp_posit.push_front('U');
  } else
    ;
  if (graph[tmp_kx / 100][tmp_kx % 100] == '#') return false;
  tmp_posit.pop_back();
  tmp = tmp_kx;
  for (int i = 0; i < tmp_posit.size(); i++) {
    if (tmp_posit[i] == 'L')
      tmp--;
    else if (tmp_posit[i] == 'R')
      tmp++;
    else if (tmp_posit[i] == 'U')
      tmp -= 100;
    else if (tmp_posit[i] == 'D')
      tmp += 100;
    else
      ;
    if (tmp == tmp_kx) return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> graph[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (graph[i][j] == '1') {
        kx = i * 100 + j;
        posit.clear();
        DFS(i, j);
      }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (isdigit(graph[i][j])) graph[i][j] == '.';
  pv = make_pair(kx, posit);
  p = make_pair(kx, To_Data(posit));
  s.insert(p);
  mask.push(0);
  q.push(pv);
  while (!q.empty()) {
    kx = q.front().first;
    posit = q.front().second;
    q.pop();
    snake = mask.front();
    mask.pop();
    if (graph[kx / 100][kx % 100] == '@') {
      ans = snake;
      break;
    }
    if (check('L')) {
      pv = make_pair(tmp_kx, tmp_posit);
      p = make_pair(tmp_kx, To_Data(tmp_posit));
      if (s.find(p) == s.end()) {
        s.insert(p);
        mask.push(snake + 1);
        q.push(pv);
      }
    }
    if (check('R')) {
      pv = make_pair(tmp_kx, tmp_posit);
      p = make_pair(tmp_kx, To_Data(tmp_posit));
      if (s.find(p) == s.end()) {
        s.insert(p);
        mask.push(snake + 1);
        q.push(pv);
      }
    }
    if (check('U')) {
      pv = make_pair(tmp_kx, tmp_posit);
      p = make_pair(tmp_kx, To_Data(tmp_posit));
      if (s.find(p) == s.end()) {
        s.insert(p);
        mask.push(snake + 1);
        q.push(pv);
      }
    }
    if (check('D')) {
      pv = make_pair(tmp_kx, tmp_posit);
      p = make_pair(tmp_kx, To_Data(tmp_posit));
      if (s.find(p) == s.end()) {
        s.insert(p);
        mask.push(snake + 1);
        q.push(pv);
      }
    }
  }
  cout << ans;
  return 0;
}
