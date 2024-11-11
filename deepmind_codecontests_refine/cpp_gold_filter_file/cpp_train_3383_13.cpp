#include <bits/stdc++.h>
using namespace std;
bool prime[10000000];
bool pall[10000000];
double cnt1[10000000], cnt2[10000000];
bool pallindrome(int n) {
  int a = n, b = 0;
  while (a > 0) {
    b = 10 * b + a % 10;
    a /= 10;
  }
  if (b == n) return true;
  return false;
}
void check_pall() {
  for (int i = 1; i < 10000000; i++) {
    pall[i] = pallindrome(i);
    if (pall[i]) {
      cnt2[i] = cnt2[i - 1] + 1;
    } else {
      cnt2[i] = cnt2[i - 1];
    }
  }
}
void check_prime() {
  prime[0] = 1;
  prime[1] = 1;
  for (int i = 2; i < 10000000; i++) {
    if (!prime[i]) {
      for (int j = 2 * i; j < 10000000; j += i) {
        prime[j] = 1;
      }
    }
    if (prime[i] == 0) {
      cnt1[i] = cnt1[i - 1] + 1;
    } else {
      cnt1[i] = cnt1[i - 1];
    }
  }
}
int main() {
  check_prime();
  check_pall();
  double p;
  double q;
  cin >> p >> q;
  for (int i = 9999999; i >= 1; i--) {
    if ((p / q) >= cnt1[i] / cnt2[i]) {
      cout << i << endl;
      break;
    }
  }
}
