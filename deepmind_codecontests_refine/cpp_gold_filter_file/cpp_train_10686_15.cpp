#include <bits/stdc++.h>
using namespace std;
long long N, Q;
long long position(long long L, long long x) {
  if (L == 1) return 1;
  if (L == 2) return x;
  if (x % 2) return x / 2 + 1;
  long long m = (L + 1) / 2;
  if (L % 2) {
    long long next = position(L / 2 + 1, x / 2 + 1) - 1;
    return next + m;
  }
  long long next = position(L / 2, x / 2);
  return next + m;
}
int main() {
  cin >> N >> Q;
  for (int i = 0; i < Q; ++i) {
    long long cur;
    cin >> cur;
    cout << position(N, cur) << endl;
  }
  return 0;
}
