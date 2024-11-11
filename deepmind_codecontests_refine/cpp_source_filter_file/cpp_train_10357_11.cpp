#include <bits/stdc++.h>
using namespace std;
string unidades(char c) {
  if (c == '0') return "zero";
  if (c == '1') return "one";
  if (c == '2') return "two";
  if (c == '3') return "three";
  if (c == '4') return "four";
  if (c == '5') return "five";
  if (c == '6') return "six";
  if (c == '7') return "seven";
  if (c == '8') return "eight";
  if (c == '9') return "nine";
}
string decenas(char c) {
  if (c == '2') return "twenty";
  if (c == '3') return "thirty";
  if (c == '4') return "fourty";
  if (c == '5') return "fifty";
  if (c == '6') return "sixty";
  if (c == '7') return "seventy";
  if (c == '8') return "eighty";
  if (c == '9') return "ninety";
}
int main() {
  string n;
  cin >> n;
  if (n == "10")
    cout << "ten";
  else if (n == "11")
    cout << "eleven";
  else if (n == "12")
    cout << "twelve";
  else if (n == "13")
    cout << "thirteen";
  else if (n == "14")
    cout << "fourteen";
  else if (n == "15")
    cout << "fifteen";
  else if (n == "16")
    cout << "sixteen";
  else if (n == "17")
    cout << "seventeen";
  else if (n == "18")
    cout << "eighteen";
  else if (n == "19")
    cout << "nineteen";
  else {
    if (n.size() == 2) {
      cout << decenas(n[0]);
      if (n[1] != '0') cout << "-" << unidades(n[1]);
    } else
      cout << unidades(n[0]);
  }
  cout << "\n";
  return 0;
}
