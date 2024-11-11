#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000;
int n, t[30][MAX + 1], color[30][MAX + 1];
map<char, int> M;
long long bin_searc(long long n) {
  long long a = 1, b = 1.e7;
  while (true) {
    if (a >= b || b - a == 1) return b;
    long long m = (a + b) / 2;
    if (m * (m + 1) / 2 < n) {
      a = m;
    } else {
      b = m;
    }
  }
  return b;
}
int main() {
  long long n;
  cin >> n;
  long long t = bin_searc(n);
  if (t * (t + 1) / 2 > n) {
    t -= 1;
  }
  n -= t * (t + 1) / 2;
  if (n == 0)
    cout << t << endl;
  else
    cout << n << endl;
}
