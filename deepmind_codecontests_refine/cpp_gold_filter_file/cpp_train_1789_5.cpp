#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int MAX = 1004, mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int K;
vector<int> pr[MAX];
void minn(int &a, int b) {
  if (b < a) a = b;
}
void maxx(int &a, int b) {
  if (b > a) a = b;
}
int sz[MAX];
bitset<MAX> B[MAX];
int n, need, want, sp, num;
bool tt = 0;
bool ok[MAX];
void DFS(int v, int trc) {
  sz[v] = 1;
  int pre = 0;
  for (int u : pr[v])
    if (u != trc) {
      DFS(u, v);
      if (tt == 1) return;
      sz[v] += sz[u];
    }
  for (int u : pr[v])
    if (u != trc) {
      B[u] = B[pre] | (B[pre] << sz[u]);
      pre = u;
    }
  reverse(pr[v].begin(), pr[v].end());
  int an = 0;
  for (int i = n - need; i >= need; i--)
    if (B[pre][i]) {
      an = i;
      break;
    }
  if (an) {
    sp = v;
    num = an;
    for (int u : pr[v])
      if (u != trc) {
        if (!B[u][an]) {
          an -= sz[pre];
          ok[pre] = 1;
        }
        pre = u;
      }
    if (an) {
      ok[pre] = 1;
    }
    tt = 1;
  }
}
int tim;
int in[MAX];
void DFS1(int v, int trc) {
  in[v] = ++tim;
  cout << v << ' ' << trc << ' ' << tim - in[trc] << '\n';
  for (int u : pr[v])
    if (u != trc) DFS1(u, v);
}
void DFS2(int v, int trc) {
  in[v] = (tim += num);
  cout << v << ' ' << trc << ' ' << tim - in[trc] << '\n';
  for (int u : pr[v])
    if (u != trc) DFS2(u, v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  want = (n * n * 2) / 9;
  int b = 1, e = n / 2;
  while (b <= e) {
    int mi = b + e >> 1;
    if (mi * (n - mi) >= want) {
      need = mi;
      e = mi - 1;
    } else
      b = mi + 1;
  }
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    pr[x].push_back(y);
    pr[y].push_back(x);
  }
  B[0][0] = 1;
  DFS(1, 0);
  for (int u : pr[sp])
    if (ok[u]) {
      DFS1(u, sp);
    }
  tim = 0;
  for (int u : pr[sp])
    if (!ok[u]) {
      DFS2(u, sp);
    }
}
