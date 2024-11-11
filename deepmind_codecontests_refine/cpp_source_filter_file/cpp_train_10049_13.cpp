#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << "0";
  } else {
    long long int max_swap = n - 1 / 2;
    if (k >= max_swap) {
      cout << (n * (n - 1) / 2);
    } else {
      long long int two = 2;
      long long int f = n * (n - 1);
      long long int g = n - (k * 2);
      long long int h = g * (g - 1);
      cout << (f - h) / 2;
    }
  }
}
