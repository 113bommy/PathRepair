#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
int N, M;
int arr1[mxN + 5];
vector<int> arr2[mxN + 5];
int ans1[mxN + 5];
vector<pair<int, int> > v;
vector<int> adj[2][mxN + 5];
vector<int> starts[2];
bool ok = true;
void dfs(int u, int c) {
  ans1[u] = c;
  for (int v : adj[2 - c][u]) {
    if (ans1[v] != 0) {
      if (ans1[v] == 3 - c) {
        ok = false;
        return;
      }
      continue;
    }
    dfs(v, c);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> arr1[i];
    for (int j = 0, x; j < arr1[i]; j++) {
      cin >> x;
      arr2[i].push_back(x);
    }
  }
  for (int i = 1; i < N; i++) {
    int asz = arr1[i], bsz = arr1[i + 1];
    bool ok = false;
    for (int j = 0; j < min(asz, bsz); j++) {
      int c1 = arr2[i][j], c2 = arr2[i + 1][j];
      if (c1 < c2) {
        ok = true;
        v.push_back({c1, c2});
        adj[0][c1].push_back(c2);
        adj[1][c2].push_back(c1);
      } else if (c1 > c2) {
        ok = true;
        if (ans1[c1] == 2 || ans1[c2] == 1) {
          cout << "No" << endl;
          return 0;
        }
        ans1[c1] = 1;
        ans1[c2] = 2;
        starts[0].push_back(c1);
        starts[1].push_back(c2);
      }
      if (ok) break;
    }
    if (!ok && asz > bsz) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int x : starts[i]) {
      dfs(x, i + 1);
      if (!ok) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= M; i++) {
    if (ans1[i] == 1) {
      ans.push_back(i);
    }
  }
  cout << "Yes" << endl;
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++)
    cout << ans[i] << (i == (int)ans.size() - 1 ? "\n" : " ");
  return 0;
}
