#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) {
  return p1.first > p2.first;
}
long long int power(int a, int b) {
  if (b == 0) return 1;
  return a * power(a, b - 1);
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, m;
  cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 0; i < n + 1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m + 1; i++) {
    cin >> b[i];
  }
  if (n > m) {
    if (a[0] * b[0] > 0)
      cout << "Infinity";
    else
      cout << "-Infinity";
  } else if (n < m) {
    cout << "0/1";
  } else {
    if (a[0] * b[0] < 0) {
      cout << "-";
    }
    cout << abs(a[0]) / gcd(abs(a[0]), abs(b[0])) << "/"
         << abs(b[0]) / gcd(abs(a[0]), abs(b[0]));
  }
  return 0;
}
