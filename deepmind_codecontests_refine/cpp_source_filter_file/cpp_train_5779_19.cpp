#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592654;
long long arr[100];
int prime(long long n) {
  if (n <= 2) return 1;
  if (n % 2 == 0) return 0;
  for (long long i = 3; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  int t, sum = 0;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long t, th;
    if (prime(n) == 1) {
      cout << 1 << endl;
      cout << n << endl;
      return 0;
    }
    t = n - 2;
    if (prime(t) == 1) {
      cout << 2 << endl;
      cout << 2 << " " << t << endl;
      return 0;
    } else {
      t = t - 2;
      if (prime(t) == 1) {
        cout << 3 << endl;
        cout << 2 << " " << 2 << " " << t << endl;
        return 0;
      }
    }
    th = n - 3;
    if (prime(th) == 1) {
      cout << 2 << endl;
      cout << 3 << " " << th << endl;
      return 0;
    } else {
      long long sum = 0, chk = th;
      for (int i = 3; i < n / 2; i += 2) {
        th -= i;
        sum += i;
        chk = th - i;
        if (prime(th) == 1 && prime(sum) == 1) {
          cout << 3 << endl;
          cout << 3 << " " << th << " " << sum << endl;
          return 0;
        }
        if (prime(chk) == 1 && prime(i) == 1) {
          cout << 3 << endl;
          cout << 3 << " " << chk << " " << i << endl;
          return 0;
        }
      }
    }
  }
}
