#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << 1;
  }
  if (n == 3) {
    cout << "1  2" << endl;
    cout << "2 11" << endl;
  }
  if (n == 4) {
    cout << "1  2  3" << endl;
    cout << "2 10 12" << endl;
    cout << "3 12 21" << endl;
  }
  if (n == 5) {
    cout << "1  2  3  4" << endl;
    cout << "2  4 11 13" << endl;
    cout << "3 11 14 22" << endl;
    cout << "4 13 22 31" << endl;
  }
  if (n == 6) {
    cout << "1  2  3  4  5" << endl;
    cout << "2  4 10 12 14" << endl;
    cout << "3 10 13 20 23" << endl;
    cout << "4 12 20 24 32" << endl;
    cout << "5 14 23 32 41" << endl;
  }
  if (n == 7) {
    cout << "1  2  3  4  5  6" << endl;
    cout << "2  4  6 11 13 15" << endl;
    cout << "3  6 12 15 21 24" << endl;
    cout << "4 11 15 22 26 33" << endl;
    cout << "5 13 21 26 34 42" << endl;
    cout << "6 15 24 22 42 51" << endl;
  }
  if (n == 8) {
    cout << "1  2  3  4  5  6  7" << endl;
    cout << "2  4  6 10 12 14 16" << endl;
    cout << "3  6 11 14 17 22 25" << endl;
    cout << "4 10 14 20 24 30 34" << endl;
    cout << "5 12 17 24 31 36 43" << endl;
    cout << "6 14 22 30 36 44 52" << endl;
    cout << "7 16 25 34 43 52 61" << endl;
  }
  if (n == 9) {
    cout << "1  2  3  4  5  6  7  8" << endl;
    cout << "2  4  6  8 11 13 15 17" << endl;
    cout << "3  6 10 13 16 20 23 26" << endl;
    cout << "4  8 13 17 22 26 31 35" << endl;
    cout << "5 11 16 22 27 33 38 44" << endl;
    cout << "6 13 20 26 33 40 46 53" << endl;
    cout << "7 15 23 31 38 46 54 62" << endl;
    cout << "8 17 26 35 44 53 62 64" << endl;
  }
  if (n == 10) {
    cout << "1  2  3  4  5  6  7  8  9" << endl;
    cout << "2  4  6  8 10 12 14 16 18" << endl;
    cout << "3  6  9 12 15 18 21 24 27" << endl;
    cout << "4  8 12 16 20 24 28 32 36" << endl;
    cout << "5 10 15 20 25 30 35 40 45" << endl;
    cout << "6 12 18 24 30 36 42 48 54" << endl;
    cout << "7 14 21 28 35 42 49 56 63" << endl;
    cout << "8 16 24 32 40 48 56 64 72" << endl;
    cout << "9 18 27 36 45 54 63 72 81" << endl;
  }
  return 0;
}
