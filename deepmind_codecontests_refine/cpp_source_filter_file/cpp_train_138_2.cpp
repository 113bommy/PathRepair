#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int dx[] = {-1, -1, -1, 0, 1, 1, 1, -1}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
  int x1, x2, y1, y2, n, a, b, r;
  cin >> x1 >> y1 >> x2 >> y2 >> n;
  map<pair<int, int>, int> h;
  for (long long i = 0; i < n; i++) {
    cin >> r >> a >> b;
    for (int j = a; j <= b; j++) h[make_pair(r, j)] = -1;
  }
  h[make_pair(x1, y1)] = 0;
  queue<pair<int, int> > q;
  q.push(make_pair(x1, y1));
  while (!q.empty()) {
    pair<int, int> x = q.front();
    q.pop();
    if (x.first == x2 && x.second == y2) break;
    for (int i = 0; i < 8; i++) {
      pair<int, int> v = make_pair(x.first + dx[i], x.second + dy[i]);
      if (h[v] == -1) {
        h[v] = h[x] + 1;
        q.push(v);
      }
    }
  }
  cout << h[make_pair(x2, y2)];
}
