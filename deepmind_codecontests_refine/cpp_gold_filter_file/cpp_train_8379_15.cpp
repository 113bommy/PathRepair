#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long mod = 1000000007;
  long long a = 1, b = 1;
  for (int i = 0; i < 3 * n; i++) {
    a = (a * 3) % mod;
  }
  for (int i = 0; i < n; i++) {
    b = (b * 7) % mod;
  }
  cout << ((a - b) + mod) % mod;
}
