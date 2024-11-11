#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string num;
  cin >> n >> k;
  cin >> num;
  if (k == 0) {
    cout << num << endl;
    return 0;
  }
  if (num.size() != n) {
    return 0;
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (k == 0) {
    cout << num << endl;
    return 0;
  }
  if (k > num.size()) {
    cout << num << endl;
    return 0;
  }
  if (k > n) {
    cout << num << endl;
  }
  if (num[0] != '1') {
    num[0] = '1';
    k--;
  }
  for (int i = 1; i <= k and i < n; ++i) {
    if (num[i] != '0') {
      num[i] = '0';
    } else {
      k = k + 1;
    }
  }
  cout << num << endl;
  return 0;
}
