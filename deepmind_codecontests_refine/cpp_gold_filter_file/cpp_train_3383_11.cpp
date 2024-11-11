#include <bits/stdc++.h>
using namespace std;
long long prime[10000010];
long long palin[10000010];
long long ans[10000010];
long long p(long long num) {
  long long temp = num;
  long long rem;
  long long rev = 0;
  while (temp != 0) {
    rem = temp % 10;
    rev = rev * 10 + rem;
    temp /= 10;
  }
  if (rev == num) return 1;
  return 0;
}
int main() {
  long long c = 0;
  for (long long i = 2; i <= 10000000; i++) {
    if (!prime[i]) {
      c++;
      for (long long j = i * 2; j <= 10000000; j += i) prime[j] = 1;
    }
  }
  c = 0;
  for (long long i = 2; i <= 10000000; i++) {
    if (!prime[i]) {
      c++;
      ans[i] = c;
    } else {
      ans[i] = c;
    }
  }
  c = 0;
  for (long long i = 1; i <= 10000000; i++) {
    if (p(i)) {
      c++;
      palin[i] = c;
    } else {
      palin[i] = c;
    }
  }
  long long p, q;
  cin >> p >> q;
  long long ans1 = -1;
  for (long long i = 1; i <= 10000000; i++) {
    if (q * ans[i] <= p * palin[i]) ans1 = i;
  }
  if (ans1 != -1)
    cout << ans1 << endl;
  else {
    cout << "Palindromic tree is better than splay tree" << endl;
  }
}
