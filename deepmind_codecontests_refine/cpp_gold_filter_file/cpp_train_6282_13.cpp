#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  int tmp;
  cin >> a;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
  }
  cin >> b;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
  }
  if (m < n) {
    if (a * b < 0)
      cout << "-Infinity" << endl;
    else
      cout << "Infinity" << endl;
    return 0;
  }
  if (m > n) {
    cout << "0/1" << endl;
    return 0;
  }
  if (m == n) {
    int k = gcd(abs(a), abs(b));
    a /= k;
    b /= k;
    if (a * b < 0) {
      cout << "-" << abs(a) << "/" << abs(b) << endl;
    } else {
      cout << abs(a) << "/" << abs(b) << endl;
    }
  }
  return 0;
}
