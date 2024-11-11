#include <bits/stdc++.h>
using namespace std;
int main() {
  string num;
  cin >> num;
  if (num.size() == 1) {
    if (num[0] == '0') cout << "zero";
    if (num[0] == '1') cout << "one";
    if (num[0] == 2) cout << "two";
    if (num[0] == '3') cout << "three";
    if (num[0] == '4') cout << "four";
    if (num[0] == '5') cout << "five";
    if (num[0] == '6') cout << "six";
    if (num[0] == '7') cout << "seven";
    if (num[0] == '8') cout << "eight";
    if (num[0] == '9') cout << "nine";
    cout << "\n";
    return 0;
  }
  if (num[0] == '1') {
    if (num[1] == '0') cout << "ten";
    if (num[1] == '1') cout << "eleven";
    if (num[1] == 2) cout << "twelve";
    if (num[1] == '3') cout << "thirteen";
    if (num[1] == '4') cout << "fourteen";
    if (num[1] == '5') cout << "fifteen";
    if (num[1] == '6') cout << "sixteen";
    if (num[1] == '7') cout << "seventeen";
    if (num[1] == '8') cout << "eighteen";
    if (num[1] == '9') cout << "nineteen";
    cout << "\n";
    return 0;
  }
  if (num[0] == '2') cout << "twenty";
  if (num[0] == '3') cout << "thirty";
  if (num[0] == '4') cout << "forty";
  if (num[0] == '5') cout << "fifty";
  if (num[0] == '6') cout << "sixty";
  if (num[0] == '7') cout << "seventy";
  if (num[0] == '8') cout << "eighty";
  if (num[0] == '9') cout << "ninety";
  if (num[1] == '1') cout << "-one";
  if (num[1] == 2) cout << "-two";
  if (num[1] == '3') cout << "-three";
  if (num[1] == '4') cout << "-four";
  if (num[1] == '5') cout << "-five";
  if (num[1] == '6') cout << "-six";
  if (num[1] == '7') cout << "-seven";
  if (num[1] == '8') cout << "-eight";
  if (num[0] == '9') cout << "-nine";
  cout << "\n";
  return 0;
}
