#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, ans, rest, temp1, temp2;
  cin >> n;
  cin >> a >> b >> c;
  ans = 0;
  rest = 0;
  temp1 = 0;
  temp2 = 0;
  if (b - c > a) {
    ans = (n - b) / a;
    rest = (n - b) % a + b;
  } else {
    if (n >= b) {
      ans += (n - b) / (b - c);
      rest = (n - b) % (b - c) + b;
    }
  }
  temp1 = rest / a;
  if (rest >= b) {
    rest -= b;
    rest += c;
    temp2++;
  }
  temp2 += rest / a;
  if (temp1 > temp2) {
    ans += temp1;
  } else {
    ans += temp2;
  }
  cout << ans;
  return 0;
}
