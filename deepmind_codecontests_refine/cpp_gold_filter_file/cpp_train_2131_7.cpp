#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int arr[150];
bool check(long long num) {
  num = abs(num);
  while (num) {
    if (num % 10 == 8) return 1;
    num /= 10;
  }
  return 0;
}
int main() {
  cin >> n;
  k = 1;
  while (!check(n + k)) {
    k++;
  }
  cout << k << endl;
  return 0;
}
