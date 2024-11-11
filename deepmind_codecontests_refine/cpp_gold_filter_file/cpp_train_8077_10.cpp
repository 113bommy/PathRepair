#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
long long int N, M, K, H, W, L, R;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= 100000; i += 2) {
    N -= i;
    M -= i + 1;
    if (N < 0) {
      cout << "Vladik\n";
      return 0;
    }
    if (M < 0) {
      cout << "Valera\n";
      return 0;
    }
  }
  return 0;
}
