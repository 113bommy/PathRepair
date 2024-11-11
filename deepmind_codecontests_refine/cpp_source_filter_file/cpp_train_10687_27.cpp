#include <bits/stdc++.h>
using namespace std;
long long n, k, ans;
int main() {
  cin >> n >> k;
  for (long long i = 1; i <= k; i++) {
    if (n % 10 != 0) {
      n = n - 1;
    }
    if (n % 10 == 1) {
      n = n / 10;
    }
  }
  cout << n << endl;
}
