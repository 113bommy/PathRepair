#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  long long a = n % 10, b = n / 10;
  if (n == 0) {
    cout << "zero";
    return 0;
  }
  if (b == 1) {
    if (a == 0) cout << "ten";
    if (a == 1) cout << "eleven";
    if (a == 2) cout << "twelve";
    if (a == 3) cout << "thirteen";
    if (a == 4) cout << "fourteen";
    if (a == 5) cout << "fifteen";
    if (a == 6) cout << "sixteen";
    if (a == 7) cout << "seventeen";
    if (a == 8) cout << "eighteen";
    if (a == 9) cout << "nineteen";
    return 0;
  }
  if (b == 2) cout << "twenty";
  if (b == 3) cout << "thirty";
  if (b == 4) cout << "fourty";
  if (b == 5) cout << "fifty";
  if (b == 6) cout << "sixty";
  if (b == 7) cout << "seventy";
  if (b == 8) cout << "eighty";
  if (b == 9) cout << "ninety";
  if (n > 20 && n % 10 != 0) cout << "-";
  if (a == 1) cout << "one";
  if (a == 2) cout << "two";
  if (a == 3) cout << "three";
  if (a == 4) cout << "four";
  if (a == 5) cout << "five";
  if (a == 6) cout << "six";
  if (a == 7) cout << "seven";
  if (a == 8) cout << "eight";
  if (a == 9) cout << "nine";
  return 0;
}
