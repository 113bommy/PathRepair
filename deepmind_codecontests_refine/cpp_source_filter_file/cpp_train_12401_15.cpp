#include <bits/stdc++.h>
using namespace std;
vector<int> V[500001];
int main() {
  ios::sync_with_stdio(false);
  int n, c, M, s;
  cin >> n >> c;
  int a[n], S[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != c) {
      V[a[i]].push_back(i);
    }
    if (i == 0) {
      if (a[i] == c) {
        S[i] = 1;
      } else {
        S[i] = 0;
      }
    } else {
      S[i] = S[i - 1];
      if (a[i] == c) {
        S[i]++;
      }
    }
  }
  M = S[n - 1];
  for (int i = 0; i <= 500000; i++) {
    if (V[i].size() > 0) {
      s = 0;
      for (int y = 0; y < V[i].size(); y++) {
        if (y - s + 1 - (S[V[i][y]] - S[V[i][s]]) < 0) {
          s = y;
        }
        M = max(M, S[n - 1] + y - s + 1 - (S[V[i][y]] - S[V[i][s]]));
      }
    }
  }
  cout << M;
  return 0;
}
