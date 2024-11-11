#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, sum = 0;
  cin >> n >> k;
  int l[n], r[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    sum += r[i] - l[i] + 1;
  }
  if (sum % k == 0)
    cout << "0";
  else
    cout << k - (sum % k);
  return 0;
}
