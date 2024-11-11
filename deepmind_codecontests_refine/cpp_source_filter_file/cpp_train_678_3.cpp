#include <bits/stdc++.h>
using namespace std;
int f[10005];
int main() {
  int n;
  cin >> n;
  if (n > 2) {
    if (n % 2 == 0)
      n /= 2;
    else
      n = n / 2 + 1;
  }
  cout << n << '\n';
}
