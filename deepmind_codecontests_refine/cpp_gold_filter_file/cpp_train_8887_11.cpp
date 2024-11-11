#include <bits/stdc++.h>
using namespace std;
int x[1000], y[1000];
int n, m;
int rod[1000];
int used[1000];
int res[1000];
int calc(int ind) {
  int pind = (ind - 1 + n) % n;
  int nind = (ind + 1) % n;
  int dx = abs(x[ind] - x[pind]) + abs(x[nind] - x[ind]);
  int dy = abs(y[ind] - y[pind]) + abs(y[nind] - y[ind]);
  return dx + dy;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < m; i++) cin >> rod[i];
  memset(res, -1, sizeof(res));
  int curr;
  bool sol;
  curr = 0;
  sol = true;
  do {
    int val = calc(curr);
    bool ok = false;
    for (int i = 0; i < m; i++) {
      if (used[i] == 1) continue;
      if (rod[i] == val) {
        ok = true;
        used[i] = 1;
        res[curr] = i + 1;
        break;
      }
    }
    if (!ok) {
      sol = false;
      break;
    }
    curr = (curr + 2) % n;
  } while (curr != 0);
  if (sol) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << res[i];
    }
    cout << endl;
    return 0;
  }
  memset(res, -1, sizeof(res));
  curr = 1;
  sol = true;
  do {
    int val = calc(curr);
    bool ok = false;
    for (int i = 0; i < m; i++) {
      if (used[i] == 2) continue;
      if (rod[i] == val) {
        ok = true;
        used[i] = 2;
        res[curr] = i + 1;
        break;
      }
    }
    if (!ok) {
      sol = false;
      break;
    }
    curr = (curr + 2) % n;
  } while (curr != 1);
  if (sol) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << res[i];
    }
    cout << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
