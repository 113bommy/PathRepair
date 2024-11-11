#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int gcd(int m, int n) { return n ? gcd(n, m % n) : m; }
bool cmp(int a, int b) { return a > b; }
int prime(int n) {
  int flag = 0;
  for (int i = 2; i <= sqrt(n * 1.00); ++i) {
    if (n % i == 0) {
      flag = 1;
      return 1;
    }
  }
  if (flag == 0) return 0;
}
map<int, int> v;
int a[200000];
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int tmp = a[0];
  int res = a[0];
  for (int i = 0; i < n; ++i) {
    if (i == 0)
      cout << a[0] << " ";
    else {
      cout << a[i] + tmp << " ";
      res += a[i];
    }
    tmp = max(res, tmp);
  }
  return 0;
}
