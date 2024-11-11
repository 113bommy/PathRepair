#include <bits/stdc++.h>
using namespace std;
long long n, k, p, i, x;
char res(long long x) {
  if (k >= (n + 1) / 2) {
    if (x <= 2 * (n - k))
      return x % 2 == 1 ? '.' : 'X';
    else
      return 'X';
  }
  long long a = (n - k) - (k - 1);
  long long b = 0;
  if (a % 2 == 0 && a != n - 1) {
    a++;
    b = 1;
  }
  if (x <= a) return '.';
  if (x > n - b) return 'X';
  return (x - a) % 2 == 1 ? 'X' : '.';
}
int main() {
  long long a[1001];
  string ans = "";
  cin >> n >> k >> p;
  for (int i = 0; i < p; i++) {
    cin >> a[i];
  }
  if (k > 0)
    if (k == 1)
      for (int i = 0; i < p; i++) {
        if (a[i] == n)
          cout << 'X';
        else
          cout << '.';
      }
    else
      for (int i = 0; i < p; i++) {
        cout << res(a[i]);
      }
  else
    for (int i = 0; i < p; i++) cout << '.';
  cout << endl;
  return 0;
}
