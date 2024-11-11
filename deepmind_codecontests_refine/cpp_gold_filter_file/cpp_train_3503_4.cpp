#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
void solve() {
  long long n, k, A, B;
  cin >> n >> k >> A >> B;
  int x = n;
  long long sum = 0;
  while (x > 1) {
    sum += (x % k) * A;
    x -= (x % k);
    long long c = x / k;
    if ((x - c) * A > B) {
      sum += B;
      x /= k;
    } else {
      sum += (x - 1) * A;
      break;
    }
  }
  cout << sum << endl;
}
int main() {
  solve();
  return 0;
}
