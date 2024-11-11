#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, z;
  cin >> n >> m >> z;
  int res = 0;
  for (int i = 1; i <= z; i++) {
    if (n % i == 0 && m % i == 0) {
      res++;
    }
  }
  cout << res << "\n";
  return 0;
}
