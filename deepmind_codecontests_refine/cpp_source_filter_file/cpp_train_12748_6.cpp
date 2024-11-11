#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int b = 1;
  int j = 1;
  for (int i = 0; i < n - 1; i++) {
    if (b + j == n) {
      cout << n << " ";
    } else {
      cout << (b + j) % n << " ";
    }
    b += j;
    j++;
  }
}
