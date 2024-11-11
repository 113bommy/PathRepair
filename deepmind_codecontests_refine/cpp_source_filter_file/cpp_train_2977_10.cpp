#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, res = 1;
  vector<int> v;
  cin >> n >> k;
  int n1 = n;
  if (k == 1) {
    cout << n;
  } else {
    for (int i = 2; i <= n / 2; i++) {
      if (n % i == 0) {
        v.push_back(n / (n / i));
        n /= i;
        i--;
      }
    }
    if (v.size() >= k) {
      for (int i = 0; i < k - 1; i++) {
        cout << v[i] << " ";
        res *= v[i];
      }
      cout << (n1 / res);
    } else {
      cout << "-1";
    }
  }
  return 0;
}
