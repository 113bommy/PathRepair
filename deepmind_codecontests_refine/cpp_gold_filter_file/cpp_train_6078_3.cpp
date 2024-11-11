#include <bits/stdc++.h>
using namespace std;
const int v[] = {1, 1, 3, 16, 125, 1296, 16807, 262144};
int main() {
  int n, k;
  cin >> n >> k;
  long long res = 1;
  for (int i = 0; i < n - k; ++i) {
    res = (res * (n - k)) % 1000000007;
  }
  res = (res * v[k - 1]) % 1000000007;
  cout << (res * (k)) % 1000000007 << endl;
}
