#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAX = 1e6;
bool sieve[MAX + 5];
void build() {
  for (int i = 2; i < MAX + 5; i++) {
    if (!sieve[i]) {
      for (int j = 2 * i; j < MAX + 5; j += i) {
        sieve[j] = true;
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  build();
  while (n--) {
    long long x;
    cin >> x;
    if (x == 1) {
      cout << "NO\n";
      continue;
    }
    long long sqrt_x = sqrt(x);
    if (sqrt_x * sqrt_x == x) {
      if (sieve[sqrt_x]) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
