#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; ++j) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = int(s[n - 1]) - 48;
    for (int i = n - 2; i >= 0; --i) {
      if (s[i] >= '1' && s[i] <= '9') {
        sum += (int(s[i]) - 48) + 1;
      }
    }
    cout << sum;
  }
  return 0;
}
