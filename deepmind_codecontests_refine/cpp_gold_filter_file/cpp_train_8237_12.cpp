#include <bits/stdc++.h>
using namespace std;
long long pow_values[500010];
int main() {
  pow_values[0] = 1;
  for (int i = 1; i < 500010; i++) {
    pow_values[i] = pow_values[i - 1] * 3;
    if (pow_values[i] >= 1000000009) {
      pow_values[i] %= 1000000009;
    }
  }
  string s, t;
  cin >> s >> t;
  int br0 = 0, br1 = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      br0++;
    } else {
      br1++;
    }
  }
  int n = t.size();
  long long hsh1 = 0, hsh2 = 0;
  int br = 0;
  for (int i = 0, j = n - 1; i < n - 1; i++, j--) {
    hsh1 += (t[i] - '0' + 1) * pow_values[i];
    if (hsh1 >= 1000000009) {
      hsh1 %= 1000000009;
    }
    hsh2 *= 3;
    hsh2 += (t[j] - '0' + 1);
    if (hsh2 >= 1000000009) {
      hsh2 %= 1000000009;
    }
    if (hsh1 == hsh2) {
      br = i + 1;
    }
  }
  int i = 0;
  for (i = 0; i < br; i++) {
    if (t[i] == '0' && br0 > 0) {
      cout << 0;
      br0--;
    } else if (t[i] == '1' && br1 > 0) {
      cout << 1;
      br1--;
    } else {
      break;
    }
  }
  for (; i < s.size();) {
    bool ind = false;
    for (int j = br; j < n; j++, i++) {
      if (t[j] == '0' && br0 > 0) {
        cout << 0;
        br0--;
      } else if (t[j] == '1' && br1 > 0) {
        cout << 1;
        br1--;
      } else {
        ind = true;
        break;
      }
    }
    if (ind) {
      break;
    }
  }
  while (br0 > 0) {
    cout << 0;
    br0--;
  }
  while (br1 > 0) {
    cout << 1;
    br1--;
  }
  cout << "\n";
  return 0;
}
