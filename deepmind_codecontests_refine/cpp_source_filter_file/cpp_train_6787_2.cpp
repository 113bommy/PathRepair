#include <bits/stdc++.h>
using namespace std;
int f[100003];
int main() {
  int n, m;
  cin >> n >> m;
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i < 100002; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % 1000000007;
  }
  cout << (2 * (f[n] + f[m] - 1)) % 1000000007;
}
