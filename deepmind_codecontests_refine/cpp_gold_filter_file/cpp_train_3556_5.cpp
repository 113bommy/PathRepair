#include <bits/stdc++.h>
using namespace std;
bool comp(int x, int y) { return x < y; }
int to_int(char c) { return c; }
long long getMin(long long arr[], long long n) {
  long long res = 1e6;
  for (int i = 0; i <= n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
long long divisors(int n) {
  long long cnt = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      cnt++;
    }
  }
  return cnt;
}
bool isPrime(long long n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void dispPrime(long long n) {
  long long num = 1e6;
  bool prime[num + num + num];
  memset(prime, true, sizeof(prime));
  for (int i = 2; i * i < num + num + num; i++) {
    if (prime[i]) {
      for (int j = i * 2; j < num + num + num; j += i) {
        prime[j] = false;
      }
    }
  }
  long long k = 2;
  long long cnt = 0;
  while (true) {
    if (prime[k]) {
      cnt++;
      cout << k << " ";
    }
    if (cnt == n) {
      break;
    }
    k++;
  }
}
int mltply(int n, int f[], int sz) {
  int carry = 0;
  for (int i = 0; i < sz; i++) {
    int prod = f[i] * n + carry;
    f[i] = prod % 10;
    carry = prod / 10;
  }
  while (carry) {
    f[sz] = carry % 10;
    carry /= 10;
    sz++;
  }
  return sz;
}
void factorial(int n) {
  int f[500];
  f[0] = 1;
  int sz = 1;
  for (int i = 2; i < n + 1; i++) {
    sz = mltply(i, f, sz);
  }
  int ans = 0;
  for (int i = sz - 1; i >= 0; i--) {
    ans += f[i];
  }
  cout << ans << "\n";
}
int main() {
  int n, m;
  cin >> n >> m;
  char arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 'W') {
        if (i - 1 >= 0) {
          if (arr[i - 1][j] == 'P') {
            cnt++;
            arr[i - 1][j] = '.';
            continue;
          }
        }
        if (j + 1 < m) {
          if (arr[i][j + 1] == 'P') {
            cnt++;
            arr[i][j + 1] = '.';
            continue;
          }
        }
        if (j - 1 >= 0) {
          if (arr[i][j - 1] == 'P') {
            cnt++;
            arr[i][j - 1] = '.';
            continue;
          }
        }
        if (i + 1 < n) {
          if (arr[i + 1][j] == 'P') {
            cnt++;
            arr[i + 1][j] = '.';
            continue;
          }
        }
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
