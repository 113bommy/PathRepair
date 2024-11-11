#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 1e5;
int n, m, c[15];
long long a[15][2 * N + 5], x[N + 5], y[N + 5], x1[N + 5];
vector<int> v[N + 5], v1[N + 5];
struct Node {
  int i, j, last;
  bool operator<(const Node &n2) const {
    return x[i] + y[j] < x[n2.i] + y[n2.j];
  }
};
priority_queue<Node> pq;
set<vector<int> > s;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    c[i] = read();
    for (int j = 1; j <= c[i]; j++) {
      a[i][j] = read();
    }
  }
  int lx = min(c[1], N + 1);
  for (int i = 1; i <= lx; i++) {
    x[i] = a[1][c[1] - i + 1];
    v[i].push_back(c[1] - i + 1);
  }
  int ly;
  int tot = lx;
  for (int i = 2; i <= n; i++) {
    while (!pq.empty()) pq.pop();
    ly = min(c[i], N + 1);
    for (int j = 1; j <= ly; j++) {
      y[j] = a[i][c[i] - j + 1];
    }
    Node start = {1, 1, false};
    pq.push(start);
    tot = 0;
    while (!pq.empty()) {
      Node u = pq.top();
      pq.pop();
      tot++;
      x1[tot] = x[u.i] + y[u.j];
      v1[tot] = v[u.i];
      v1[tot].push_back(c[i] - u.j + 1);
      if (tot >= N + 1) {
        break;
      }
      if (u.j < ly) {
        Node v1 = {u.i, u.j + 1, true};
        pq.push(v1);
      }
      if (u.last == false && u.i < lx) {
        Node v1 = {u.i + 1, u.j, false};
        pq.push(v1);
      }
    }
    lx = tot;
    for (int i = 1; i <= tot; i++) {
      x[i] = x1[i];
      v[i] = v1[i];
    }
  }
  m = read();
  vector<int> vt;
  int t;
  for (int i = 1; i <= m; i++) {
    vt.clear();
    for (int j = 1; j <= n; j++) {
      t = read();
      vt.push_back(t);
    }
    s.insert(vt);
  }
  for (int i = 1; i <= tot; i++) {
    if (s.find(v[i]) == s.end()) {
      for (int j = 0; j <= n - 1; j++) cout << v[i][j] << " ";
      cout << endl;
      break;
    }
  }
  return 0;
}
