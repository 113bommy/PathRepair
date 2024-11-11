#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string num;
  cin >> num;
  if (n == 1 && k > 0) {
    cout << '0';
    return 0;
  }
  if (num[0] != '1' && k > 0) {
    k--;
    num[0] = '1';
  }
  for (int i = 1; i < n; i++) {
    if (k > 0) {
      if (num[i] != '0') {
        num[i] = '0';
        k = k - 1;
      }
    } else {
      break;
    }
  }
  cout << num;
  return 0;
}
