#include <bits/stdc++.h>
using namespace std;
bool debug = true;
template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> ptt) {
  os << ptt.first << "," << ptt.second;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vt) {
  os << "{";
  for (int i = 0; i < vt.size(); i++) {
    os << vt[i] << " ";
  }
  os << "}";
  return os;
}
int n;
int l[7][7], r[7][7], a[7][7], f[7];
int cost;
void dfs(int x, int y, int flow, int cc) {
  if (x == n) {
    cost = max(cost, cc);
    return;
  }
  if (y > n) {
    if (flow == 0) {
      dfs(x + 1, x + 2, f[x + 1], cc);
    }
  } else {
    for (int i = l[x][y]; i <= r[x][y]; i++) {
      if (i > flow) {
        break;
      }
      f[y] += i;
      dfs(x, y + 1, flow - i, cc + i * i + (i == 0 ? 0 : a[x][y]));
      f[y] -= i;
    }
  }
}
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    l[a][b] = c;
    r[a][b] = d;
    ::a[a][b] = e;
  }
  for (int i = 1; i <= 100; i++) {
    cost = -1e9;
    dfs(1, 2, i, 0);
    if (cost >= 0) {
      cout << i << " " << cost;
      return 0;
    }
  }
  cout << "-1 -1";
  return 0;
}
