#include <bits/stdc++.h>
using namespace std;
bool check(long long p) {
  for (long long i = 2; i * i <= p; i++)
    if (p % i == 0) return 1;
  return 0;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 4;; i += 2)
    if (check(i + n)) {
      cout << i + n << " " << i;
      return 0;
    }
  return 0;
}
