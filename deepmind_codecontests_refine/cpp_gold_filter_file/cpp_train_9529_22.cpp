#include <bits/stdc++.h>
using namespace std;
long long big = 1000000007ll;
long long n, m, k, q, d, h;
std::vector<long long> A;
std::vector<long long> B;
std::vector<long long> toobig;
int main() {
  long long c1, c2, c3, c4, c5, c6;
  long long x, y, z;
  long long a, b, c, e;
  std::cin >> n >> k;
  n++;
  for (c1 = 0; c1 < n; c1++) {
    std::cin >> a;
    A.push_back(a);
    toobig.push_back(1);
    B.push_back(-1);
  }
  long long nu = 0;
  long long stor = 100000000000000000ll;
  for (c1 = n - 1; c1 >= 0; c1--) {
    nu += A[c1];
    if (nu <= stor && nu >= -stor) {
      B[c1] = nu;
      toobig[c1] = 0;
      nu *= 2;
    } else {
      break;
    }
  }
  x = 0;
  long long ans = 0;
  for (c1 = 0; c1 < n; c1++) {
    if (toobig[c1] == 0) {
      if (B[c1] != x) {
        a = B[c1] - A[c1];
        if (abs(a - x) <= k && (c1 != n - 1 || abs(a - x) != 0)) {
          ans++;
        }
      }
    }
    if ((x - A[c1]) % 2 == 0) {
      x = (x - A[c1]) / 2;
    } else {
      break;
    }
  }
  std::cout << ans << "\n";
  return 0;
}
