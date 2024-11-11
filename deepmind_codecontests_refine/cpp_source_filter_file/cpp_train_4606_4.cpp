#include <bits/stdc++.h>
using namespace std;
string to_binary_string(unsigned int n) {
  string result;
  do {
    char pl = ('0' + (n % 2));
    result = pl + result;
    n = n / 2;
  } while (n > 0);
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, n2;
  string s, s2;
  cin >> n;
  n2 = n;
  s = to_binary_string(n);
  while (s2.size() + s.size() < 6) {
    s2.push_back('0');
  }
  s2 += s;
  string s3 = s2;
  s3[0] = s2[0];
  s3[1] = s2[5];
  s3[2] = s2[3];
  s3[3] = s2[1];
  s3[4] = s2[4];
  s3[5] = s2[2];
  n2 = stoi(s3);
  int i = 0;
  int digitT = n2;
  int rest = 1;
  while (digitT >= 1 && rest <= 1) {
    rest = digitT % 10;
    digitT = digitT / 10;
    i = i + 1;
  }
  int two = 1;
  int sum = 0;
  digitT = n2;
  while (i > 0) {
    rest = digitT % 10;
    digitT = digitT / 10;
    sum = sum + rest * two;
    two = two * 2;
    i = i - 1;
  }
  cout << sum;
  return 0;
}
