#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, a = 0, x;
  cin >> n >> x;
  n = 1 << n;
  if (x < n) {
    cout << n / 2 - 1 << endl;
  } else {
    cout << n << endl;
  }
  for (long long int i = 1; i < n; i++) {
    if (i < (i ^ x)) {
      cout << (i ^ a) << " ";
      a = i;
    }
  }
  return 0;
}
