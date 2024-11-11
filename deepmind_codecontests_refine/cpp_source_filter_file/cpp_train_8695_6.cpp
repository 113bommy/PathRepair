#include <bits/stdc++.h>
using namespace std;
int n, m;
long long K;
int a[1003][1003];
struct hdm {
  int u, v, h;
  hdm(){};
  hdm(int u, int v, int h) : u(u), v(v), h(h){};
  bool operator<(const hdm &a) const { return h < a.h; }
};
vector<hdm> V;
int cur;
int lab[1003 * 1003];
int X[] = {-1, 0, 0, 1};
int Y[] = {0, -1, 1, 0};
bool d[1003][1003];
int getVer(int i, int j) { return (i - 1) * m + j; }
int getRoot(int u) {
  if (lab[u] < 0) return u;
  return lab[u] = getRoot(lab[u]);
}
void unionUV(int u, int v) {
  u = getRoot(u), v = getRoot(v);
  if (lab[u] > lab[v]) swap(u, v);
  lab[u] += lab[v], lab[v] = u;
}
bool canC(int u, int v, int must) {
  return (1 <= u) && (u <= n) && (1 <= v) && (v <= m) && (a[u][v] >= must);
}
void DFS(int u, int v, int must) {
  if (cur < 0) return;
  cur--;
  d[u][v] = 1;
  for (int k = 0; k < 4; k++) {
    int nu = u + X[k];
    int nv = v + Y[k];
    if (canC(nu, nv, must) && (d[nu][nv] == 0)) DFS(nu, nv, must);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> K;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      V.push_back(hdm(i, j, a[i][j]));
    }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  memset(lab, -1, sizeof lab);
  for (int id = 0; id < V.size(); id++) {
    int height = V[id].h;
    int u = V[id].u, v = V[id].v;
    int r1, r2;
    for (int k = 0; k < 4; k++) {
      int nu = u + X[k], nv = v + Y[k];
      if (canC(nu, nv, height)) {
        r1 = getRoot(getVer(u, v));
        r2 = getRoot(getVer(nu, nv));
        if (r1 != r2) {
          unionUV(r1, r2);
        }
      }
    }
    r1 = getRoot(getVer(u, v));
    long long sm = 1LL * height * (-lab[r1]);
    if ((K % height != 0) || (sm < K)) continue;
    cout << "YES" << '\n';
    cur = K / height;
    DFS(u, v, height);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cout << height * d[i][j] << ' ';
      cout << '\n';
    }
    return 0;
  }
  cout << "NO";
  return 0;
}
