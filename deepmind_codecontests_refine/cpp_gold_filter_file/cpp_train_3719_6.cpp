#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> dig(10, 1);
  int i;
  for (i = 1; i < 10; i++) {
    dig[i] = pow(2, i - 1) + dig[i - 1];
  }
  int n;
  cin >> n;
  string s = to_string(n);
  n = s.length();
  bool flag = false;
  int sum = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '1') {
      sum += dig[n - 1 - i];
    } else if (s[i] == '0') {
      sum += 0;
    } else {
      sum += dig[n - i];
      flag = true;
      break;
    }
  }
  if (flag) {
    cout << sum - 1;
  } else {
    cout << sum;
  }
}
