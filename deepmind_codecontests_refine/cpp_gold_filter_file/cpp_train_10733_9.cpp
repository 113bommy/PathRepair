#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1100;
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
long long N, Q, a, b, c, d, e, M, X, T;
int A[MAXN];
int B[MAXN];
vector<long long> V[MAXN];
int p[MAXN];
void dfs(int x, int pa) {
  p[x] = pa;
  for (auto v : V[x])
    if (v != pa) dfs(v, x);
}
int main() {
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 1; i <= N; ++i) V[i].clear();
    for (int i = 1; i < N; ++i) {
      cin >> a >> b;
      V[a].emplace_back(b);
      V[b].emplace_back(a);
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    cin >> a;
    for (int i = 0; i < a; ++i) {
      cin >> b;
      A[b] = 1;
    }
    int nrt = b;
    cin >> a;
    for (int i = 0; i < a; ++i) {
      cin >> b;
      B[b] = 1;
    }
    int rt = b;
    cout << "B " << rt << endl;
    cin >> c;
    if (A[c]) {
      cout << "C " << c << endl;
      continue;
    }
    dfs(nrt, -1);
    vector<long long> t;
    int cur = c;
    while (cur != nrt) {
      t.emplace_back(cur);
      cur = p[cur];
    }
    t.emplace_back(nrt);
    while ((long long)t.size() > 1 && A[t[(long long)t.size() - 2]])
      t.pop_back();
    int tt = t.back();
    cout << "A " << tt << endl;
    cin >> c;
    if (B[c]) {
      cout << "C " << tt << endl;
    } else {
      cout << "C " << -1 << endl;
    }
  }
}
