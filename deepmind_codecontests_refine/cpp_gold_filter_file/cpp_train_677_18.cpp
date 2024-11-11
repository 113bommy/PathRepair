#include <bits/stdc++.h>
using namespace std;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  s << "[";
  for (int i = 0; i < ((int)(t.size())) - 1; i++) s << t[i] << ", ";
  if (((int)(t.size())) > 0) s << t[((int)(t.size())) - 1];
  s << "]";
  return s;
}
const int MOD = 1e9 + 7;
template <typename T>
inline T gcD(T a, T b) {
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    b ^= a;
    a ^= b;
    b ^= a;
  };
  return a;
}
template <typename T>
inline T pow_mod(T a, T b) {
  T res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
const int MAXN = 3e3 + 10;
int dist[MAXN][MAXN], dist2[MAXN][MAXN];
pair<int, int> far[MAXN][3], far2[MAXN][3];
vector<pair<int, bool> > graph[MAXN];
int N, M;
void bfs(int start, bool reverse, int d[], pair<int, int> f[]) {
  queue<int> Q;
  Q.push(start);
  for (int i = 1; i < N + 1; i++) d[i] = (int)1e9;
  d[start] = 0;
  while (!Q.empty()) {
    int ver = Q.front();
    Q.pop();
    for (__typeof((graph[ver]).begin()) v = (graph[ver]).begin();
         v != (graph[ver]).end(); ++v) {
      if (v->second == reverse) {
        if (d[v->first] > d[ver] + 1) {
          d[v->first] = d[ver] + 1;
          Q.push(v->first);
        }
      }
    }
  }
  f[0] = f[1] = f[2] = {-1, -1};
  for (int i = 1; i < N + 1; i++) {
    if (d[i] == (int)1e9 || i == start) continue;
    if (d[i] > f[0].first) {
      swap(f[1], f[2]);
      swap(f[0], f[1]);
      f[0] = {d[i], i};
    } else if (d[i] > f[1].first) {
      swap(f[1], f[2]);
      f[1] = {d[i], i};
    } else if (d[i] > f[2].first)
      f[2] = {d[i], i};
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back({y, false});
    graph[y].push_back({x, true});
  }
  for (int i = 1; i < N + 1; i++) {
    bfs(i, false, dist[i], far[i]);
    bfs(i, true, dist2[i], far2[i]);
  }
  int dsum = 0;
  int ansA, ansB, ansC, ansD;
  for (int i = 1; i < N + 1; i++)
    for (int j = 1; j < N + 1; j++)
      if (i != j && dist[i][j] != (int)1e9) {
        int b = i, c = j;
        for (int k = 0; k < 3; k++)
          for (int l = 0; l < 3; l++)
            if (far2[b][k].first != -1 && far[c][l].first != -1) {
              int a = far2[b][k].second;
              int d = far[c][l].second;
              if (a != d && a != c && d != b) {
                int sum = dist[a][b] + dist[b][c] + dist[c][d];
                if (sum > dsum) {
                  dsum = sum;
                  ansA = a;
                  ansB = b;
                  ansC = c;
                  ansD = d;
                }
              }
            }
      }
  cout << ansA << ' ' << ansB << ' ' << ansC << ' ' << ansD << endl;
  return 0;
}
