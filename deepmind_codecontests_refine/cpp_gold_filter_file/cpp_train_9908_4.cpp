#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  const long long inf = 1e18;
  cin >> n >> m >> k;
  vector<vector<long long> > v(m, vector<long long>(3));
  for (int i = 0; i < (m); i++) {
    cin >> v[i][1] >> v[i][2] >> v[i][0];
    v[i][1]--;
    v[i][2]--;
  }
  vector<int> idx(n, -1);
  int ind = 0;
  vector<vector<long long> > M(805, vector<long long>(805, inf));
  sort(v.begin(), v.end());
  for (int i = 0; i < (min(m, k)); i++) {
    int a = v[i][1];
    int b = v[i][2];
    if (idx[a] < 0) idx[a] = ind++;
    if (idx[b] < 0) idx[b] = ind++;
    a = idx[a];
    b = idx[b];
    M[a][b] = M[b][a] = v[i][0];
  }
  for (int i = 0; i < (ind); i++) M[i][i] = 0;
  for (int k = 0; k < (ind); k++) {
    for (int i = 0; i < (ind); i++) {
      for (int j = 0; j < (ind); j++) {
        M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
      }
    }
  }
  vector<long long> ans;
  for (int i = 0; i < (ind); i++) {
    for (int j = i + 1; j < (ind); j++) {
      ans.push_back(M[i][j]);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans[k - 1] << endl;
}
