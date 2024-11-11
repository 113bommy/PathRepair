#include <bits/stdc++.h>
using namespace std;
long long nthRoot(long long A, long long N) {
  float xPre = rand() % 10;
  float eps = 1e-3;
  float delX = LLONG_MAX;
  float xK;
  while (delX > eps) {
    xK = ((N - 1.0) * xPre + (float)A / pow(xPre, N - 1)) / (float)N;
    delX = abs(xK - xPre);
    xPre = xK;
  }
  return ceil(xK);
}
int main() {
  long long n;
  cin >> n;
  char a[] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
  long long in = 0, num;
  num = nthRoot(n, 10);
  if (pow(num, 10) < n) num++;
  for (int i = 0; i <= 10; i++) {
    if (pow(num - 1, i) * pow(num, 10 - i) >= n) {
      in = i;
    } else
      break;
  }
  if (in * (num - 1) + (10 - in) * num - 10 < n - 1) {
    for (int i = 0; i < in; i++) {
      long long t = num - 1;
      while (t--) cout << a[i];
    }
    for (int i = in; i < 10; i++) {
      long long t = num;
      while (t--) cout << a[i];
    }
  } else {
    for (int i = 0; i < 10; i++) cout << a[i];
    long long t = n - 1;
    while (t--) cout << a[9];
  }
}
