#include <bits/stdc++.h>
using namespace std;
bool check(long long int y) {
  long long int i = 0;
  long long int b[9], str[10];
  for (long long int i = 0; i <= 9; i++) {
    b[i] = 0;
    str[i] = 0;
  }
  while (y > 0) {
    b[i] = y % 10;
    str[b[i]]++;
    y = y / 10;
    i++;
  }
  for (long long int i = 0; i <= 9; i++) {
    if (str[i] > 1) {
      return false;
    }
  }
  return true;
}
int main() {
  long long int n, i;
  cin >> n;
  for (i = n + 1; i <= 1000000; i++) {
    if (check(i)) {
      break;
    }
  }
  cout << i << endl;
  return 0;
}
