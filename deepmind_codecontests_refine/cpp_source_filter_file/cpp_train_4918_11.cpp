#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, a, b, i, m;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    if (b == 1) s = "a";
    if (b == 2) s = "ab";
    if (b == 3) s = "abc";
    if (b == 4) s = "abcd";
    if (b == 5) s = "abcde";
    if (b == 6) s = "abcdef";
    if (b == 7) s = "abcdefg";
    if (b == 8) s = "abcdefgh";
    if (b == 9) s = "abcdefghi";
    if (b == 10) s = "abcdefghij";
    if (b == 11) s = "abcdefghijk";
    if (b == 12) s = "abcdefghijkl";
    if (b == 13) s = "abcdefghijklm";
    if (b == 14) s = "abcdefghijklmn";
    if (b == 15) s = "abcdefghijklmno";
    if (b == 16) s = "abcdefghijklmnop";
    if (b == 17) s = "abcdefghijklmnopq";
    if (b == 18) s = "abcdefghijklmnopqr";
    if (b == 19) s = "abcdefghijklmnopqrs";
    if (b == 20) s = "abcdefghijklmnopqrst";
    if (b == 21) s = "abcdefghijklmnopqrstu";
    if (b == 22) s = "abcdefghijklmnopqrstuv";
    if (b == 23) s = "abcdefghijklmnopqrstuvw";
    if (b == 24) s = "abcdefghijklmnopqrstuvx";
    if (b == 25) s = "abcdefghijklmnopqrstuvxy";
    if (b == 26) s = "abcdefghijklmnopqrstuvxyz";
    m = n % b;
    for (i = 1; i <= (n / b); i++) {
      cout << s;
    }
    if (m != 0) {
      if (m == 1) s = "a";
      if (m == 2) s = "ab";
      if (m == 3) s = "abc";
      if (m == 4) s = "abcd";
      if (m == 5) s = "abcde";
      if (m == 6) s = "abcdef";
      if (m == 7) s = "abcdefg";
      if (m == 8) s = "abcdefgh";
      if (m == 9) s = "abcdefghi";
      if (m == 10) s = "abcdefghij";
      if (m == 11) s = "abcdefghijk";
      if (m == 12) s = "abcdefghijkl";
      if (m == 13) s = "abcdefghijklm";
      if (m == 14) s = "abcdefghijklmn";
      if (m == 15) s = "abcdefghijklmno";
      if (m == 16) s = "abcdefghijklmnop";
      if (m == 17) s = "abcdefghijklmnopq";
      if (m == 18) s = "abcdefghijklmnopqr";
      if (m == 19) s = "abcdefghijklmnopqrs";
      if (m == 20) s = "abcdefghijklmnopqrst";
      if (m == 21) s = "abcdefghijklmnopqrstu";
      if (m == 22) s = "abcdefghijklmnopqrstuv";
      if (m == 23) s = "abcdefghijklmnopqrstuvw";
      if (m == 24) s = "abcdefghijklmnopqrstuvx";
      if (m == 25) s = "abcdefghijklmnopqrstuvxy";
      if (m == 26) s = "abcdefghijklmnopqrstuvxyz";
      cout << s;
    }
    cout << endl;
    s.clear();
  }
  return 0;
}
