#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int i;
  if (n % 2 == 0) {
    cout << n / 2 << "\n";
    for (i = 0; i < n / 2; i++) {
      cout << "2"
           << " ";
    }
  } else if (n % 2 == 1) {
    cout << n / 2 << "\n";
    for (i = 0; i < n / 2 - 1; i++) {
      cout << "2"
           << " ";
    }
    cout << "3";
  }
  return 0;
}
