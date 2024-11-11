#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;
const long long linf = (1ll << 62) - 1;
int main() {
  int n;
  cin >> n;
  vector<int> is_prime(n + 1, true), primes;
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (is_prime[i]) {
      int q = 1;
      while (q <= n / i) {
        q *= i;
        ans.push_back(q);
      }
    }
  }
  cout << ((int)(ans).size()) << endl;
  for (int i : ans) {
    printf("%d ", i);
  }
  puts("");
  return 0;
}
