#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
};
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
};
template <typename T>
inline string toString(const T& a) {
  ostringstream oss;
  oss << a;
  return oss.str();
};
bool can = true;
vector<vector<int>> G(200010);
vector<int> dir(200010, -1);
void dfs(int v) {
  int id = dir[v] ^ 1;
  for (int nv : G[v]) {
    if (dir[nv] == -1) {
      dir[nv] = id;
      dfs(nv);
    }
    if (dir[nv] != id) {
      can = false;
      return;
    }
  }
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  dir[0] = 1;
  dfs(0);
  if (!can) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for (int i = 0; i < M; i++) {
      if (dir[a[i]] == 0) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << endl;
  }
  return 0;
}
