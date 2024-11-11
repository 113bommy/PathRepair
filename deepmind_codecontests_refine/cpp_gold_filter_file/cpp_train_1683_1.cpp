#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  if (n < 10) {
    cout << n << endl;
    return 0;
  }
  long long now = 0, len = 0;
  long long sum = 9, num = 1;
  while (now < n) {
    len++;
    now += sum * len;
    sum *= 10;
    num *= 10;
  }
  sum /= 10;
  now -= sum * len;
  long long k = (n - now) / len + num / 10;
  long long rank = (n - now) % len;
  if (!rank) {
    rank = len;
    k--;
  }
  for (long long i = 1; i <= len - rank; ++i) k /= 10;
  cout << k % 10 << endl;
  return 0;
}
