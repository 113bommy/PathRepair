#include <bits/stdc++.h>
using namespace std;
const int E = 2e5 + 9;
char a[2][E];
int b[2][E];
int d[2][E];
int n, k;
pair<int, int> m[3] = {make_pair(0, 1), make_pair(0, -1), make_pair(1, k)};
bool BFS() {
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  b[0][0] = true;
  while (q.size() > 0) {
    pair<int, int> p = q.front();
    int l = p.first, x = p.second;
    for (int i = 0; i < 3; i++) {
      int newl = (l + m[i].first) % 2, newx = x + m[i].second;
      if (newx >= 0 and !b[newl][newx] and a[newl][newx] != 'X') {
        b[newl][newx] = true;
        d[newl][newx] = d[l][x] + 1;
        if (d[newl][newx] > newx) {
          continue;
        }
        q.push(make_pair(newl, newx));
        if (newx >= n) {
          return true;
        }
      }
    }
    q.pop();
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  m[2] = make_pair(1, k);
  for (int i = 0; i < n; i++) {
    cin >> a[0][i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[1][i];
  }
  if (BFS()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
