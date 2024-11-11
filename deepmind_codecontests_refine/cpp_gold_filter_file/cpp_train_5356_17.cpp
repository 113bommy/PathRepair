#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 305;
long long flag[305];
long long n, p, x;
int main() {
  cin >> p >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (flag[x % p]) {
      cout << i;
      return 0;
    }
    flag[x % p] = 1;
  }
  cout << -1;
  return 0;
}
