#include <bits/stdc++.h>
using namespace std;
long long po(int m, int n) {
  if (n == 1) return m;
  if (n == 0) return 1;
  if (n % 2) {
    long long te = po(m, n / 2);
    return te * te * m;
  } else {
    long long te = po(m, n / 2);
    return te * te;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    long long k;
    cin >> k;
    if (k == 1) {
      cout << "codeforces";
      return 0;
    }
    int num = 0;
    for (int i = 2; i < 60; i++) {
      if (po(i, 10) >= k) {
        num = i;
        break;
      }
    }
    int mn = num * 10;
    int b = 1;
    for (int i = 0; i <= 10; i++) {
      long long a = po(num, i) * po(num - 1, 10 - i);
      int len = (i * num) + ((10 - i) * (num - 1));
      if (a >= k && len < mn) {
        mn = len;
        b = i;
      }
    }
    string s = "codeforces";
    string te;
    for (int i = 0; i < b; i++)
      for (int j = 0; j < num; j++) te += s[i];
    for (int i = b; i < s.size(); i++)
      for (int j = 1; j < num; j++) te += s[i];
    cout << te;
  }
}
