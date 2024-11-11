#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  int a[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }
  long long l = 0, r = 1e9 + 1;
  int i1 = 1, i2 = 1;
  while (r - l > 1) {
    long long m = (l + r) >> 1;
    bool check = false;
    vector<int> vis((1 << M), 0);
    for (int i = 0; i < N; i++) {
      int bit = 0;
      for (int j = 0; j < M; j++) {
        if (a[i][j] >= m) {
          bit += (1 << j);
        }
      }
      vis[bit] = i + 1;
    }
    for (int i = 0; i < (1 << M); i++) {
      for (int j = 0; j < (1 << M); j++) {
        if (vis[i] && vis[j] && ((i | j) + 1) == (1 << M)) {
          i1 = vis[i], i2 = vis[j];
          check = true;
          break;
        }
      }
    }
    if (check)
      l = m;
    else
      r = m;
  }
  cout << i1 << " " << i2;
}
