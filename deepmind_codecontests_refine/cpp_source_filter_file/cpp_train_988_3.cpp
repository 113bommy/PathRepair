#include <bits/stdc++.h>
using namespace std;
long long n;
long long k, s, v;
int i, j, m, l;
int starti, startj, endi, endj, p, ch, X, Y;
int a[100], b[100];
long long x, y;
int main() {
  cin >> n >> X;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    x += pow(X, n - i - 1) * a[i];
  }
  cin >> m >> Y;
  for (i = 0; i < m; i++) {
    cin >> b[i];
    y += pow(Y, m - i - 1) * b[i];
  }
  if (x > y)
    cout << ">";
  else if (x < y)
    cout << "<";
  else
    cout << "=";
}
