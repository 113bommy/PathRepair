#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
template <class T>
T ABS(const T &x) {
  return x > 0 ? x : -x;
}
long long int gcd(long long int n1, long long int n2) {
  return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2);
}
long long int lcm(long long int n1, long long int n2) {
  return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2);
}
const int N = 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int foo;
  bitset<N> a[n][n];
  bitset<N> tmp;
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      cin >> foo;
      tmp = foo;
      a[i][j] = tmp;
    }
  }
  bitset<N> res[n];
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (n); ++j) {
      if (i == j) {
        continue;
      }
      for (int l = 0; l < (N); ++l) {
        if (a[i][j][l] == 1) {
          res[i][l] = 1;
          res[j][l] = 1;
        }
      }
    }
  }
  for (int i = 0; i < (n); ++i) {
    cout << res[i].to_ulong() << " ";
  }
  return 0;
}
