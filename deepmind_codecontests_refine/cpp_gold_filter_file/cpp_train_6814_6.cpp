#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const double EPS = 10e-9;
int main() {
  long long n;
  cin >> n;
  long long pot = 1;
  for (int i = 0; i < (18); ++i) pot *= 10;
  long long r = pot % n;
  for (int i = 0; i < (4); ++i) {
    r *= 3;
    r %= n;
  }
  n -= r;
  cout << n << " " << pot + n - 1;
  return 0;
}
