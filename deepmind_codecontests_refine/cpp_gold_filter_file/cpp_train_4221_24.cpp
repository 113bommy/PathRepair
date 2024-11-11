#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0;
  cin >> n;
  while (n) {
    if (n % 8 == 1) {
      a++;
    }
    n /= 8;
  }
  cout << a;
}
