#include <bits/stdc++.h>
using namespace std;
long long getrand(long long int a, long long int b) {
  random_device rd;
  mt19937_64 eng(rd());
  uniform_int_distribution<unsigned long long> distr;
  return min(a, b) + distr(eng) % (max(a, b) - min(a, b) + 1);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<long> a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  long xor1 = 0, xor2 = 0;
  for (int i = 0; i < n; ++i) xor1 ^= a[i];
  for (int i = 0; i < m; ++i) xor2 ^= b[i];
  if (xor1 != xor2) {
    cout << "NO" << endl;
    exit(0);
  }
  printf("YES\n");
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) printf("0 ");
    printf("%li\n", a[i]);
  }
  for (int i = 0; i < m - 1; ++i) printf("%li ", b[i]);
  printf("%li\n", xor1 ^ b[m - 1] ^ a[n - 1]);
}
int main() {
  solve();
  return 0;
}
