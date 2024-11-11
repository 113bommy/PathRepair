#include <bits/stdc++.h>
using namespace std;
long long int poww(long long int x, long long int y) {
  long long int ans = 1;
  while (y-- > 0) {
    ans *= x;
  }
  return ans;
}
void sieve() {
  bool *primes = new bool[100000 + 1];
  for (long long int i = 0; i < 100000 + 1; i++) {
    primes[i] = true;
  }
  long long int sqr = sqrt(100000);
  primes[0] = false;
  primes[1] = false;
  for (long long int p = 2; p <= sqr; p++) {
    if (primes[p]) {
      for (long long int i = p * p; i <= 100000; i += p) {
        primes[i] = false;
      }
    }
  }
  vector<int> v;
  for (long long int i = 2; i <= 100000; i++) {
    if (primes[i]) {
      v.push_back(i);
    }
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    long long int arr[n];
    int ch = 0;
    for (long long int i = 0; i <= n - 1; i++) {
      cin >> arr[i];
    }
    if (n % 2 == 0) {
      cout << "YES" << endl;
    } else {
      for (long long int i = 0; i <= n - 2; i++) {
        if (arr[i] >= arr[i + 1]) {
          ch = 1;
          break;
        }
      }
      if (ch == 1) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
