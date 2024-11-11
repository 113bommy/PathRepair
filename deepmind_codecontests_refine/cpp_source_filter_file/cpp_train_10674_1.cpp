#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0)
    return a;
  else
    return gcd(a % b, b);
}
int main() {
  long long int i, j;
  long long int n;
  cin >> n;
  long long int max = 0;
  long long int min = 0;
  if (n % 7 == 0) {
    max = (n / 7) * 2;
    min = (n / 7) * 2;
  } else {
    long long int x = n % 7;
    if (x > 2) {
      max = (n / 7) * 2 + 2;
      if (x > 5) {
        min = (n / 7) * 2 + (7 - x);
      } else {
        min = (n / 7) * 2;
      }
    } else {
      max = (n / 7) * 2 + x;
      min = (n / 7) * 2;
    }
  }
  cout << max << " " << min << endl;
  return 0;
}
