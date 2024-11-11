#include <bits/stdc++.h>
using namespace std;
long long modPower(long long num, long long r) {
  if (r == 0) return 1;
  if (r == 1) return num % 1000000007;
  long long ans = modPower(num, r / 2) % 1000000007;
  if (r % 2 == 0) {
    return (ans * ans) % 1000000007;
  }
  return (((ans * ans) % 1000000007) * num) % 1000000007;
}
long long nCr(long long n, long long r) {
  long long res = 1;
  if (r > n - r) {
    r = n - r;
  }
  for (long long i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long pos(long long n) {
  if (n < 0)
    return (-1) * n;
  else
    return n;
}
unsigned long long highestPowerof2(unsigned long long n) {
  unsigned long long p = (unsigned long long)log2(n);
  return (unsigned long long)pow(2, p);
}
long long arraySum(int a[], long long n) {
  long long initial_sum = 0;
  return accumulate(a, a + n, initial_sum);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unsigned long long n, i, j, sum, psum = 0, power, ans;
  cin >> n;
  int A[n];
  for (i = 0; i < n; i++) {
    cin >> A[i];
    psum += (A[i] - 1);
  }
  sort(A, A + n);
  j = 2;
  if (n <= 31) {
    do {
      if (j != 2) psum = sum;
      sum = 0;
      power = 1;
      for (i = 0; i < n; i++) {
        sum += pos(A[i] - power);
        power = power * j;
      }
      j++;
    } while (psum > sum);
    cout << psum;
  } else
    cout << psum;
}
