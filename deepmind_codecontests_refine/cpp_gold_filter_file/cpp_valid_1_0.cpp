#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N, X[6005], Y[6005];
long long cnt[4][4];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    X[i] /= 2;
    Y[i] /= 2;
    cnt[X[i] % 2][Y[i] % 2]++;
  }
  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (abs(X[i] - X[j]) % 2 != 0 || abs(Y[i] - Y[j]) % 2 != 0) continue;
      cnt[X[i] % 2][Y[i] % 2]--;
      cnt[X[j] % 2][Y[j] % 2]--;
      int v1 = X[i] % 2;
      int v2 = Y[i] % 2;
      ans1 += cnt[v1][v2];
      ans2 += cnt[(v1 + 1) % 2][v2] + cnt[v1][(v2 + 1) % 2] +
              cnt[(v1 + 1) % 2][(v2 + 1) % 2];
      cnt[X[i] % 2][Y[i] % 2]++;
      cnt[X[j] % 2][Y[j] % 2]++;
    }
  }
  cout << ans1 / 3 + ans2 << endl;
  return 0;
}
