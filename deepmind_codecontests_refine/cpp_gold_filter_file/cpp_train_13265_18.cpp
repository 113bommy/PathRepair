#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int binomial(int n, int k, const int& factorial) {
  auto result = factorial;
  for (auto i = 1; i <= k; i++) result = 1LL * result * (n - i + 1) % p;
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int result = 1;
  vector<int> a(n, 0);
  for (auto i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> count;
  for (auto current : a) {
    for (auto i = 2; i <= current / i; i++)
      while (current % i == 0) {
        count[i] = count[i] + 1;
        current /= i;
      }
    if (current != 1) {
      count[current] = count[current] + 1;
    }
  }
  int inverse[600];
  int factorial = 1;
  inverse[1] = 1;
  for (auto i = 2; i < n; i++) {
    inverse[i] = p - 1LL * p / i * inverse[p % i] % p;
    factorial = 1LL * factorial * inverse[i] % p;
  }
  for (auto i : count)
    result = (1LL * result * binomial(n + i.second - 1, n - 1, factorial)) % p;
  cout << result << endl;
  return 0;
}
