#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int N, M = 1e9 + 7;
  cin >> N;
  vector<long long> sum(60);
  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;
    for (int j = 0; j < 60; j++) sum.at(j) += a >> j & 1;
  }
  long long ans = 0;
  for (int i = 0; i < 60; i++) {
    ans = (ans + (sum.at(i) * (N - sum.at(i)) % M) * (1LL << i % M)) % M;
  }
  cout << ans << "\n";
}
