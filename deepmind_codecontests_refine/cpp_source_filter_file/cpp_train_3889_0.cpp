#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long mas[1111][1111], y[1111], x[1111];
long long X, Y, ansX = 1000000000000000000, ansY = 1000000000000000000;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%I64d", &mas[j][i]);
  for (int i = 1; i <= n; ++i) {
    long long sum = 0;
    for (int j = 1; j <= m; ++j) sum += mas[j][i];
    x[i] = sum;
  }
  for (int j = 1; j <= m; ++j) {
    long long sum = 0;
    for (int i = 1; i <= n; ++i) sum += mas[j][i];
    y[j] = sum;
  }
  for (int i = 1; i <= n; ++i) {
    long long sum = 0;
    for (int j = 1; j <= i; ++j)
      sum += x[j] * ((abs(i - j) * 4 + 2) * (abs(i - j) * 4 + 2));
    for (int j = i + 1; j <= n; ++j)
      sum += x[j] * (((abs(i - j) - 1) * 4 + 2) * ((abs(i - j) - 1) * 4 + 2));
    if (sum < ansX) {
      ansX = sum;
      X = i;
    }
  }
  for (int i = 1; i <= m; ++i) {
    long long sum = 0;
    for (int j = 1; j <= i; ++j)
      sum += y[j] * (((abs(i - j) * 4 + 2)) * ((abs(i - j) * 4 + 2)));
    for (int j = i + 1; j <= m; ++j)
      sum += y[j] * (((abs(i - j) - 1) * 4 + 2) * ((abs(i - j) - 1) * 4 + 2));
    if (sum < ansY) {
      ansY = sum;
      Y = i;
    }
  }
  cout << ansX + ansY << endl;
  cout << X << ' ' << Y << endl;
  return 0;
}
