#include <bits/stdc++.h>
using namespace std;
template <class T>
void max_swap(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void min_swap(T& a, const T& b) {
  a = min(a, b);
}
template <class T>
void uniq(vector<T>& c) {
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
}
template <class T>
string to_s(const T& a) {
  ostringstream os;
  os << a;
  return os.str();
}
template <class T>
T to_T(const string& s) {
  istringstream is(s);
  T res;
  is >> res;
  return res;
}
template <class T, class U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << "( " << p.first << ", " << p.second << " )";
  return os;
}
template <class T>
void print(T a, int n, const string& deli = " ", int br = 1) {
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i + 1 != n) cout << deli;
  }
  while (br--) cout << endl;
}
template <class T>
void print(const T& c, const string& deli = " ", int br = 1) {
  for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it) {
    cout << *it;
    if (++it != c.end()) cout << deli;
    --it;
  }
  while (br--) cout << endl;
}
template <class T>
void print2d(T a, int w, int h, int width = -1, int br = 1) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (width != -1) cout.width(width);
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  while (br--) cout << endl;
}
template <class T>
void input(T& a, int n) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
template <class T>
void input(T* a, int n) {
  for (int i = 0; i < n; ++i) cin >> a[i];
}
void fast_io() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}
bool valid(int x, int y, int w, int h) {
  return 0 <= x && x < w && 0 <= y && y < h;
}
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const double PI = acos(-1.0);
const int mod = ((long long)(1e9)) + 7;
int index(const vector<long long>& v, long long p) {
  return lower_bound((v).begin(), (v).end(), p) - v.begin();
}
int main() {
  int n;
  cin >> n;
  long long d[1111];
  int dir[1111];
  for (int i = 0; i < (int)(n); ++i) {
    const char* ddd = "URDL";
    char dd;
    cin >> dd >> d[i];
    dir[i] = strchr(ddd, dd) - ddd;
  }
  vector<long long> cx, cy;
  cx.push_back(0);
  cy.push_back(0);
  for (int i = 0; i < (int)(n); ++i) {
    cx.push_back(cx.back() + dx[dir[i]] * d[i]);
    cy.push_back(cy.back() + dy[dir[i]] * d[i]);
  }
  for (int i = 0; i < (int)(n + 1); ++i) {
    cx.push_back(cx[i] + 1);
    cy.push_back(cy[i] + 1);
  }
  const long long INF = ((long long)(1e16));
  cx.push_back(-INF);
  cx.push_back(INF);
  cy.push_back(-INF);
  cy.push_back(INF);
  uniq(cx);
  uniq(cy);
  static bool sprayed[3333][3333];
  long long rx = 0, ry = 0;
  int x = index(cx, 0), y = index(cy, 0);
  sprayed[y][x] = true;
  for (int i = 0; i < (int)(n); ++i) {
    rx += dx[dir[i]] * d[i];
    ry += dy[dir[i]] * d[i];
    while (cx[x] != rx || cy[y] != ry) {
      x += dx[dir[i]];
      y += dy[dir[i]];
      sprayed[y][x] = true;
    }
  }
  static bool infected[3333][3333];
  int w = cx.size(), h = cy.size();
  queue<pair<int, int> > q;
  infected[0][0] = true;
  q.push(pair<int, int>(0, 0));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < (int)(4); ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (valid(nx, ny, w, h)) {
        if (!sprayed[ny][nx] && !infected[ny][nx]) {
          infected[ny][nx] = true;
          q.push(pair<int, int>(nx, ny));
        }
      }
    }
  }
  long long res = 0;
  for (int y = 1; y < cy.size() - 2; ++y) {
    for (int x = 1; x < cx.size() - 2; ++x) {
      if (!infected[y][x]) {
        long long h = !infected[y + 1][x] ? cy[y + 1] - cy[y] : 1;
        long long w = !infected[y][x + 1] ? cx[x + 1] - cx[x] : 1;
        res += h * w;
      }
    }
  }
  cout << res << endl;
}
