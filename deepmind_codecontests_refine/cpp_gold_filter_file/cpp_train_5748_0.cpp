#include <bits/stdc++.h>
using namespace std;
using cat = long long;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int N, Q;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> Q;
  vector<vector<cat> > max_sum(N + 1,
                               vector<cat>(N + 1, -1234567890123456789LL));
  max_sum[N][0] = 0;
  vector<vector<int> > seq(N + 1);
  for (int i = N - 1; i >= 0; i--) {
    max_sum[i] = max_sum[i + 1];
    for (int j = 0; j < N; j++)
      max_sum[i][j + 1] = max(max_sum[i][j + 1], max_sum[i + 1][j] + A[i]);
  }
  for (int l = 1; l <= N; l++) {
    int cur = 0;
    for (int i = 0; i < l; i++) {
      cat m = max_sum[cur][l - i];
      int v = 1234567890123456789LL, pos = -1;
      for (int j = N - 1; j >= cur; j--)
        if (m == max_sum[j + 1][l - i - 1] + A[j])
          if (A[j] <= v) v = A[j], pos = j;
      seq[l].push_back(v);
      cur = pos + 1;
    }
  }
  for (int q = 0; q < Q; q++) {
    int K, id;
    cin >> K >> id;
    id--;
    cout << seq[K][id] << "\n";
  }
  return 0;
}
