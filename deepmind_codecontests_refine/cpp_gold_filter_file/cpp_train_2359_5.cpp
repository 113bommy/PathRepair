#include <bits/stdc++.h>
#pragma GCC("O3")
using namespace std;
string printBit(int x) {
  string res;
  while (res.size() < 12) {
    res.push_back(x % 2 + '0');
    x >>= 1;
  }
  reverse((res).begin(), (res).end());
  return res;
}
long long MAX = 1e16;
int main() {
  long long N;
  scanf("%lld", &N);
  --N;
  long long sum = 0;
  for (long long i = 2; i <= MAX; i <<= 1) {
    sum += (i >> 1) * ((N + (i >> 1)) / i);
  }
  cout << sum << endl;
  return 0;
}
