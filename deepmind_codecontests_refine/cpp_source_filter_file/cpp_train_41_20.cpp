#include <bits/stdc++.h>
using namespace std;
string c(int base, int x) {
  int a[4], l = 0;
  string ans;
  while (x > 0) a[++l] = x % base, x /= base;
  for (int i = l; i >= 1; i--) ans += (char)(a[i] - '0');
  return ans;
}
int main() {
  int base;
  cin >> base;
  for (int i = 1; i < base; i++)
    for (int j = 1; j < base; j++)
      cout << c(base, i * j) << (j < base - 1 ? ' ' : '\n');
  return 0;
}
