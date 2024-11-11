#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int iterr = 0;
  int sum0 = 0;
  if (n == 1 && s == "0") {
    cout << "No";
    return 0;
  }
  int j = 0;
  while (s[j] == '0') {
    j++;
  }
  if (j >= 1) {
    cout << "No";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1] && sum0 != 0) {
      if (sum0 != 1) {
        cout << "No";
        return 0;
      }
      sum0 = 0;
    }
    if (s[i - 1] == s[i] && s[i] == '1') {
      cout << "No";
      return 0;
    }
    if (s[i - 1] == s[i] && s[i] == '0') {
      sum0++;
    }
  }
  if (sum0 != 0) {
    if (sum0 >= 1) {
      cout << "No";
      return 0;
    }
    sum0 = 0;
  }
  cout << "Yes";
  return 0;
}
