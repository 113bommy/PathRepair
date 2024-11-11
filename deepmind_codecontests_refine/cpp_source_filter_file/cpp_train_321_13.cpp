#include <bits/stdc++.h>
using namespace std;
int n, k1, k2, u[1001], q[1001], start, x, y;
vector<int> vec[1001];
int a, b;
int f(int v, int pr) {
  if (u[v] == 1) {
    return v;
  }
  int yy = 0;
  for (int i = 0; i < vec[v].size(); i++) {
    if (vec[v][i] != pr) {
      yy = max(yy, f(vec[v][i], v));
    }
  }
  return yy;
}
pair<int, int> get(int v, int pr) {
  pair<int, int> ans = make_pair(0, 0);
  if (v == y) {
    ans.first = 1;
    return ans;
  }
  if (u[v] == 1) {
    ans.second = v;
  }
  pair<int, int> yy = make_pair(0, 0);
  for (int i = 0; i < vec[v].size(); i++) {
    if (vec[v][i] != pr) {
      yy = max(yy, get(vec[v][i], v));
    }
  }
  if (yy.first != 0) {
    ans.first = 1;
  }
  if (yy.first != 0 && yy.second != 0) {
    ans = yy;
  }
  return ans;
}
void solve() {
  for (int i = 0; i < 1001; i++) {
    vec[i].clear();
    u[i] = 0;
    q[i] = 0;
  }
  cin >> n;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  cin >> k1;
  for (int i = 0; i < k1; i++) {
    scanf("%d", &x);
    u[x] = 1;
  }
  cin >> k2;
  for (int i = 0; i < k2; i++) {
    scanf("%d", &x);
    q[x] = 1;
  }
  start = f(1, -1);
  cout << "A " << start << endl;
  fflush(stdout);
  cin >> y;
  if (q[y] == 1) {
    cout << "C " << start << endl;
    fflush(stdout);
    return;
  } else {
    cout << "B " << x << endl;
    fflush(stdout);
    cin >> y;
    if (u[y] == 1) {
      cout << "C " << y << endl;
      fflush(stdout);
      return;
    } else {
      pair<int, int> ppp = get(1, -1);
      if (ppp.first == 0) {
        cout << "C -1" << endl;
        fflush(stdout);
        return;
      }
      start = ppp.second;
      cout << "A " << start << endl;
      fflush(stdout);
      cin >> y;
      if (q[y] == 1) {
        cout << "C " << start << endl;
        fflush(stdout);
        return;
      } else {
        cout << "C -1" << endl;
        fflush(stdout);
        return;
      }
    }
  }
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
