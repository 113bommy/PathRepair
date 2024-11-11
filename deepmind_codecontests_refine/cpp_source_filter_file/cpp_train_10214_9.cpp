#include <bits/stdc++.h>
using namespace std;
int p[101];
int n;
int FIND(int x) {
  if (x != p[x]) p[x] = FIND(p[x]);
  return p[x];
}
void join(int x, int y) {
  int px = FIND(x);
  int py = FIND(y);
  if (px != py) p[py] = px;
}
int func(int x) {
  for (int i = 1; i <= n; i++) {
    if (p[i] != x) return false;
  }
  return true;
}
int main() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    join(x, y);
  }
  bool l = false;
  for (int i = 1; i <= n; i++) {
    p[i] = FIND(i);
  }
  if (n < 3 || (m < n && !func(p[1])))
    cout << "NO" << endl;
  else
    cout << "FHTAGN!" << endl;
  return 0;
}
