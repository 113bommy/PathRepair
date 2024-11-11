#include <bits/stdc++.h>
using namespace std;
long long n, k;
string s, p, mau = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
  cin >> n;
  if (n <= 200) {
    for (int i = 0; i < n; i++) cout << 'a';
    cout << " " << 'a' << endl;
  } else {
    k = 0;
    while (--n) {
      if (n % 2 != 0)
        s = s + mau[k++];
      else
        s = s + mau[k] + mau[k], k++, n /= 2;
    }
    for (long long i = 0; i <= k; ++i) p += mau[i];
    cout << s + p << " " << p << endl;
  }
}
