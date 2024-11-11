#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, tot, i;
  cin >> n >> k;
  tot = n * (n - 1) / 2;
  if (tot <= k) {
    cout << "no solution";
  } else {
    for (i = 0; i < n; i++) {
      cout << 0 << " " << i << endl;
    }
  }
  return 0;
}
