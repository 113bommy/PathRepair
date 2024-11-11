#include <bits/stdc++.h>
using namespace std;
long long ans;
long long n, k;
int main() {
  cin >> n >> k;
  long long tmp;
  int ks = 0;
  int ts;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp % k == 0) {
      ts += tmp / k;
    } else {
      ts += tmp / k + 1;
    }
  }
  if (ts % 2 == 0) {
    cout << ts / 2;
  } else {
    cout << ts / 2 + 1 << "\n";
  }
  return 0;
}
