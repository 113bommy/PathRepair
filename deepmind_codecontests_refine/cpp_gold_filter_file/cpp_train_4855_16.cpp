#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int max(int a, int b) { return a > b ? a : b; }
bool per(int n, int one, int zero) {
  int d = 0, p = 0;
  while (n > 0) {
    if (n % 2 == zero) {
      d++;
    } else if (n % 2 == one) {
      break;
    }
    n /= 2;
  }
  while (n > 0) {
    if (n % 2 == one) {
      p++;
    } else {
      break;
    }
    n /= 2;
  }
  int rs = 0;
  if (p == 0) {
    rs = d - p;
  } else {
    rs = p - d;
  }
  if (n == 0 && rs == 1) {
    return true;
  }
  return false;
}
bool dectobinary(int n) {
  if (n % 2 == 0) {
    return per(n, 1, 0);
  }
  return per(n, 0, 1);
}
int main() {
  int n;
  cin >> n;
  int m = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0 && dectobinary(i)) {
      m = max(m, i);
    }
  }
  cout << m << endl;
  return 0;
}
