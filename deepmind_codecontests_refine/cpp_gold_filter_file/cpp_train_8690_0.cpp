#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int q = n;
  if (n % 2 == 0) {
    for (int i = 1; i <= n / 2; i++) {
      cout << i << " " << q << " ";
      q--;
    }
  } else {
    for (int i = 1; i <= n / 2; i++) {
      cout << i << " " << q << " ";
      q--;
    }
    cout << q;
  }
}
