#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const int MAXN = 220 * 1000;
const int MAXLOG = 20;
int n, m;
vector<int> adj[MAXN];
int p[MAXLOG][MAXN];
int e1[MAXN], e2[MAXN], w[MAXN];
int time_in[MAXN], time_out[MAXN];
vector<int> ind[MAXN];
long long ans[MAXN];
long long fen1[MAXN], fen2[MAXN];
long long Get(long long* fen, int pos) {
  long long res = 0;
  for (int x = pos; x >= 0; x = (x & (x + 1)) - 1) {
    res += fen[x];
  }
  return res;
}
void Add(long long* fen, int pos, long long val) {
  for (int x = pos; x < n; x = (x | (x + 1))) {
    fen[pos] += val;
  }
}
long long GetVert(long long* fen, int v) { return Get(fen, time_in[v]); }
void AddSubtree(long long* fen, int v, long long val) {
  Add(fen, time_in[v], val);
  Add(fen, time_out[v], -val);
}
int time_cur = 0;
void DFSTime(int v) {
  time_in[v] = time_cur;
  ++time_cur;
  for (int i = 0; i < ((int)(adj[v]).size()); ++i) {
    DFSTime(adj[v][i]);
  }
  time_out[v] = time_cur;
}
bool IsFather(int v1, int v2) {
  return time_in[v2] >= time_in[v1] && time_in[v2] < time_out[v1];
}
int LCA(int v1, int v2) {
  if (IsFather(v1, v2)) {
    return v1;
  }
  if (IsFather(v2, v1)) {
    return v2;
  }
  for (int i = MAXLOG - 1; i >= 0; --i) {
    if (!IsFather(p[i][v1], v2)) {
      v1 = p[i][v1];
    }
  }
  return p[0][v1];
}
void DFSAns(int v) {
  for (int i = 0; i < ((int)(adj[v]).size()); ++i) {
    DFSAns(adj[v][i]);
  }
  long long sum_ch = 0;
  for (int i = 0; i < ((int)(adj[v]).size()); ++i) {
    sum_ch += ans[adj[v][i]];
  }
  ans[v] = sum_ch;
  for (int i = 0; i < ((int)(ind[v]).size()); ++i) {
    int v1 = e1[ind[v][i]];
    int v2 = e2[ind[v][i]];
    int cur_w = w[ind[v][i]];
    long long cur_ans = 0;
    if (v1 != v && v2 != v) {
      cur_ans = GetVert(fen2, v1) + GetVert(fen2, v2) + sum_ch -
                GetVert(fen1, v1) - GetVert(fen1, v2);
    } else {
      int v3 = v1 + v2 - v;
      cur_ans = GetVert(fen2, v3) + sum_ch - GetVert(fen1, v3);
    }
    ans[v] = max(ans[v], cur_ans + cur_w);
  }
  AddSubtree(fen1, v, ans[v]);
  AddSubtree(fen2, v, sum_ch);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  p[0][0] = 0;
  for (int i = 1; i < n; ++i) {
    cin >> p[0][i];
    --p[0][i];
    adj[p[0][i]].push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    cin >> e1[i] >> e2[i] >> w[i];
    --e1[i], --e2[i];
  }
  DFSTime(0);
  for (int i = 1; i < MAXLOG; ++i) {
    for (int j = 0; j < n; ++j) {
      p[i][j] = p[i - 1][p[i - 1][j]];
    }
  }
  for (int i = 0; i < m; ++i) {
    int lca = LCA(e1[i], e2[i]);
    ind[lca].push_back(i);
  }
  DFSAns(0);
  cout << ans[0] << "\n";
  return 0;
}
