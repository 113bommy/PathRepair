#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MM = 205;
int N, M, a[MM], b[MM], result[MM][MM];
set<int> pos[2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> a[i];
  for (int i = 1; i <= M; ++i) cin >> b[i];
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      result[i][j] = a[i] & b[j];
    }
  }
  pos[0].insert(a[0]);
  int cur = 0, nxt = 0;
  for (int i = 1; i <= N; ++i) {
    nxt = !cur;
    pos[nxt].clear();
    for (int x : pos[cur]) {
      for (int j = 1; j <= M; ++j) {
        pos[nxt].insert(x | result[i][j]);
      }
    }
    cur = nxt;
  }
  cout << *pos[cur].begin() << "\n";
}
