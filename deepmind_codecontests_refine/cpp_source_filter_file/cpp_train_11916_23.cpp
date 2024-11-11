#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int INF = 1000000000;
int s(int first) {
  int r = 0;
  while (first) {
    r += first % 10;
    first /= 10;
  }
  return r;
}
int main() {
  long long m;
  cin >> m;
  long long b = 1000 * 1000 * 1000;
  long long r = b * b;
  r = 9 * r % m;
  r = 9 * r % m;
  r = (m - (r + 1) % m) % m;
  cout << 1 + r << b * b + r << endl;
  return 0;
}
