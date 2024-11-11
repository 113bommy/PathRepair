#include <bits/stdc++.h>
using namespace std;
bool MySort(const pair<int, int>& A, const pair<int, int>& B) {
  return A.first > B.first;
}
int main() {
  int N;
  cin >> N;
  string Numbers[] = {"",     "one", "tow",   "three", "four",
                      "five", "six", "seven", "eight", "nine"};
  string Tens[] = {"",      "ten",   "twenty",  "thirty", "forty",
                   "fifty", "sixty", "seventy", "eighty", "ninety"};
  string Numbers2[] = {"",         "eleven",  "twelve",  "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nineteen"};
  if (N == 0)
    cout << "zero";
  else if (N % 10 == 0) {
    cout << Tens[N / 10];
  } else if (N < 10) {
    cout << Numbers[N];
  } else if (N < 20) {
    int X1 = N % 10;
    cout << Numbers2[X1];
  } else {
    int X1 = N / 10;
    int X2 = N % 10;
    cout << Tens[X1] << "-" << Numbers[X2];
  }
  return 0;
}
