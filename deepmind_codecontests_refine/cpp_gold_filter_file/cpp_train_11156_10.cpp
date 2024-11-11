#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  if (x == 1) return 0;
  if (x == 2) return 1;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  if (isPrime(n)) {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
      if (i < n)
        cout << i << " " << i + 1 << "\n";
      else
        cout << i << " " << 1 << "\n";
    }
    return 0;
  }
  int temp = n;
  for (int i = n + 1;; i++) {
    if (isPrime(i)) {
      n = i;
      break;
    }
  }
  if (isPrime(n - temp + 2)) {
    cout << n << "\n";
    for (int i = 1; i <= temp; i++) {
      if (i < temp)
        cout << i << " " << i + 1 << "\n";
      else
        cout << i << " " << 1 << "\n";
    }
    int cnt = 3;
    for (int i = 1; i <= n - temp; i++) {
      cout << 1 << " " << cnt << "\n";
      cnt++;
    }
    return 0;
  }
  int tt;
  for (int i = n - temp + 2;; i--) {
    if (isPrime(i)) {
      tt = i;
      break;
    }
  }
  cout << n << "\n";
  for (int i = 1; i <= temp; i++) {
    if (i < temp)
      cout << i << " " << i + 1 << "\n";
    else
      cout << i << " " << 1 << "\n";
  }
  int cnt = 3;
  for (int i = 1; i <= tt - 2; i++) {
    cout << 1 << " " << cnt << "\n";
    cnt++;
  }
  int cnt2 = 1;
  cout << 2 << " " << cnt << "\n";
  for (int i = cnt + 1; cnt2 <= n - temp + 2 - tt - 1; i) {
    cout << i << " " << i + 2 << "\n";
    cnt2++;
    cnt++;
  }
  return 0;
}
