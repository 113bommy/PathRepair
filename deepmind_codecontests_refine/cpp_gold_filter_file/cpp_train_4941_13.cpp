#include <bits/stdc++.h>
using namespace std;
long long N;
long long how_many(long long ub, int rem) {
  if (rem == 0) return ub / 3;
  if (ub < rem) return 0;
  return 1 + (ub - rem) / 3;
}
int main() {
  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  long long L = 1, H = 1000000;
  long long B = 1;
  while (L <= H) {
    long long M = (L + H) / 2;
    long long C = M * (M + 1);
    C = C / 2 * 3;
    C = C - M;
    if (C > N)
      H = M - 1;
    else {
      B = M;
      L = M + 1;
    }
  }
  int rem = (3 - (N % 3)) % 3;
  cout << how_many(B, rem) << endl;
}
