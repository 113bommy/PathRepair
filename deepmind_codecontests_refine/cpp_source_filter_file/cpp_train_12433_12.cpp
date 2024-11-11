#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int winX = 0, winO = 0, countX = 0, countO = 0;
  countX = count(s1.begin(), s1.end(), 'X') + count(s2.begin(), s2.end(), 'X') +
           count(s3.begin(), s3.end(), 'X');
  countO = count(s1.begin(), s1.end(), '0') + count(s2.begin(), s2.end(), '0') +
           count(s3.begin(), s3.end(), '0');
  int countS = count(s1.begin(), s1.end(), '.') +
               count(s2.begin(), s2.end(), '.') +
               count(s3.begin(), s3.end(), '.');
  if (countX - countO == 1 || countX - countO == 0) {
    if (s1 == "XXX") {
      winX++;
    }
    if (s1 == "000") {
      winO++;
    }
    if (s2 == "XXX") {
      winX++;
    }
    if (s2 == "000") {
      winO++;
    }
    if (s3 == "XXX") {
      winX++;
    }
    if (s3 == "000") {
      winO++;
    }
    if ((s1[0] == 'X' && s2[1] == 'X' && s3[2] == 'X')) {
      winX++;
    }
    if ((s1[0] == '0' && s2[1] == '0' && s3[2] == '0')) {
      winO++;
    }
    if ((s1[2] == 'X' && s2[1] == 'X' && s3[0] == 'X')) {
      winX++;
    }
    if ((s1[2] == '0' && s2[1] == '0' && s3[0] == '0')) {
      winX++;
    }
    if ((s1[0] == 'X' && s2[0] == 'X' && s3[0] == 'X')) {
      winX++;
    }
    if ((s1[0] == '0' && s2[0] == '0' && s3[0] == '0')) {
      winO++;
    }
    if ((s1[1] == '0' && s2[1] == '0' && s3[1] == '0')) {
      winO++;
    }
    if ((s1[1] == 'X' && s2[1] == 'X' && s3[1] == 'X')) {
      winX++;
    }
    if ((s1[2] == 'X' && s2[2] == 'X' && s3[2] == 'X')) {
      winX++;
    }
    if ((s1[2] == '0' && s2[2] == '0' && s3[2] == '0')) {
      winO++;
    }
    if (winX == 1 && winO == 0 && countX - countO == 1) {
      cout << "the first player won\n";
    } else if (winX == 2 && countX - countO == 1) {
      cout << "the first player won\n";
    } else if (winO == 1 && winX == 0 && countX == countO) {
      cout << "the second player won\n";
    } else if (winX == 0 && winO == 0 && countS == 0) {
      cout << "draw\n";
    } else if (winX > 1) {
      cout << "illegal\n";
    } else if (winO > 1) {
      cout << "illegal\n";
    } else if (winX == 1 && winO == 1) {
      cout << "illegal\n";
    } else if (countS > 0 && winX == 0 && winO == 0) {
      if (countX == countO) {
        cout << "first\n";
      } else {
        cout << "second\n";
      }
    } else {
      cout << "illegal\n";
    }
  } else {
    cout << "illegal\n";
  }
  return 0;
}
