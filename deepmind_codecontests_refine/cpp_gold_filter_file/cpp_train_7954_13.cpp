#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long k, t = 0, r = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '^') k = i;
  }
  for (int i = k - 1; i >= 0; i--) {
    if (s[i] >= '1' && s[i] <= '9') {
      int l = s[i] - '0';
      t += (l * (k - i));
    }
  }
  for (int i = k + 1; i < s.length(); i++) {
    if (s[i] >= '1' && s[i] <= '9') {
      int m = s[i] - '0';
      r += (m * (i - k));
    }
  }
  if (r == t)
    cout << "balance" << endl;
  else if (r > t)
    cout << "right" << endl;
  else
    cout << "left" << endl;
}
