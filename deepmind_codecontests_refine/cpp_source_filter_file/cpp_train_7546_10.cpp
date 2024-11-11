#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 1000000007;
int mas[200010];
bool is[200010];
int main() {
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  for (int i = 2; i <= 2 * n - 1; i++) {
    if (!is[i]) {
      int delta = i;
      while (delta <= 2 * n - 1) {
        is[delta] = true;
        int copy_delta = delta;
        while (copy_delta % i == 0) {
          mas[i]++;
          copy_delta /= i;
        }
        delta += i;
      }
    }
  }
  memset(is, 0, sizeof(is));
  for (int i = 2; i <= n - 1; i++) {
    if (!is[i]) {
      int delta = i;
      while (delta <= n - 1) {
        is[delta] = true;
        int copy_delta = delta;
        while (copy_delta % i == 0) {
          mas[i]--;
          copy_delta /= i;
        }
        delta += i;
      }
    }
  }
  memset(is, 0, sizeof(is));
  for (int i = 2; i <= n; i++) {
    if (!is[i]) {
      int delta = i;
      while (delta <= n) {
        is[delta] = true;
        int copy_delta = delta;
        while (copy_delta % i == 0) {
          mas[i]--;
          copy_delta /= i;
        }
        delta += i;
      }
    }
  }
  long long res = 1;
  for (int i = 1; i <= 2 * n - 1; i++) {
    while (mas[i] != 0) {
      res *= i;
      res %= mod;
      mas[i]--;
    }
  }
  res *= 2;
  res %= mod;
  cout << (res + mod - n) % mod;
}
