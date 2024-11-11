#include <bits/stdc++.h>
using namespace std;
long long int cal(long long int a) {
  int x = 0;
  long long int b = a;
  while (b != 0) {
    x += b % 10;
    b = b / 10;
  }
  return a - x;
}
int main() {
  long long int n, s;
  cin >> n >> s;
  long long int start = 0, end = n;
  long long b = 0;
  if (cal(end) < s) {
    cout << 0 << endl;
    return 0;
  }
  while (start <= end) {
    b = (end + start) / 2;
    if (cal(b) >= s) {
      end = b - 1;
    } else {
      start = ++b;
    }
  }
  cout << n - b + 1 << endl;
  return 0;
}
