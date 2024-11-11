#include <bits/stdc++.h>
using namespace std;
long long f[100];
int main() {
  long long n;
  f[0] = 1, f[1] = 2;
  cin >> n;
  int ans = 1;
  while (f[ans] <= n) {
    ans++;
    f[ans] = f[ans - 1] + f[ans - 2];
  }
  cout << ans - 1;
}
