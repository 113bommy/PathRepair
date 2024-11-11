#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 2e3 + 100;
vector<long long> v;
int q, n, x, m;
string second;
map<int, int> mp;
int main() {
  cin >> x;
  for (int i = 1; i < x; ++i) {
    for (int j = 1; j < x; ++j) {
      if (i <= x && j <= x) {
        if (i % j == 0) {
          if (i * j > x) {
            if (i / j < x) {
              cout << i << " " << j;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1;
}
