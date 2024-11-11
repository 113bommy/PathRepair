#include <bits/stdc++.h>
using namespace std;
long long m{};
long long add(long long a, long long b) { return (a + b) % m; }
long long mul(long long a, long long b) { return (a * b) % m; }
int32_t main() {
  long long T{1};
  while (T--) {
    long long n{};
    cin >> n >> m;
    vector<long long> facts(n + 3);
    facts[0] = 1;
    for (long long i = 1; i <= n; ++i) {
      facts[i] = facts[i - 1] * i;
    }
    long long result{};
    for (long long len = 1; len <= n; ++len) {
      long long x = n - len + 1;
      long long y = facts[len];
      long long z = facts[x];
      result = add(result, mul(x, mul(y, z)));
    }
    cout << result << endl;
  }
}
