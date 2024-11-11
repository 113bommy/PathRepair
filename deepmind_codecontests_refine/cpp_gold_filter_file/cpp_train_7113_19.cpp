#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long v = 0;
  v = n;
  long double temp = 1;
  for (long double i = k; i < n; i *= k) {
    temp += (1.0 / i);
  }
  v /= temp;
  for (long long i = 0; i < 11; i++) {
    long long te = v + i;
    long long cost = 0;
    long long cop = 1;
    while (te / cop > 0) {
      cost += te / cop;
      cop *= k;
    }
    if (cost >= n) {
      cout << te << endl;
      return 0;
    }
  }
}
