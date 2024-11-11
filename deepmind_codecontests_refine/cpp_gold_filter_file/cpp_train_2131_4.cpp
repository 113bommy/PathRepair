#include <bits/stdc++.h>
using namespace std;
bool y(long long n) {
  while (n > 0) {
    long long temp = n % 10;
    if (temp == 8) return 1;
    n = n / 10;
  }
  return 0;
}
long long n, arr[101], c;
int main() {
  long long n, cnt = 1;
  ;
  cin >> n;
  while (1) {
    long long t = n + cnt;
    if (y(abs(t))) {
      cout << cnt;
      return 0;
    }
    cnt++;
  }
}
