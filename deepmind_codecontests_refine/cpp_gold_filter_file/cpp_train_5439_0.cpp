#include <bits/stdc++.h>
using namespace std;
int power(int n, int k) {
  if (k == 0) return 1;
  return n * power(n, k - 1);
}
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int k = 0;
    for (int j = 0; j < to_string(n).length(); j++) {
      if ((int)(n / power(10, j)) % 10 != 0) k++;
    }
    cout << k << endl;
    for (int j = 0; j < to_string(n).length(); j++) {
      if ((n / power(10, j)) % 10 != 0)
        cout << (int)(((n / power(10, j)) % 10) * power(10, j)) << ' ';
    }
    cout << endl;
  }
}
