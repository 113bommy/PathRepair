#include <bits/stdc++.h>
using namespace std;
int n, m;
deque<char> q;
vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};
vector<char> dq = {'D', 'L', 'R', 'U'};
vector<vector<int> > used;
vector<vector<char> > a;
bool dfs(int x, int y) {
  if (!(x < n && x >= 0 && y < m && y >= 0)) {
    return false;
  }
  if (used[x][y]) {
    return false;
  }
  if (a[x][y] == '*') {
    return false;
  }
  used[x][y] = true;
  if (a[x][y] == 'F') {
    return true;
  }
  for (int i = 0; i < 4; i++) {
    q.push_back(dq[i]);
    if (dfs(x + dx[i], y + dy[i])) {
      return true;
    }
    q.pop_back();
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y;
  cin >> n >> m;
  a.resize(n, vector<char>(m));
  used.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  used.assign(n, vector<int>(m));
  if (a[0][0] == 'F') {
    return 0;
  }
  if (n == 1) {
    cout << 'L' << endl;
    cin >> x >> y;
    x--;
    y--;
    int s = 0;
    if (x == 0 && y == 0) {
      while (a[0][s] != 'F') {
        cout << 'R' << endl;
        cin >> x >> y;
        x--;
        y--;
        s++;
      }
    } else {
      s = 1;
      while (a[0][s] != 'F') {
        cout << 'L' << endl;
        cin >> x >> y;
        x--;
        y--;
        s++;
      }
    }
    return 0;
  }
  if (m == 1) {
    cout << 'D' << endl;
    cin >> x >> y;
    x--;
    y--;
    int s = 0;
    if (x == 0 && y == 0) {
      while (a[s][0] != 'F') {
        cout << 'U' << endl;
        cin >> x >> y;
        x--;
        y--;
        s++;
      }
    } else {
      s = 1;
      while (a[s][0] != 'F') {
        cout << 'D' << endl;
        cin >> x >> y;
        x--;
        y--;
        s++;
      }
    }
    return 0;
  }
  map<char, char> voc;
  voc['L'] = 'L';
  voc['R'] = 'R';
  voc['U'] = 'U';
  voc['D'] = 'D';
  if (a[1][0] != '*' && a[0][1] != '*') {
    cout << 'L' << endl;
    cin >> x >> y;
    x--;
    y--;
    if (!(x == 0 && y == 0)) {
      swap(voc['L'], voc['R']);
      cout << 'R' << endl;
      cin >> x >> y;
      x--;
      y--;
    }
    cout << 'D' << endl;
    cin >> x >> y;
    x--;
    y--;
    if (!(x == 0 && y == 0)) {
      swap(voc['U'], voc['D']);
      cout << 'U' << endl;
      cin >> x >> y;
      x--;
      y--;
    }
    dfs(0, 0);
    while (!q.empty()) {
      cout << voc[q.front()] << endl;
      cin >> x >> y;
      x--;
      y--;
      q.pop_front();
    }
    return 0;
  }
  if (a[1][0] != '*') {
    cout << 'D' << endl;
    cin >> x >> y;
    x--;
    y--;
    if (!(x == 0 && y == 0)) {
      swap(voc['U'], voc['D']);
      cout << 'U' << endl;
      cin >> x >> y;
      x--;
      y--;
    }
    int s = 0;
    while (a[s][1] == '*') {
      s++;
      cout << voc['U'] << endl;
      cin >> x >> y;
      x--;
      y--;
    }
    cout << 'L' << endl;
    int nx, ny;
    cin >> nx >> ny;
    nx--;
    ny--;
    if (!(x == nx && y == ny)) {
      swap(voc['L'], voc['R']);
      cout << 'R' << endl;
      cin >> x >> y;
      x--;
      y--;
    }
    dfs(x, y);
    while (!q.empty()) {
      cout << voc[q.front()] << endl;
      cin >> x >> y;
      x--;
      y--;
      q.pop_front();
    }
    return 0;
  }
  cout << 'L' << endl;
  cin >> x >> y;
  x--;
  y--;
  if (!(x == 0 && y == 0)) {
    swap(voc['L'], voc['R']);
    cout << 'R' << endl;
    cin >> x >> y;
    x--;
    y--;
  }
  int s = 0;
  while (a[1][s] == '*') {
    s++;
    cout << voc['R'] << endl;
    cin >> x >> y;
    x--;
    y--;
  }
  cout << 'D' << endl;
  int nx, ny;
  cin >> nx >> ny;
  nx--;
  ny--;
  if (!(x == nx && y == ny)) {
    swap(voc['U'], voc['D']);
    cout << 'U' << endl;
    cin >> x >> y;
    x--;
    y--;
  }
  dfs(x, y);
  while (!q.empty()) {
    cout << voc[q.front()] << endl;
    cin >> x >> y;
    x--;
    y--;
    q.pop_front();
  }
  return 0;
}
