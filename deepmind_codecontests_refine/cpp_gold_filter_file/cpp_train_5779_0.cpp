#include <bits/stdc++.h>
using namespace std;
bool prime(int n) {
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  int k;
  cin >> k;
  vector<int> p;
  if (prime(k)) {
    cout << 1 << endl << k;
    return 0;
  }
  int k1 = k;
  while (!prime(k1)) k1--;
  for (int i = 2; i < k; i++) {
    if (prime(i) && (prime(k - k1 - i) || k - k1 - i == 0)) {
      if (k - k1 - i == 0)
        cout << 2 << endl << i << " " << k1;
      else
        cout << 3 << endl << k - k1 - i << " " << i << ' ' << k1;
      return 0;
    }
  }
}
