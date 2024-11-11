#include <bits/stdc++.h>
using namespace std;
vector<int> vi;
bool is_prime(int x) {
  for (int i = 2; i <= x / i; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int fast_pow(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans *= a, ans %= mod;
    a *= a;
    a %= mod;
    ans %= mod;
    b >>= 1;
  }
  return ans % mod;
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i <= 100; i++) {
    if (fast_pow(n, i, d) == 0) {
      printf("2-type\n%d\n", i);
      return 0;
    }
  }
  if (n % d == 1) {
    printf("3-type\n");
    return 0;
  }
  if (n % d == d - 1) {
    printf("11-type\n");
    return 0;
  }
  int tmp = d;
  for (int i = 2; i <= 100; i++) {
    if (is_prime(i) && d % i == 0) {
      int v = 1;
      while (tmp % i == 0) {
        v *= i;
        tmp /= i;
      }
      vi.push_back(v);
    }
  }
  for (int k = 0; k < vi.size(); k++) {
    int flag = 0;
    for (int i = 0; i <= 100; i++) {
      if (fast_pow(n, i, vi[k]) == 0) {
        flag = 1;
      }
    }
    if (n % vi[k] == 1) {
      flag = 1;
    }
    if (n % vi[k] == n - 1) {
      flag = 1;
    }
    if (!flag) {
      printf("7-type\n");
      return 0;
    }
  }
  printf("6-type\n");
}
