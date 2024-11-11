#include <bits/stdc++.h>
using namespace std;
bool prim(int n) {
  int i, gigel = 0;
  if (n < 2)
    return 0;
  else {
    for (i = 2; i * i <= n; i++) {
      if (n % i == 0) return 0;
    }
    return 1;
  }
}
int main() {
  int n, i, a;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a;
    if (sqrt(a) == (int)sqrt(a) && prim(sqrt(a)) == 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
