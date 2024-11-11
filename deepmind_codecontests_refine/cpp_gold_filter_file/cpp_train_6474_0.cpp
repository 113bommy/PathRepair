#include <bits/stdc++.h>
using namespace std;
long long int binaexpo(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  long long int x = binaexpo(2, m) - 1;
  cout << binaexpo(x, n) << "\n";
}
