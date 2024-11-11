#include <bits/stdc++.h>
using namespace std;
bool numbers[10];
bool cnt(int n) {
  while (n != 0) {
    if (numbers[n % 10]) return true;
    n /= 10;
  }
  return false;
}
int div(int n) {
  int len = sqrt(n), sum = 0;
  for (int i = 1; i <= len; i++) {
    if (n % i == 0) {
      if (n % i == i) {
        if (cnt(i)) sum++;
      } else {
        if (cnt(i)) sum++;
        if (cnt(n / i)) sum++;
      }
    }
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, temp;
  cin >> n;
  temp = n;
  while (temp != 0) {
    numbers[temp % 10] = true;
    temp /= 10;
  }
  cout << div(n) << endl;
  return 0;
}
