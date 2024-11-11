#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<long long> sieveOfErthnosis(long long n) {
  vector<bool> flag(n + 5, false);
  vector<long long> primes;
  for (int i = 2; i * i <= n; i++) {
    if (!flag[i]) {
      for (int j = i * i; j <= n; j += i) {
        flag[j] = true;
      }
    }
  }
  for (int i = 2; i < n + 1; i++) {
    if (!flag[i]) primes.push_back(i);
  }
  return primes;
}
void solve() {
  long long n, a, b, c;
  cin >> n >> a >> b;
  cout << min(n, max(1ll, a + b + 1 - n)) << ' ' << min(n, a + b - 1) << endl;
}
int main() {
  auto start = high_resolution_clock::now();
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
}
