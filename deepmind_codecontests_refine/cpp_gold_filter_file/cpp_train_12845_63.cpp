#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long maxOper = (n - 1) * n;
  maxOper /= 2;
  if (maxOper > k) {
    for (int i = 0; i < n; i++) {
      cout << 0 << " " << i << endl;
    }
  } else
    cout << "no solution";
  return 0;
}
