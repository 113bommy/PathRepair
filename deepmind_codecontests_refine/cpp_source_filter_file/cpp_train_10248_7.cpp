#include <bits/stdc++.h>
using namespace std;
int x[110], y[110];
long long my_pow(int a, int b) {
  long long x = 1, y = a;
  while (b) {
    if (b % 2) x *= y;
    y *= y;
    b >>= 1;
  }
  return x;
}
int main() {
  int n, m, a = 0;
  cin >> n >> m;
  for (int i = (0); i < (n); i++) cin >> x[i];
  long long val = 0;
  for (int i = (0); i < (m); i++) {
    int j;
    cin >> j;
    y[j - 1] = 1;
    a = max(a, x[j - 1]);
  }
  for (int i = (0); i < (n); i++)
    if (!y[i]) val += x[i];
  cout << max(val + a * my_pow(2, m - 1), val * my_pow(2, m)) << endl;
  return 0;
}
