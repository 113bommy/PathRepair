#include <bits/stdc++.h>
using namespace std;
constexpr long long int MOD = 1000000007;
constexpr double EPS = 1e-8;
long long int N, M, K, H, W, L, R;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  vector<int> v(N);
  for (auto &i : v) cin >> i >> i;
  cin >> K;
  for (int i = 0; i < N; i++) {
    if (v[i] >= K) {
      cout << N - i << endl;
      break;
    }
  }
}
