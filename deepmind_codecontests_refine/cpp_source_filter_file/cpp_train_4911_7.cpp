#include <bits/stdc++.h>
using namespace std;
void pyr(int n);
void pyr(int n) {
  for (long long int i = 0; i <= n; i++) {
    if (i == n && i == 0)
      cout << i;
    else
      cout << i << "s";
  }
  for (long long int j = n - 1; j >= 0; j--) {
    if (j == 0)
      cout << j;
    else
      cout << j << "S";
  }
}
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i <= n; i++) {
    for (long long int j = 0; j < (n - i); j++) {
      cout << "  ";
    }
    pyr(i);
    cout << endl;
  }
  for (long long int k = n - 1; k >= 0; k--) {
    for (long long int j = 0; j < (n - k); j++) {
      cout << "  ";
    }
    pyr(k);
    cout << endl;
  }
  return 0;
}
