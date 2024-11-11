#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<int, int> row[5001], col[5001];
  int i, N, M, K, j;
  cin >> N >> M >> K;
  for (i = 1; i <= K; i++) {
    int t, rc, a;
    cin >> t >> rc >> a;
    if (t == 1) {
      row[rc].first = t;
      row[rc].second = a;
    } else {
      col[rc].first = t;
      col[rc].second = a;
    }
  }
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++) {
      pair<int, int> latest = max(row[i], col[j]);
      cout << latest.second << " ";
    }
    cout << endl;
  }
  return 0;
}
