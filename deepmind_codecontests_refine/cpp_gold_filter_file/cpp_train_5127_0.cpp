#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int q = 1; q <= t; q++) {
    long long int n, k;
    cin >> n >> k;
    bool fl = true;
    for (long long int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        n += i;
        fl = false;
        break;
      }
    }
    if (fl) n += n;
    n += (k - 1) * 2;
    cout << n << "\n";
  }
  return 0;
}
