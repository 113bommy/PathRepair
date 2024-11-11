#include <bits/stdc++.h>
using namespace std;
struct timer {
  time_t start;
  timer() { start = clock(); }
  ~timer() {
    cerr << 1. * (clock() - start) / CLOCKS_PER_SEC << " secs" << endl;
  }
};
long long n, x;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> x;
  long long N = n + 1;
  for (int i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      cout << -1;
      return 0;
    }
  }
  for (int i = x - 1; i >= 1; i--)
    if (i % N) {
      long long x = 1;
      for (int j = 0; j < (N - 2); j++) {
        x = x * i % N;
        if (x == 1) goto fail;
      }
      cout << i;
      return 0;
    fail:;
    }
  cout << -1;
}
