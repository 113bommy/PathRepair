#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int INF = 1e9;
int n, x;
int jd(int a, int b) {
  if (b == 0) {
    return a % 10;
  } else {
    return a / 10;
  }
}
int js(int a, int b) {
  if (b == 0) {
    return a % 10;
  } else if (b == 2) {
    return (a / 10) % 10;
  } else {
    return a / 100;
  }
}
int main() {
  cin >> n;
  if (n <= 9) {
    cout << n;
  } else if (n <= 189) {
    n = n - 9;
    x = (n + (n % 2)) / 2;
    cout << jd(x + 9, n % 2);
  } else {
    n = n - 189;
    if (x % 3 == 0)
      x = n / 3;
    else if (x % 3 == 1)
      x = (n + 2) / 3;
    else
      x = (n + 1) / 3;
    cout << js(x + 99, n % 3);
  }
  return 0;
}
