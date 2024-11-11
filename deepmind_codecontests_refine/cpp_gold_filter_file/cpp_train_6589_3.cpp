#include <bits/stdc++.h>
using namespace std;
int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}
long long GCD(long long n, long long m) {
  if (n == 0) return m;
  return GCD(m % n, n);
}
int main() {
  bool f = 0;
  int n, UP1(0), UP2(0), x;
  cin >> x;
  string str;
  cin >> str;
  n = str.size();
  for (int i = 0; i < n; i++) {
    if ((str[i] != '7') && (str[i] != '4')) {
      return cout << "NO\n", 0;
    }
  }
  for (int i = 0; i < n / 2; i++) {
    if ((str[i] == '7') || (str[i] == '4')) {
      UP1 += (str[i] - '0');
    }
  }
  for (int i = n / 2; i < n; i++) {
    if ((str[i] == '7') || (str[i] == '4')) {
      UP2 += (str[i] - '0');
    }
  }
  if (UP1 == UP2)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
