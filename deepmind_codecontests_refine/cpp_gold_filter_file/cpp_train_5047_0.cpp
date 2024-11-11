#include <bits/stdc++.h>
using namespace std;
long long int LS(long long int arr[], long long int n, long long int k) {
  for (long long int i = 0; i < n; i++)
    if (arr[i] == k) return i;
}
int main() {
  long long int a, b;
  cin >> a >> b;
  long long int t = a;
  if (b > a) {
    a = b;
    b = t;
  }
  long long int c = 0;
  while (a != b) {
    if (a % b == 0) {
      cout << c + a / b << endl;
      return 0;
    } else if (b % a == 0) {
      cout << c + b / a << endl;
      return 0;
    } else if (a > b) {
      c += a / b;
      a = a % b;
    } else if (a < b) {
      c += b / a;
      b = b % a;
    }
  }
  cout << c + 1 << endl;
  return 0;
}
