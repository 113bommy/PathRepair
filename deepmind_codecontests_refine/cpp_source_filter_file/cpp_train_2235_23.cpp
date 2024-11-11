#include <bits/stdc++.h>
using namespace std;
int todec(string s, int k) {
  int ans = 0;
  int coef = 1;
  for (int i = s.length() - 1; i >= 0; --i) {
    if (s[i] > '9')
      ans += (s[i] - 'A' + 10) * coef;
    else
      ans += (s[i] - '0') * coef;
    coef *= k;
  }
  return ans;
}
string tosys(int n, int k) {
  string ans;
  while (n) {
    ans += (n % k + '0');
    n /= k;
  }
  return ans;
}
int main() {
  string a, b;
  cin >> a >> b;
  int m1 = 2;
  int m2 = 2;
  for (int i = 0; i < a.length(); ++i) {
    int t;
    if (a[i] > '9')
      t = a[i] - 'A' + 10;
    else
      t = a[i] - '0';
    m1 = max(m1, t);
  }
  for (int i = 0; i < b.length(); ++i) {
    int t;
    if (b[i] > '9')
      t = b[i] - 'A' + 10;
    else
      t = b[i] - '0';
    m2 = max(m2, t);
  }
  int answ = max(m1 + 1, m2 + 1);
  int t1 = todec(a, answ);
  int t2 = todec(b, answ);
  int t = t1 + t2;
  string otv = tosys(t, answ);
  cout << otv.length() << endl;
  return 0;
}
