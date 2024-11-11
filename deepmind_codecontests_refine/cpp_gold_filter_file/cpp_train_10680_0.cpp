#include <bits/stdc++.h>
using namespace std;
char mp[5005][5005];
long long int C[5005][5005];
vector<int> nd[5005];
vector<int> vs;
int cmb[5005];
bool use[5005];
char str[2000005];
string A[5005];
string B[5005];
pair<int, int> pos[5005];
int n;
void init() {
  for (int i = 0; i < 5005; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      if (C[i][j] >= 1000000007) C[i][j] %= 1000000007;
    }
  }
}
int gcd(int x, int y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
void dfs(int v) {
  use[v] = true;
  for (int i = 0; i < n; i++)
    if (!use[i] && mp[v][i] == '1') dfs(i);
  vs.push_back(v);
}
void rdfs(int v, int k) {
  use[v] = true;
  cmb[v] = k;
  nd[k].push_back(v);
  for (int i = 0; i < n; i++)
    if (!use[i] && mp[i][v] == '1') rdfs(i, k);
}
int scc() {
  memset(use, false, sizeof(use));
  for (int i = 0; i < n; i++)
    if (!use[i]) dfs(i);
  memset(use, false, sizeof(use));
  int k = 0;
  for (int i = n - 1; i >= 0; i--)
    if (!use[vs[i]]) rdfs(vs[i], k++);
  return k;
}
int main() {
  init();
  int a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) scanf("%s", &mp[i]);
  for (int i = 0; i < n; i++) {
    int DM;
    scanf("%d %s", &DM, &str);
    A[i] = str;
  }
  int sz = scc();
  int nm = 0;
  for (int i = 0; i < sz; i++) {
    int g = i > 0 ? B[i - 1].size() : 0;
    for (int j = 0; j < nd[i].size(); j++) {
      int v = nd[i][j];
      g = gcd(g, A[v].size());
    }
    for (int j = 0; j < g; j++) B[i] += "0";
    if (i > 0) {
      for (int j = 0; j < B[i - 1].size(); j++) {
        if (B[i - 1][j] == '1') {
          B[i][j % g] = '1';
        }
      }
    }
    for (int j = 0; j < nd[i].size(); j++) {
      int v = nd[i][j];
      for (int k = 0; k < A[v].size(); k++) {
        if (A[v][k] == '1') {
          B[i][k % g] = '1';
        }
      }
    }
    for (int j = 0; j < nd[i].size(); j++) {
      int v = nd[i][j];
      int a = 0, b = 0;
      for (int k = 0; k < A[v].size(); k++) {
        if (A[v][k] == '1') a++;
        if (B[i][k % g] == '1') b++;
      }
      pos[nm++] = pair<int, int>(b, a);
    }
  }
  sort(pos, pos + n);
  priority_queue<int> que;
  long long int ret = 0;
  int cnt = 0;
  a--, b--;
  for (int i = n - 1; i >= 0; i--) {
    pair<int, int> p = pos[i];
    while (!que.empty() && que.top() > p.first) {
      cnt++;
      que.pop();
    }
    for (int j = 0; j <= min(b, cnt); j++) {
      int zb = b - j;
      if (zb <= que.size() && b + (cnt - j) <= a) {
        long long int way = C[que.size()][zb] * C[cnt][j] % 1000000007;
        ret += way;
        if (ret >= 1000000007) ret -= 1000000007;
      }
    }
    que.push(p.second);
  }
  printf("%lld\n", ret);
  return 0;
}
