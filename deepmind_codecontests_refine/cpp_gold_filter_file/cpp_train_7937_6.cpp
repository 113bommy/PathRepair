#include <bits/stdc++.h>
using namespace std;
bool isvalid(int num, int &count) {
  int count1 = 0;
  int num2 = num;
  while (num) {
    if (num % 10 == 1 || num % 10 == 0) {
      if (num % 10 == 1) count1++;
      if (count1 > 1) return false;
    } else
      return false;
    num /= 10;
  }
  count += log(num2) / log(10);
  return true;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = a[i] - i - 1;
    }
    int i = 0, j = n - 1;
    while (i < n && a[i] == 0) {
      i++;
    }
    while (j >= 0 && a[j] == 0) j--;
    if (i == n)
      cout << 0 << endl;
    else {
      bool flag = true;
      for (int k = i; k <= j; k++) {
        if (a[k] == 0) flag = false;
      }
      if (flag)
        cout << 1 << endl;
      else
        cout << 2 << endl;
    }
  }
}
