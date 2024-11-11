#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
long long int N, M, K, H, W, L, R;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = N + 1; i < M; i++) {
    bool flag = true;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        flag = false;
      }
    }
    if (flag) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i = 2; i < M; i++) {
    if (N % i == 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
