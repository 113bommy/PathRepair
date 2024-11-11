#include <bits/stdc++.h>
using namespace std;
long long fac(long long n, long long i, long long res) {
  if (i > n) {
    return res;
  } else {
    res *= i;
    i++;
    fac(n, i, res);
  }
}
int main() {
  long long n, s = 1, res = 1;
  cin >> n;
  cout << fac(n - 1, s, res) * 2 / n << endl;
}
