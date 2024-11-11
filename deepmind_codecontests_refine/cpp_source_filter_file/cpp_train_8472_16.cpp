#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, n;
  cin >> n >> k;
  if (k <= (n - 1) / 2) {
    cout << k * 2 - 1;
  } else {
    k -= (n + 1) / 2;
    cout << k * 2 - 1;
  }
}
