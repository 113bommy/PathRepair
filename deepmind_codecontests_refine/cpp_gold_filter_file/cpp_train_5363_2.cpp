#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, i = 1, j, k, temp = 0, flag = 0;
  string s;
  cin >> n >> p >> q;
  cin >> s;
  if (n % p == 0 && n != p + q || n % q == 0 && n != p + q) {
    if (n % p == 0) {
      cout << n / p << endl;
      for (i = 0; i < n; i++) {
        cout << s[i];
        if ((i + 1) % p == 0) cout << endl;
      }
    } else {
      cout << n / q << endl;
      for (i = 0; i < n; i++) {
        cout << s[i];
        if ((i + 1) % q == 0) cout << endl;
      }
    }
  } else {
    while (1) {
      j = n - (p * i);
      k = n - (q * i);
      if (j < 0 || k < 0) break;
      if (j % q == 0) {
        temp = 1;
        break;
      }
      if (k % p == 0) {
        flag = 1;
        break;
      }
      if (j < 0 && k < 0) break;
      i++;
    }
    if (temp == 1) {
      cout << i + (j / q) << endl;
      for (int x = 0; x < i * p; x++) {
        cout << s[x];
        if ((x + 1) % p == 0) cout << endl;
      }
      j = 1;
      for (int x = i * p; x < n; x++) {
        cout << s[x];
        if ((j) % q == 0) cout << endl;
        j++;
      }
    } else if (flag == 1) {
      cout << i + (k / p) << endl;
      for (int x = 0; x < i * q; x++) {
        cout << s[x];
        if ((x + 1) % q == 0) cout << endl;
      }
      j = 1;
      for (int x = i * q; x < n; x++) {
        cout << s[x];
        if ((j) % p == 0) cout << endl;
        j++;
      }
    } else {
      cout << "-1" << endl;
    }
  }
}
