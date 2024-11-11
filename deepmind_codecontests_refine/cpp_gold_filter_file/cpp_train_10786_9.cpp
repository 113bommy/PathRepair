#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
vector<int> v1[100000 + 5];
long long dpP[100000 + 5];
long long dpNP[100000 + 5];
long long iloczynP[100000 + 5];
long long iloczynNP[100000 + 5];
long long ans = 0;
long long POW(long long a, long long power) {
  if (a == 0) return 0;
  if (power == 0) return 1;
  long long result = POW(a, power / 2) % M;
  if (power % 2 == 0) return (result * result) % M;
  return ((result * result) % M * a) % M;
}
void dfs(int v, int p) {
  if (v1[v].size() == 1 && p != -1) {
    dpNP[v] = 1;
    dpP[v] = 1;
    return;
  }
  long long parz = 1;
  long long nParz = 1;
  for (int i = 0; i < (int)v1[v].size(); ++i) {
    int w = v1[v][i];
    if (w != p) {
      dfs(w, v);
      parz *= dpP[w];
      nParz *= dpNP[w];
      parz %= M;
      nParz %= M;
    }
  }
  dpP[v] = (parz % M + nParz % M) % M;
  dpNP[v] = (nParz % M + parz % M) % M;
}
void rootShift(int v, int p) {
  long long parz = 1;
  long long nParz = 1;
  for (auto i : v1[v]) {
    parz *= dpP[i];
    nParz *= dpNP[i];
    parz %= M;
    nParz %= M;
  }
  iloczynP[v] = parz % M;
  iloczynNP[v] = nParz % M;
  dpP[v] = (iloczynP[v] + iloczynNP[v]) % M;
  dpNP[v] = dpP[v];
  ans += dpP[v];
  ans %= M;
  for (int i = 0; i < (int)v1[v].size(); ++i) {
    int w = v1[v][i];
    if (w != p) {
      long long temp1 = dpP[v];
      long long temp2 = dpNP[v];
      if (v1[v].size() == 1) {
        dpNP[v] = 1;
        dpP[v] = 1;
      } else {
        dpP[v] = ((iloczynP[v] * POW(dpP[w], M - 2)) % M +
                  (iloczynNP[v] * POW(dpNP[w], M - 2)) % M) %
                 M;
        dpNP[v] = dpP[v];
      }
      rootShift(w, v);
      dpP[v] = temp1;
      dpNP[v] = temp2;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    cin >> a >> b;
    v1[a].push_back(b);
    v1[b].push_back(a);
  }
  dfs(1, -1);
  rootShift(1, -1);
  cout << ans % M;
  return 0;
}
