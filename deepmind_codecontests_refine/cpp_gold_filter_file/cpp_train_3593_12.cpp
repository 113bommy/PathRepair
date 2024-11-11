#include <bits/stdc++.h>
using namespace std;
int a[27];
bool Check(int c, int k) {
  bool ans = 1;
  for (int i = 1; i <= c && ans == 1; i++) ans = (a[i] % k == 0);
  for (int i = 1, oddCnt = 0; i <= c && ans == 1; i++) {
    int x = a[i] / k;
    oddCnt += (x % 2);
    ans = (k % 2 == 0 || (k % 2 == 1 && oddCnt <= 1));
  }
  return ans;
}
string GetString(int c, int k) {
  string s;
  if (k == 0) {
    for (int i = 1; i <= c; i++) {
      int x = a[i];
      while (x--) s.push_back('a' + i - 1);
    }
  } else {
    for (int i = 1; i <= c; i++) a[i] /= k;
    for (int i = 1; i <= c; i++) {
      int x = a[i] / 2;
      while (x--) s.push_back('a' + i - 1);
    }
    for (int i = 1; i <= c; i++) {
      int x = a[i] % 2;
      while (x--) s.push_back('a' + i - 1);
    }
    for (int i = c; i >= 0; i--) {
      int x = a[i] / 2;
      while (x--) s.push_back('a' + i - 1);
    }
  }
  return s;
}
int main() {
  int c, k = 0;
  cin >> c;
  for (int i = 1; i <= c; i++) {
    cin >> a[i];
    k += a[i];
  }
  for (; k > 0 && Check(c, k) == 0; k--)
    ;
  cout << k << '\n';
  if (k % 2 == 0) k /= 2;
  string s = GetString(c, k);
  k = max(1, k);
  while (k--) cout << s;
  cout << '\n';
  return 0;
}
