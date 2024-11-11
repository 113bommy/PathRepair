#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << "No";
  } else {
    cout << "Yes"
         << "\n";
    cout << 1 << " ";
    cout << n << "\n";
    cout << n - 1 << " ";
    for (i = 0; i < n - 1; i++) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
