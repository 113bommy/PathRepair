#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T, n, m, i, k, l;
  map<int, string> word;
  word[0] = "zero";
  word[1] = "one";
  word[2] = "two";
  word[3] = "three";
  word[4] = "four";
  word[5] = "five";
  word[6] = "six";
  word[7] = "seven";
  word[8] = "eight";
  word[9] = "nine";
  word[10] = "ten";
  word[11] = "eleven";
  word[12] = "twelve";
  word[13] = "thirteen";
  word[14] = "fourteen";
  word[15] = "fifteen";
  word[16] = "sixteen";
  word[17] = "seventeen";
  word[18] = "eighteen";
  word[19] = "nineteen";
  word[20] = "twenty";
  word[30] = "thirty";
  word[40] = "forty";
  word[50] = "fifty";
  word[60] = "sixty";
  word[70] = "seventy";
  word[80] = "eighty";
  word[90] = "ninety";
  cin >> n;
  if (n >= 0 && n <= 20)
    cout << word[n] << endl;
  else if (n == 30 || n == 40 || n == 50 || n == 60 || n == 70 || n == 80 ||
           n == 90)
    cout << word[n];
  else {
    k = n % 10;
    n = n - k;
    cout << word[n] << "-" << word[k] << endl;
  }
}
