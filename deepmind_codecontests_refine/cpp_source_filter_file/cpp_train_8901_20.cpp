#include <bits/stdc++.h>
using namespace std;
int dig(long long int n) {
  long long int c = 0;
  while (n) {
    n = n / 10;
    c++;
  }
  return c;
}
int segment(long long int a, long long int b) {
  long long int n, l;
  long long int sum = 0;
  for (int i = a; i <= b; i++) {
    l = i;
    if (dig(i) == 1) {
      switch (i) {
        case 0:
          sum += 6;
          break;
        case 1:
          sum += 2;
          break;
        case 2:
          sum += 5;
          break;
        case 3:
          sum += 5;
          break;
        case 4:
          sum += 4;
          break;
        case 5:
          sum += 6;
          break;
        case 6:
          sum += 6;
          break;
        case 7:
          sum += 3;
          break;
        case 8:
          sum += 7;
          break;
        case 9:
          sum += 6;
          break;
      }
    } else {
      while (l) {
        n = l % 10;
        switch (n) {
          case 0:
            sum += 6;
            break;
          case 1:
            sum += 2;
            break;
          case 2:
            sum += 5;
            break;
          case 3:
            sum += 5;
            break;
          case 4:
            sum += 4;
            break;
          case 5:
            sum += 6;
            break;
          case 6:
            sum += 6;
            break;
          case 7:
            sum += 3;
            break;
          case 8:
            sum += 7;
            break;
          case 9:
            sum += 6;
            break;
        }
        l = l / 10;
      }
    }
  }
  return sum;
}
int main() {
  long long int a, b;
  cin >> a >> b;
  cout << segment(a, b);
  return 0;
}
