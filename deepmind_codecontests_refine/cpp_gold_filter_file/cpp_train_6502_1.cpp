#include <bits/stdc++.h>
using namespace std;
unsigned long long int combi(unsigned long long int num) {
  unsigned long long int ans;
  ans = (num * (num - 1)) / 2;
  return ans;
}
int main() {
  unsigned long long int i, j, rem, ans, a, b, mx, mi, sum, res, div;
  cin >> a >> b;
  res = a - (b - 1);
  mx = (res * (res - 1)) / 2;
  if (b == 1)
    cout << mx << " " << mx << endl;
  else {
    if ((a / 2) < b) {
      ans = 0;
      div = a / 2;
      if (a % 2) ans = 1;
      res = b - div;
      mi = div - res + ans;
    } else if ((a / 2) == b)
      mi = b;
    else {
      res = a / b;
      if (res * b == a)
        mi = combi(res) * b;
      else {
        sum = 0;
        rem = a - (res * b);
        ans = b - rem;
        sum = sum + combi(res) * ans;
        sum += combi(res + 1) * rem;
        mi = sum;
      }
    }
    cout << mi << " " << mx << endl;
  }
  return 0;
}
