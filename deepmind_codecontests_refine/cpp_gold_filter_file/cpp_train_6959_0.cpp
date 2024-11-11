#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int n;
  cin >> n;
  for(int i = sqrt(n); ; i--) {
    if(n % i == 0) {
      cout << (int)log10(n / i) + 1 << endl;
      return 0;
    }
  }
}