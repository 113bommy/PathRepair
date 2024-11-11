#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, aa, bb;
  cin >> n;
  a = n / 10;
  b = n % 10;
  if (a == 0) {
    aa = 2;
  } else if (a == 1) {
    aa = 6;
  } else if (a == 2) {
    aa = 2;
  } else if (a == 3) {
    aa = 3;
  } else if (a == 4) {
    aa = 3;
  } else if (a == 5) {
    aa = 4;
  } else if (a == 6) {
    aa = 2;
  } else if (a == 7) {
    aa = 5;
  } else if (a == 8) {
    aa = 1;
  } else {
    aa = 2;
  }
  if (b == 0) {
    bb = 2;
  } else if (b == 1) {
    bb = 6;
  } else if (b == 2) {
    bb = 2;
  } else if (b == 3) {
    bb = 3;
  } else if (b == 4) {
    bb = 3;
  } else if (b == 5) {
    bb = 4;
  } else if (b == 6) {
    bb = 2;
  } else if (b == 7) {
    bb = 5;
  } else if (b == 8) {
    bb = 1;
  } else {
    bb = 2;
  }
  cout << aa * bb;
  return 0;
}
