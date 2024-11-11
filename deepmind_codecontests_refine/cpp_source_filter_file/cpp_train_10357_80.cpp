#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, string> record;
  record[0] = "zero";
  record[10] = "ten";
  record[11] = "eleven";
  record[12] = "twelve";
  record[13] = "thirteen";
  record[14] = "fourteen";
  record[15] = "fifteen";
  record[16] = "sixteen";
  record[17] = "seventeen";
  record[18] = "eighteen";
  record[19] = "nineteen";
  map<int, string> record2;
  map<int, string> record3;
  record2[1] = "one";
  record2[2] = "two";
  record2[3] = "three";
  record2[4] = "four";
  record2[5] = "five";
  record2[6] = "six";
  record2[7] = "seven";
  record2[8] = "eight";
  record2[9] = "nine";
  record3[2] = "twenty";
  record3[3] = "thirty";
  record3[4] = "fourty";
  record3[5] = "fifty";
  record3[6] = "sixty";
  record3[7] = "seventy";
  record3[8] = "eighty";
  record3[9] = "ninety";
  int n;
  cin >> n;
  if (record.find(n) != record.end()) {
    cout << record[n] << endl;
    return 0;
  }
  int x = n / 10;
  int y = n % 10;
  if (x == 0) {
    cout << record2[y] << endl;
    return 0;
  } else if (y == 0) {
    cout << record3[x] << endl;
    return 0;
  } else {
    cout << record3[x] << "-" << record2[y] << endl;
    return 0;
  }
}
