#include <bits/stdc++.h>
using namespace std;
long long powll(long long a, long long e) {
  long long ret = 1;
  for (int i = 0; i < e; i++) {
    ret *= a;
  }
  return ret;
}
long long remove0(long long n) {
  long long ret = 0;
  for (int i = 0; n;) {
    if (n % 10 != 0) {
      ret += (n % 10) * powll(10, i++);
    }
    n /= 10;
  }
  return ret;
}
int main() {
  long long a, b, ans;
  while (cin >> a >> b) {
    bool flag = false;
    ans = a + b;
    a = remove0(a);
    b = remove0(b);
    ans = remove0(ans);
    if (ans == a + b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
