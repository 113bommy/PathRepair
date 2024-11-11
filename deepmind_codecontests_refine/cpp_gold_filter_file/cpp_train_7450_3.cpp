#include <bits/stdc++.h>
using namespace std;
const long long linf = LLONG_MAX;
const int CMAX = 1000 + 100;
double eps = 2.2e-13;
int getNum(long long n, long long k) {
  long long size = pow(2, n) - 1;
  if (k == size / 2 + 1) {
    return n;
  } else {
    return getNum(n - 1, k > size / 2 + 1 ? size - k + 1 : k);
  }
}
int main() {
  long long n, k;
  cin >> n >> k;
  cout << getNum(n, k) << endl;
}
