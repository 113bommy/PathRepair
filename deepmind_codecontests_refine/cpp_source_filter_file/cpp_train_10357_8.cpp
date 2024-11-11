#include <bits/stdc++.h>
using namespace std;
void nvastacnel(int &a) {
  while (a % 2 == 0) a /= 2;
  while (a % 3 == 0) a /= 3;
}
string y;
int main() {
  int n;
  cin >> n;
  string a1[] = {"zero", "one", "two",   "three", "four",
                 "five", "six", "seven", "eight", "nine"};
  string a2[] = {"",      "",      "twenty",  "thirty", "forty",
                 "fifty", "sixty", "seventy", "eighty", "ninety"};
  if (n <= 9)
    cout << a1[n];
  else if (n == 10)
    cout << "ten";
  else if (n == 11)
    cout << "eleven";
  else if (n == 12)
    cout << "twelve";
  else if (n == 13)
    cout << "thirteen";
  else if (n == 14)
    cout << "fourteen";
  else if (n == 15)
    cout << "fifteen";
  else if (n == 16)
    cout << "sixteen";
  else if (n == 17)
    cout << "seventeen";
  else if (n == 18)
    cout << "eightteen";
  else if (n == 19)
    cout << "nineteen";
  else {
    int sec = n % 10;
    int first = (n / 10) % 10;
    cout << a2[first];
    if (sec != 0) cout << '-' << a1[sec];
  }
  cout << endl;
  return 0;
}
