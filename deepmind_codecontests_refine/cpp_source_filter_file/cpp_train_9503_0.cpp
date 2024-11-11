#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int s[maxn];
long long c(long long a, long long b) {
  long long sum = 1;
  long long cnt = 1;
  for (long long i = b; i > b - a; i--, cnt++) {
    sum *= i;
    sum /= cnt;
  }
  return sum;
}
int main() {
  long long t;
  cin >> t;
  long long k[20] = {1, 1, 2, 6, 20, 120, 720, 5040, 40320, 362880};
  if (t == 2) {
    cout << 1;
  } else {
    long long sum = c(t / 2, t);
    cout << sum * k[t / 2 - 1] * k[t / 2 - 1] / 2;
  }
  return 0;
}
