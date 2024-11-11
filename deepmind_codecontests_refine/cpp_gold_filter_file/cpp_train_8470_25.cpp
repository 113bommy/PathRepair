#include <bits/stdc++.h>
using namespace std;
int countdistinct(int n) {
  int ab[10] = {0};
  int count = 0;
  while (n != 0) {
    int r = n % 10;
    ab[r] = 1;
    n = n / 10;
  }
  for (int i = 0; i < 10; i++) {
    if (ab[i] == 1) {
      count++;
    }
  }
  return count;
}
int countdigits(int n) {
  int c = 0;
  while (n != 0) {
    c++;
    n = n / 10;
  }
  return c;
}
int countdistinctno(int n) {
  while (n < INT_MAX) {
    int distinctdigits = countdistinct(n + 1);
    int total_digits = countdigits(n + 1);
    if (distinctdigits == total_digits) {
      return n + 1;
    } else {
      n++;
    }
  }
  return -1;
}
int main() {
  int n;
  cin >> n;
  cout << countdistinctno(n) << endl;
}
