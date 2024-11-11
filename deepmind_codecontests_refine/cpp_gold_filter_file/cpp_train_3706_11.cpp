#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
  bool flag = true;
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
int n, m;
bool f = true;
int main() {
  cin >> n >> m;
  for (int i = n + 1; i < m + 1; i++) {
    if (isPrime(i)) {
      if (i != m) {
        cout << "NO";
        f = false;
        break;
      }
    }
  }
  if (!isPrime(m) && f) {
    f = false;
    cout << "NO";
  }
  if (f) {
    cout << "YES";
  }
  return 0;
}
