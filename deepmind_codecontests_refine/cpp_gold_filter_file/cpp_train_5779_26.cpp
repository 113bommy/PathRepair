#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6;
bool tub(int n) {
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
bool prime[3123456];
int main() {
  int n;
  cin >> n;
  bool ok = 1;
  if (tub(n)) return cout << "1\n" << n, 0;
  prime[1] = 1;
  for (int i = 2; i * i <= maxn; i++) {
    if (!prime[i]) {
      for (int j = i * i; j <= maxn; j += i) prime[j] = 1;
    }
  }
  for (int i = 2; i < min(n, maxn); i++)
    if (!prime[i] && tub(n - i))
      return cout << "2\n"
                  << " " << i << " " << n - i,
             0;
  n -= 3;
  for (int i = 2; i < min(n, maxn); i++)
    if (!prime[i] && tub(n - i))
      return cout << "3\n"
                  << "3 " << i << " " << n - i,
             0;
}
