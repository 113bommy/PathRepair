#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  string a, input;
  cin >> input;
  n = input.length();
  for (int i = 1; i < n; i++) {
    if (input[i] == input[i - 1]) {
      ans = ans + 1;
      if (ans == 7) {
        cout << "YES" << endl;
        return 0;
      }
    } else
      ans = 0;
  }
  cout << "NO" << endl;
  return 0;
}
