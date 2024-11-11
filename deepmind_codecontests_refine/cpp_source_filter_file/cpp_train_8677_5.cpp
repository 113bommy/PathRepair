#include <bits/stdc++.h>
using namespace std;
int prime[1000001] = {0};
int tprime(long long a) {
  long long b = (long long)sqrt(a);
  if (a != (b * b))
    return 0;
  else
    return !prime[b];
}
int main() {
  int n;
  cin >> n;
  prime[1] = 0;
  prime[2] = 0;
  for (long i = 2; i <= sqrt(1000001); i++) {
    if (!prime[i]) {
      for (long j = i * i; j <= 1000000; j += i) prime[j] = 1;
    }
  }
  for (int i = 0; i <= n - 1; i++) {
    long long a;
    cin >> a;
    if (tprime(a))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
