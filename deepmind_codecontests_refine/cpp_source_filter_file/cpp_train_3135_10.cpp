#include <bits/stdc++.h>
using namespace std;
void bye();
long long int power(long long int a, long long int b, long long int m);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t, pro = 1, n, m, temp, k, l, r, mid, i, j, x, y, z, rem, ind,
                   ans = 0, mx = LONG_LONG_MIN, mn = LONG_LONG_MAX, cnt = 0,
                   curr = 0, prev, sum = 0, flag = 0, i1 = -1, i2 = -1;
  cin >> n >> m;
  if (n > m) {
    swap(n, m);
  }
  if (n == 1) {
    cout << 6 * (m / 6) + max(0ll, (m % 6) - 2);
  } else if (n % 2 == 0 && m % 2 == 0) {
    if (n == 2 && m == 2) {
      cout << "0";
    } else {
      cout << n * m;
    }
  } else if ((n + m) % 2) {
    if (m % 2) {
      swap(n, m);
    }
    if (n == 3 && m == 2) {
      cout << 4;
    } else if (n == 7 && m == 2) {
      cout << 12;
    } else {
      cout << n * m;
    }
  } else {
    cout << m * n - 1;
  }
  return 0;
}
void bye() { exit(0); }
long long int power(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b /= 2;
    a = (a * a) % m;
  }
  return res;
}
