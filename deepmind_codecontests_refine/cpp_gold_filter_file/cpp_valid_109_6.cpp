#include <bits/stdc++.h>
using namespace std;
string s;
int tt, k, n;
int main() {
  cin >> tt;
  while (tt--) {
    long long d = 0, tong = 0;
    cin >> n;
    cin >> s;
    s = s + '0';
    for (int i = 0; i <= n - 1; i++) {
      if (s[n - 1] != '0') {
        tong = tong + int(s[n - 1]) - 48;
        s[n - 1] = '0';
      }
      if (s[i] != '0' && s[n - 1] == '0') {
        d++;
        swap(s[i], s[n]);
        k = int(s[n]) - 48;
        s[n] = 0;
        tong = tong + k;
      }
    }
    cout << d + tong << endl;
  }
}
