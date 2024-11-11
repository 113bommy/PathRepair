#include <bits/stdc++.h>
using namespace std;
bool prime[100];
int a[100];
long long ans[100];
bool check(int a[], int m, int k) {
  for (int i = k; i < m; i += k) {
    for (int j = 0; j < k; ++j) {
      if (a[j] != a[i + j]) {
        return a[j] < a[i + j];
      }
    }
  }
  return true;
}
void gen_prime() {
  fill(prime, prime + 100, true);
  for (int i = 2; i < 100; ++i) {
    if (!prime[i]) continue;
    for (int j = i * i; j < 100; j += i) {
      prime[j] = false;
    }
  }
}
int gcd(int a, int b) {
  while (b) {
    int c = a;
    a = b;
    b = c % b;
  }
  return a;
}
long long calc(long long n) {
  if (n <= 1) return 0;
  int m = 0;
  for (long long _n = n; _n; _n >>= 1) {
    a[m++] = _n & 1;
  }
  long long ret = ans[m - 1];
  for (int i = 0; i < m / 2; ++i) {
    swap(a[i], a[m - 1 - i]);
  }
  vector<int> A;
  for (int k = 2; k <= m; ++k) {
    if (m % k == 0) A.push_back(k);
  }
  for (int i = 1; i < (1 << (int)(A.size())); ++i) {
    int len = m, cnt = 0;
    for (int j = 0; j < (int)(A.size()); ++j) {
      if (i & (1 << j)) {
        len = gcd(len, m / A[j]);
        ++cnt;
      }
    }
    long long all = 0;
    long long sum = 0;
    for (int k = 0; k < len; ++k) {
      sum = (sum << 1) | a[k];
    }
    all += sum - (1LL << (len - 1)) + check(a, m, len);
    if (cnt % 2)
      ret += all;
    else
      ret -= all;
  }
  return ret;
}
int main() {
  long long a, b;
  gen_prime();
  ans[1] = 0;
  for (int i = 2; i < 64; ++i) {
    ans[i] = calc((1LL << i) - 1);
  }
  cin >> a >> b;
  cout << calc(b) - calc(a - 1) << endl;
  return 0;
}
