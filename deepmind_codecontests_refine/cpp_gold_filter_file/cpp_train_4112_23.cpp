#include <bits/stdc++.h>
double eps = 1e-9;
using namespace std;
long long pow(int x) {
  int ans = 1;
  while (x--) {
    ans *= 10;
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int digits = 0;
  int num = n;
  while (num) {
    digits++;
    num /= 10;
  }
  long long total = 0;
  for (int i = 1; i < digits; ++i) {
    total += (pow(i - 1) * 9) * i;
  }
  total += (n - pow(digits - 1) + 1) * digits;
  cout << total;
  return 0;
}
