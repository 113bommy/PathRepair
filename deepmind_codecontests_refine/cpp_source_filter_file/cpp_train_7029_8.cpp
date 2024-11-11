#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const double EPS = 0.0000000001;
const long long int mod1 = 998244353;
const long long int mod2 = 1000000007;
const long long int mod3 = 1000000009;
int main() {
  int n;
  cin >> n;
  string mass[n];
  for (int i = 0; i < n; i++) cin >> mass[i];
  int c = 1000000;
  for (int i = 0; i < n; i++) {
    for (int z = i + 1; z < n; z++) {
      int k = 0;
      if (mass[i][0] != mass[z][0]) k++;
      if (mass[i][1] != mass[z][1]) k++;
      if (mass[i][2] != mass[z][2]) k++;
      if (mass[i][3] != mass[z][3]) k++;
      if (mass[i][4] != mass[z][4]) k++;
      if (mass[i][5] != mass[z][5]) k++;
      c = min(c, (k - 1) / 2);
    }
  }
  cout << c;
}
