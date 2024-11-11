#include <bits/stdc++.h>
using namespace std;
int check_bills(int num, int count) {
  if (num >= 100) {
    while (num >= 100) {
      num -= 100;
      count++;
    }
    check_bills(num, count);
  }
  if (num >= 20) {
    while (num >= 20) {
      num -= 20;
      count++;
    }
    check_bills(num, count);
  }
  if (num >= 10) {
    while (num >= 10) {
      num -= 10;
      count++;
    }
    check_bills(num, count);
  }
  if (num >= 5) {
    while (num >= 5) {
      num -= 5;
      count++;
    }
    check_bills(num, count);
  }
  if (num >= 1) {
    while (num >= 1) {
      num -= 1;
      count++;
    }
  }
  return count;
}
int min_bills(int num) {
  if (num % 100 == 0) {
    return num / 100;
  } else {
    int count = 0;
    return check_bills(num, count);
  }
}
int main() {
  int num;
  cin >> num;
  cout << min_bills(num) << endl;
  return 0;
}
