#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n >> i;
  if (i % 2 == 0) {
    for (long long int j = 1; j <= n; j++) {
      if ((j % 2) == 1) {
        for (long long int k = 0; k < i; k++) {
          cout << "#";
        }
        cout << "\n";
      } else if ((j % 4) == 0) {
        cout << "#";
        for (long long int k = 1; k < i; k++) {
          cout << ".";
        }
        cout << "\n";
      } else {
        for (long long int k = 1; k < i; k++) {
          cout << ".";
        }
        cout << "#"
             << "\n";
      }
    }
  } else {
    for (long long int j = 1; j <= n; j++) {
      if ((j % 2) == 1) {
        for (long long int k = 0; k < i; k++) {
          cout << "#";
        }
        cout << "\n";
      } else if ((j % 4) == 0) {
        cout << "#";
        for (long long int k = 1; k < i; k++) {
          cout << ".";
        }
        cout << "\n";
      } else {
        for (long long int k = 1; k < i; k++) {
          cout << ".";
        }
        cout << "#"
             << "\n";
      }
    }
  }
}
