#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t N;
  cin >> N;
  int res = 0;
  if (N == 2) {
    cout << 1 << '\n';
    return 0;
  }
  for (int64_t i = 2; i * i < N + 1; i++) {
    if ((N - 1) % i == 0) {
      res += (i * i == N - 1 ? 1 : 2);
    }
    if (N % i == 0) {
      int64_t x = N;
      while (x % i == 0) {
        x /= i;
      }
      if (x % i == 1) res++;
    }
  }
  cout << res + 2 << '\n';
  return 0;
}
