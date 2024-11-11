#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
int ptr[1000000 + 5];
bool visited[1000000 + 5];
void flood(int k) {
  if (!visited[k]) {
    visited[k] = 1;
    flood(ptr[k]);
  }
}
long long modulo(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % MOD;
    }
    y = (y * y) % MOD;
    b /= 2;
  }
  return x % MOD;
}
int main() {
  long long p, k;
  cin >> p >> k;
  if (k <= 1) {
    cout << modulo(p, p) << "\n";
    return 0;
  }
  memset(visited, 0, sizeof(visited));
  for (int i = 0, _n = p; i < _n; i++) ptr[i] = (k * i) % p;
  int pwr = 0;
  for (int i = 0, _n = p; i < _n; i++) {
    if (!visited[i] && ptr[i] != i) {
      flood(i);
      pwr++;
    }
  }
  cout << modulo(p, pwr) << "\n";
  return 0;
}
