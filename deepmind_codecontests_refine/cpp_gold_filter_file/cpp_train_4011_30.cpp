#include <bits/stdc++.h>
using namespace std;
string bin(long long int x) {
  string s;
  for (; x != 0; x = x / 2) {
    if (x % 2 == 0) {
      s = "0" + s;
    } else {
      s = "1" + s;
    }
  }
  int l = s.size();
  for (int i = 0; i != 40 - l; i++) {
    s = "0" + s;
  }
  return s;
}
int main() {
  long long int s, x;
  cin >> s >> x;
  string sum, exor;
  sum = bin(s);
  exor = bin(x);
  char carry = '0';
  long long int ans = 1;
  for (int i = 39; i != 0; i--) {
    if (exor[i] == '1') {
      if (carry == '0' && sum[i] == '0' || carry == '1' && sum[i] == '1') {
        cout << 0 << endl;
        return 0;
      } else {
        ans *= 2;
      }
    } else {
      if (carry == '0' && sum[i] == '1' || carry == '1' && sum[i] == '0') {
        cout << 0 << endl;
        return 0;
      } else {
        if (exor[i - 1] == '0' && sum[i - 1] == '1' ||
            exor[i - 1] == '1' && sum[i - 1] == '0') {
          carry = '1';
        } else {
          carry = '0';
        }
      }
    }
  }
  if (carry == '0') {
    if (exor[0] != sum[0]) {
      cout << 0 << endl;
      return 0;
    } else {
      if (exor[0] == '1') {
        ans *= 2;
      }
    }
  } else {
    if (exor[0] == sum[0]) {
      cout << 0 << endl;
      return 0;
    }
  }
  if (s == x) {
    ans = ans - 2;
  }
  cout << ans << endl;
}
