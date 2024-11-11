#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 5 + 10;
long long matris[MAXN][MAXN], masmin[MAXN][MAXN];
long long ans[MAXN], arr[MAXN];
vector<int> graph[MAXN];
vector<int> vec;
long long MINIM(int v) {
  long long ans = 0;
  for (int i = 0; i < graph[v].size(); i++) {
    for (int j = 0; j < graph[v].size(); j++) {
      masmin[v][graph[v][i]] =
          min(masmin[v][graph[v][i]],
              matris[v][graph[v][j]] + masmin[graph[v][j]][graph[v][i]]);
      masmin[graph[v][i]][v] =
          min(masmin[graph[v][i]][v],
              matris[graph[v][j]][v] + masmin[graph[v][i]][graph[v][j]]);
    }
    ans += masmin[v][graph[v][i]] + masmin[graph[v][i]][v];
  }
  for (int i = 0; i < graph[v].size(); i++) {
    for (int j = 0; j < graph[v].size(); j++) {
      masmin[graph[v][i]][graph[v][j]] =
          min(masmin[graph[v][i]][graph[v][j]],
              masmin[graph[v][i]][v] + masmin[v][graph[v][j]]);
      ans += masmin[graph[v][i]][graph[v][j]];
    }
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> matris[i][j];
      masmin[i][j] = matris[i][j];
    }
  for (int i = 0; i < n; i++) {
    masmin[i][i] = 0;
    cin >> arr[i];
    arr[i]--;
  }
  for (int j = n - 1; j >= 0; j--) {
    for (int i = 0; i < vec.size(); i++) {
      graph[vec[i]].push_back(arr[j]);
      graph[arr[j]].push_back(vec[i]);
    }
    ans[j] = MINIM(arr[j]);
    vec.push_back(arr[j]);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
