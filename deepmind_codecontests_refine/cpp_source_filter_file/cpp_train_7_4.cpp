#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, k, indi[(int)5e5 + 110];
set<int> gra[(int)5e5 + 110];
int arr[(int)5e5 + 110], bra[(int)5e5 + 110], result[(int)5e5 + 110],
    donno[(int)5e5 + 110];
int track;
void funck(int u) {
  queue<int> pq;
  pq.push(u);
  while (!pq.empty()) {
    int v = pq.front();
    pq.pop();
    if (donno[v]) continue;
    donno[v] = 1;
    track--;
    for (int go : gra[u]) {
      gra[go].erase(v);
      if (--indi[go] < k) pq.push(go);
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    gra[u].insert(v);
    gra[v].insert(u);
    indi[u]++;
    indi[v]++;
    arr[i] = u;
    bra[i] = v;
  }
  track = n;
  for (int i = 0; i < n; ++i) {
    if (donno[i] == 0 and indi[i] < k) {
      funck(i);
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    result[i] = track;
    if (donno[arr[i]] == 0 and donno[bra[i]] == 0) {
      indi[arr[i]]--;
      indi[bra[i]]--;
      gra[arr[i]].erase(bra[i]);
      gra[bra[i]].erase(arr[i]);
      if (indi[arr[i]] < k) funck(arr[i]);
      if (indi[bra[i]] < k) funck(bra[i]);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << result[i] << endl;
  }
  return 0;
}
