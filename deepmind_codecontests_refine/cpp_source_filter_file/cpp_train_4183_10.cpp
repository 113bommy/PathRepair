#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18 + 1;
const long long int MOD = 1000000007L;
clock_t time_p = clock();
void timer() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
template <typename Arg1>
ostream& operator<<(ostream& out, const vector<Arg1>& a) {
  out << "[ ";
  for (const auto& x : a) out << x << " ";
  return out << "]";
}
long long int s, b;
bool bpm(bool bpGraph[1000][1000], int u, bool seen[], int matchR[]) {
  for (int v = 0; v < b; v++) {
    if (bpGraph[u][v] && !seen[v]) {
      seen[v] = true;
      if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR)) {
        matchR[v] = u;
        return true;
      }
    }
  }
  return false;
}
int maxBPM(bool bpGraph[1000][1000]) {
  int matchR[b];
  memset(matchR, -1, sizeof(matchR));
  int result = 0;
  for (int u = 0; u < s; u++) {
    bool seen[b];
    memset(seen, 0, sizeof(seen));
    if (bpm(bpGraph, u, seen, matchR)) result++;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  long long int adj[n][n];
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      if (i == j) {
        adj[i][j] = 0;
        continue;
      }
      adj[i][j] = INF;
    }
  }
  for (int i = 0; i < (m); ++i) {
    long long int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (u == v) {
      continue;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
  }
  long long int k, h;
  cin >> s >> b >> k >> h;
  vector<long long int> xs(s), as(s), fs(s);
  for (int i = 0; i < (s); ++i) {
    cin >> xs[i] >> as[i] >> fs[i];
    xs[i]--;
  }
  vector<long long int> xb(b), db(b);
  for (int i = 0; i < (b); ++i) {
    cin >> xb[i] >> db[i];
    xb[i]--;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
  bool adj1[1000][1000];
  for (int i = 0; i < (1000); ++i) {
    for (int j = 0; j < (1000); ++j) {
      adj1[i][j] = false;
    }
  }
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < b; j++) {
      if (adj[xs[i]][xb[j]] <= fs[i] && as[i] >= db[j]) {
        adj1[i][j] = true;
      }
    }
  }
  long long int val = maxBPM(adj1);
  long long int temp = 0;
  for (int i = 0; i < (s); ++i) {
    bool found = false;
    for (int j = 0; j < (b); ++j) {
      if (adj1[i][j]) {
        found = true;
        break;
      }
    }
    if (found) {
      temp++;
    }
  }
  long long int ans = min(val * k, temp * h);
  cout << ans << endl;
  timer();
  return 0;
}
