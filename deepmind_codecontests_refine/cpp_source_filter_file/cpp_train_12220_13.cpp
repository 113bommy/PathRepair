#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  return b == 0 ? abs(a) : gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int prime[1000000];
void seive() {
  int n_prime = 1000000;
  fill_n(prime, n_prime, 1);
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i * i <= n_prime; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= n_prime; j += i) {
        prime[j] = 0;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, y;
  std::cin >> x >> y;
  int count = 0;
  int temp = 0;
  if (x == 1 && y == 0) {
    temp = 1;
  }
  if (x >= 0 && y >= 0) {
    if (x >= y) {
      y = x;
    } else {
      x = -y;
    }
  } else if (x < 0 && y >= 0) {
    if (abs(x) >= y) {
      y = x;
    } else {
      x = -y;
    }
  } else if (x < 0 && y < 0) {
    if (abs(x) >= abs(y)) {
      y = x;
    } else {
      x = -y + 1;
    }
  } else if (x >= 0 && y < 0) {
    if (abs(x) >= abs(y)) {
      y = x;
    } else {
      x = -y + 1;
    }
  }
  if ((x == 0 && y == 0) || temp == 1) {
    std::cout << 0 << '\n';
    return 0;
  } else {
    if (x > 0 && y > 0) {
      count = 1 + (x - 1) * 4;
    } else if (x < 0 && y < 0) {
      count = 3 + (abs(x) - 1) * 4;
    } else if (x < 0 && y > 0) {
      count = 2 + (y - 1) * 4;
    } else {
      count = (x - 1) * 4;
    }
  }
  std::cout << count << '\n';
  return 0;
}
