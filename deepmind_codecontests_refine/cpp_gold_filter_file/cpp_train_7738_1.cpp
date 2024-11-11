#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  vector<int> numbers, prime;
  cin >> n >> k;
  for (int i = 0; i <= n; ++i) {
    numbers.push_back(0);
  }
  for (int j = 2; j <= n; ++j) {
    if (not numbers[j]) {
      prime.push_back(j);
      for (int u = 2 * j; u <= n; u += j) {
        numbers[u] = 1;
      }
    }
  }
  int counter = 0;
  for (int c = 0; c + 1 < prime.size(); ++c) {
    if (prime[c] + prime[c + 1] + 1 <= n) {
      if (numbers[prime[c] + prime[c + 1] + 1] == 0 and
          prime[c] + prime[c + 1] + 1 <= n) {
        counter += 1;
        if (counter == k) {
          cout << "YES";
          return 0;
        }
      }
    }
  }
  if (counter < k) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
