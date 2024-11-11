#include <bits/stdc++.h>
using namespace std;
void fileIO() {}
int n, u, v, numOfEdge[(int)1e5 + 5], ans[(int)1e5 + 5];
vector<pair<int, int>> edge;
void bigBang() {
  cin >> n;
  edge.resize(n + 1);
  for (size_t i = (1); i < (n); ++i) {
    cin >> u >> v;
    edge[i] = {u, v};
    numOfEdge[u]++;
    numOfEdge[v]++;
  }
  memset(ans, -1, sizeof(ans));
  int label = n - 2;
  for (size_t i = (1); i < (n); ++i)
    if (numOfEdge[edge[i].first] > 1 && numOfEdge[edge[i].second] > 1)
      ans[i] = label--;
  for (size_t i = (1); i < (n); ++i)
    if (ans[i] == -1) ans[i] = label--;
  for (size_t i = (1); i < (n); ++i) cout << ans[i] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  fileIO();
  bigBang();
  return 0;
}
