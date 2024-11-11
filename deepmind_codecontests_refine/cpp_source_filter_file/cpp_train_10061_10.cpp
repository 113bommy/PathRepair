#include <bits/stdc++.h>
using namespace std;
int prime[1000000];
void primo() {
  int n = 2;
  while (n < 1000000) {
    int num = n * 2;
    while (num < 1000000) {
      prime[num] = n;
      num += n;
    }
    num = n + 1;
    while (prime[num] != 0 && num < 1000000) num++;
    n = num;
  }
}
int main() {
  primo();
  int x0, x1, x2;
  cin >> x2;
  int a = 0, b = 0;
  b = prime[x2];
  x0 = 1000000;
  for (int i = x2 - b + 1; i <= x2; i++) {
    a = prime[i];
    x0 = min(i - a + 1, x0);
  }
  cout << x0;
  return 0;
}
