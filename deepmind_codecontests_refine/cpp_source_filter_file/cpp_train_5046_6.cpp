#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > res;
int Xsum[111111];
int NofV[111111];
int main() {
  int n;
  cin >> n;
  queue<int> Q;
  for (int i = 0; i < n; i++) {
    cin >> NofV[i] >> Xsum[i];
    if (NofV[i] == 1) Q.push(i);
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    int v = Xsum[u];
    if (u == v || NofV[u] == 0) continue;
    Xsum[v] = Xsum[v] ^ u;
    NofV[v]--;
    NofV[u]--;
    res.push_back({u, v});
    if (NofV[v] == 0) {
      Q.push(v);
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
